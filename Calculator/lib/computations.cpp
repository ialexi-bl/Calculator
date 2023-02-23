#include <pch.h>
#include <utility>
#include "computations.h"

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

        static int parseNumber(int &i, int base, System::String ^ str, Token &out)
        {
            out.type = Token::Type::NUMBER;
            out.number = {};

            NumberToken &number = out.number;
            for (; i < str->Length; i++) {
                wchar_t c = str[i];

                switch (c) {
                case '.':
                    if (number.hasPoint) {
                        return 1;
                    }
                    number.hasPoint = true;
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    if (!number.hasPoint) {
                        number.whole += c;
                    } else {
                        number.decimal += c;
                    }
                    break;
                default:
                    goto end_number;
                }
            }

        end_number:
            i--;
            return 0;
        }

        static int parseOperation(int &i, System::String ^ str, Token &out)
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

        int tokenize(System::String ^ str, int base, std::vector<Token> &out)
        {
            if (base < 2) {
                return 1; // Invalid base
            }
            if (base > 10) {
                return 2; // Only bases 2-10 are supported
            }

            out.clear();

            for (int i = 0; i < str->Length; i++) {
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
                    if (parseNumber(i, base, str, token)) {
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
                    token.type = Token::Type::PARENTHESIS;
                    token.parenthesis = '(';
                    break;
                case L')':
                    token.type = Token::Type::PARENTHESIS;
                    token.parenthesis = ')';
                    break;
                default:
                    return 4; // Invalid token
                }
            }

            return 0;
        }
    } // namespace Tokenizer

    namespace Parser
    {
        Node::Node(Type type) : type {type} {};
        Node::Node(Node &&node)
        {
            *this = std::move(node);
        }
        Node &Node::operator=(Node &&node)
        {
            type = node.type;
            getPointer() = node.getPointer();

            node.type = Node::Type::LITERAL;
            node.literal = new Literal::Node {0};
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
                return (void *&)parentheses;
            }
        }

        Node Node::Binary(BinaryOperation::Type type, Node &&left, Node &&right) noexcept
        {
            Node node(Type::BINARY_OPERATION);
            node.binaryOperation = new BinaryOperation::Node {type, std::move(left), std::move(right)};
            return std::move(node);
        }
        Node Node::Unary(UnaryOperation::Type type, Node &&operand) noexcept
        {
            Node node(Type::UNARY_OPERATION);
            node.unaryOperation = new UnaryOperation::Node {type, std::move(operand)};
            return node;
        }
        Node Node::Parentheses(Node &&expression) noexcept
        {
            Node node(Type::PARENTHESES);
            node.parentheses = new Parentheses::Node {std::move(expression)};
            return node;
        }
        Node Node::Literal(long double value) noexcept
        {
            Node node(Type::LITERAL);
            node.literal = new Literal::Node {value};
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

        long double Literal::Node::evaluate() const noexcept
        {
            return value;
        }

        long double Parentheses::Node::evaluate() const noexcept
        {
            return expression.evaluate();
        }

        long double UnaryOperation::Node::evaluate() const noexcept
        {
            long double x = operand.evaluate();
            switch (type) {
            case Type::MINUS:
                return -x;
            }
            return x;
        }

        long double BinaryOperation::Node::evaluate() const noexcept
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

        long double compute(System::String ^ str)
        {
            return parse(str).evaluate();
        }

        static int parseExpression(int &i, const std::vector<Tokenizer::Token> &tokens, int base, Node &result)
        {
            using Tokenizer::Token;

            Node root = Node::Binary(BinaryOperation::Type::PLUS, Node::Empty(), Node::Empty());
            Node *ptr = &root.binaryOperation->right;
            Node *lastValue = nullptr;
            char unaryOperation = 0;

            for (int s = tokens.size(); i < s; i++) {
                const Token &token = tokens[i];

                if (token.type == Token::Type::OPERATION) {
                    if (!lastValue) {
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

                
            }
        }
        int parse(System::String ^ str, int base, Node &result)
        {
            std::vector<Tokenizer::Token> tokens;
            if (Tokenizer::tokenize(str, base, tokens)) {
                return 1; // Tokenization error
            }
            int i = 0;
            if (parseExpression(i, tokens, base, result)) {
                return 2; // Parsing error
            }
            return 0;
        }
    } // namespace Parser
} // namespace Calculator