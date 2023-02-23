#pragma once

#include "computations.h"
#include <utility>

namespace Calculator
{
    namespace Tokenizer
    {
        Token::Token()
        {
        }
        Token::~Token()
        {
        }

        Token Token::Number(std::vector<char> whole, std::vector<char> decimal)
        {
            Token result;
            result.type = Type::NUMBER;
            result.number = new NumberToken {whole, decimal};
            return result;
        }

        static int parseNumber(size_t &i, const std::wstring &str, Token &out)
        {
            bool hasPoint = false;
            std::vector<char> whole, decimal;
            for (size_t s = str.size(); i < s; i++) {
                wchar_t c = str[i];

                switch (c) {
                case L'.':
                    if (hasPoint) {
                        return 1;
                    }
                    hasPoint = true;
                    break;
                case L'0':
                case L'1':
                case L'2':
                case L'3':
                case L'4':
                case L'5':
                case L'6':
                case L'7':
                case L'8':
                case L'9':
                    if (!hasPoint) {
                        whole.push_back(static_cast<char>(c));
                    } else {
                        decimal.push_back(static_cast<char>(c));
                    }
                    break;
                default:
                    goto end_number;
                }
            }

        end_number:
            i--;
            out = Token::Number(whole, decimal);
            return 0;
        }

        static int parseOperation(size_t &i, const std::wstring &str, Token &out)
        {
            out.type = Token::Type::OPERATION;
            switch (str[i]) {
            case L'+':
                out.operation = '+';
                break;
            case L'-':
                out.operation = '-';
                break;
            case L'×':
                out.operation = '*';
                break;
            case L'÷':
                out.operation = '/';
                break;
            default:
                return 1; // Invalid operation;
            }

            return 0;
        }

        int tokenize(const std::wstring &str, std::vector<Token> &out)
        {
            out.clear();

            for (size_t i = 0, s = str.size(); i < s; i++) {
                wchar_t c = str[i];
                Token token;

                switch (c) {
                case L'0':
                case L'1':
                case L'2':
                case L'3':
                case L'4':
                case L'5':
                case L'6':
                case L'7':
                case L'8':
                case L'9':
                case L'.':
                    if (parseNumber(i, str, token)) {
                        return 3; // Parse error
                    }
                    break;

                case L'+':
                case L'-':
                case L'×':
                case L'÷':
                    if (parseOperation(i, str, token)) {
                        return 3; // Parse error
                    }
                    break;
                case L'(':
                    token.type = Token::Type::OPEN_PARENTHESIS;
                    break;
                case L')':
                    token.type = Token::Type::CLOSE_PARENTHESIS;
                    break;
                default:
                    return 4; // Invalid token
                }

                out.push_back(token);
            }

            return 0;
        }
    } // namespace Tokenizer

    namespace Parser
    {
        Node::Node(Type type) : type {type} {};
        Node::Node() : type {Type::LITERAL}, literal {nullptr} {};
        Node::Node(Node &&node)
        {
            *this = std::move(node);
        }
        Node &Node::operator=(Node &&node)
        {
            type = node.type;
            getPointer() = node.getPointer();

            node.type = Node::Type::LITERAL;
            node.literal = new Literal::Nodel {0};
            return *this;
        }
        Node::~Node()
        {
            delete getPointer();
        }
        void *&Node::getPointer()
        {
            switch (type) {
            case Type::BINARY_OPERATION:
                return (void *&)binaryOperation;
            case Type::UNARY_OPERATION:
                return (void *&)unaryOperation;
            case Type::LITERAL:
                return (void *&)literal;
            case Type::PARENTHESES:
            default:
                return (void *&)parentheses;
            }
        }

        Node Node::Binary(BinaryOperation::Type type, Node &&left, Node &&right) noexcept
        {
            Node node(Type::BINARY_OPERATION);
            node.binaryOperation = new BinaryOperation::Nodeb {type, std::move(left), std::move(right)};
            return node;
        }
        Node Node::Unary(UnaryOperation::Type type, Node &&operand) noexcept
        {
            Node node(Type::UNARY_OPERATION);
            node.unaryOperation = new UnaryOperation::Nodeu {type, std::move(operand)};
            return node;
        }
        Node Node::Parentheses(Node &&expression) noexcept
        {
            Node node(Type::PARENTHESES);
            node.parentheses = new Parentheses::Nodep {std::move(expression)};
            return node;
        }
        Node Node::Literal(long double value) noexcept
        {
            Node node(Type::LITERAL);
            node.literal = new Literal::Nodel {value};
            return node;
        }
        Node Node::Empty() noexcept
        {
            return Literal(0);
        }

        long double Node::evaluate() const noexcept
        {
            switch (type) {
            case Type::LITERAL:
                return literal->evaluate();
            case Type::UNARY_OPERATION:
                return unaryOperation->evaluate();
            case Type::BINARY_OPERATION:
                return binaryOperation->evaluate();
            case Type::PARENTHESES:
                return parentheses->evaluate();
            }
            return 0;
        }

        long double Literal::Nodel::evaluate() const noexcept
        {
            return value;
        }

        long double Parentheses::Nodep::evaluate() const noexcept
        {
            return expression.evaluate();
        }

        long double UnaryOperation::Nodeu::evaluate() const noexcept
        {
            long double x = operand.evaluate();
            switch (type) {
            case Type::MINUS:
                return -x;
            }
            return x;
        }

        int BinaryOperation::getPriority(Type type)
        {
            switch (type) {
            case Type::PLUS:
            case Type::MINUS:
                return 0;
            case Type::MULTIPLY:
            case Type::DIVIDE:
                return 1;
            default:
                return -1;
            }
        }

        long double BinaryOperation::Nodeb::evaluate() const noexcept
        {
            long double a = left.evaluate(), b = right.evaluate();
            switch (type) {
            case Type::PLUS:
                return a + b;
            case Type::MINUS:
                return a - b;
            case Type::MULTIPLY:
                return a * b;
            case Type::DIVIDE:
                return a / b;
            }
            return 0;
        }

        int parseExpression(size_t &i, const std::vector<Tokenizer::Token> &tokens, int base, Node &result)
        {
            using Tokenizer::Token;

            Node root = Node::Binary(BinaryOperation::Type::PLUS, Node::Empty(), Node::Empty());
            Node *ptr = &root.binaryOperation->right;
            Node *lastValue = nullptr;
            char unaryOperation = 0;

            for (size_t s = tokens.size(); i < s; i++) {
                const Token &token = tokens[i];

                if (token.type == Token::Type::OPERATION) {
                    if (!lastValue) {
                        if (token.operation != '-') {
                            return 1;
                        }
                        unaryOperation = token.operation;
                        continue;
                    }

                    BinaryOperation::Type type;
                    switch (token.operation) {
                    case '-':
                        type = BinaryOperation::Type::MINUS;
                        break;
                    case '+':
                        type = BinaryOperation::Type::PLUS;
                        break;
                    case '*':
                        type = BinaryOperation::Type::MULTIPLY;
                        break;
                    case '/':
                        type = BinaryOperation::Type::DIVIDE;
                        break;
                    default:
                        return 1;
                    }

                    int p1 = BinaryOperation::getPriority(ptr->binaryOperation->type);
                    int p2 = BinaryOperation::getPriority(type);
                    if (p2 >= p1) {
                        *ptr = Node::Binary(
                            type,
                            unaryOperation ? Node::Unary(UnaryOperation::Type::MINUS, std::move(*lastValue))
                                           : std::move(*lastValue),
                            Node::Empty()
                        );
                        ptr = &ptr->binaryOperation->right;

                        delete lastValue;
                        lastValue = nullptr;
                    } else {
                        *ptr = unaryOperation ? Node::Unary(UnaryOperation::Type::MINUS, std::move(*lastValue))
                                              : std::move(*lastValue);

                        root.binaryOperation->right = Node::Binary(type, std::move(root.binaryOperation->right), Node::Empty());
                        ptr = &root.binaryOperation->right;

                        delete lastValue;
                        lastValue = nullptr;
                    }

                    continue;
                }

                if (token.type == Token::Type::NUMBER) {
                    long double whole = 0, decimal = 0;
                    for (char digit : token.number->whole) {
                        whole *= base;
                        whole += digit - '0';
                    }
                    for (char digit : token.number->decimal) {
                        decimal *= base;
                        decimal += digit - '0';
                    }
                    while (decimal >= 1) {
                        decimal /= base;
                    }

                    lastValue = new Node;
                    *lastValue = Node::Literal(whole + decimal);
                    continue;
                }

                if (token.type == Token::Type::OPEN_PARENTHESIS) {
                    lastValue = new Node(Node::Type::PARENTHESES);
                    parseExpression(i, tokens, base, lastValue->parentheses->expression);
                    continue;
                }

                if (token.type == Token::Type::CLOSE_PARENTHESIS) {
                    break;
                }
            }

            if (lastValue) {
                *ptr = unaryOperation ? Node::Unary(UnaryOperation::Type::MINUS, std::move(*lastValue)) : std::move(*lastValue);
                delete lastValue;
                lastValue = nullptr;
            }

            result = std::move(root.binaryOperation->right);
            return 0;
        }

        int parse(const std::wstring &str, int base, Node &result)
        {
            std::vector<Tokenizer::Token> tokens;
            if (Tokenizer::tokenize(str, tokens)) {
                return 1; // Tokenization error
            }
            size_t i = 0;
            if (parseExpression(i, tokens, base, result)) {
                return 2; // Parsing error
            }
            return 0;
        }
    } // namespace Parser

    int compute(const std::wstring &str, int base, long double &out)
    {
        auto result = Parser::Node::Empty();
        if (parse(str, base, result)) {
            return 1;
        }

        out = result.evaluate();
        return 0;
    }
} // namespace Calculator