#include "math-parser.h"

#include <utility>

namespace Calculator
{
    namespace Math
    {
        namespace Tokens
        {
            int tokenize(const std::wstring &str, std::vector<Token> &out)
            {
                out.clear();

                for (size_t i = 0, s = str.size(); i < s; i++) {
                    switch (str[i]) {
                    case L' ':
                        goto next_token;

                    case L'+':
                    case L'-':
                    case L'*':
                    case L'/':
                        out.push_back({Token::Type::OPERATION, i, i + 1});
                        goto next_token;

                    case L'(':
                        out.push_back({Token::Type::PARENTHESIS_OPEN, i, i + 1});
                        goto next_token;

                    case L')':
                        out.push_back({Token::Type::PARENTHESIS_CLOSE, i, i + 1});
                        goto next_token;
                    }

                    size_t j;
                    bool hasNumber = false;
                    for (j = i; j < s; j++) {
                        switch (str[j]) {
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
                        case L',':
                            hasNumber = true;
                            break;
                        default:
                            goto end_number;
                        }
                    }
                end_number:

                    if (hasNumber) {
                        out.push_back({Token::Type::NUMBER, i, j});
                        i = j - 1;
                    } else {
                        return 1; // Invalid character
                    }

                next_token:;
                }

                return 0;
            }
        } // namespace Tokens

        namespace Parser
        {
            Node::~Node()
            {
            }
            BinaryOperation::~BinaryOperation()
            {
            }
            BinaryOperation::BinaryOperation(Type type, std::unique_ptr<Node> &&left, std::unique_ptr<Node> &&right)
                : type {type}, left {std::move(left)}, right {std::move(right)}
            {
            }
            UnaryOperation::~UnaryOperation()
            {
            }
            UnaryOperation::UnaryOperation(Type type, std::unique_ptr<Node> &&operand) : type {type}, operand {std::move(operand)}
            {
            }
            Literal::~Literal()
            {
            }
            Literal::Literal(value_t value) : value {value}
            {
            }
            /*Node::Node() : type {Type::EMPTY}, operands {nullptr}
            {
            }
            Node::Node(size_t operands_count) : type {Type::EMPTY}, operands {new std::unique_ptr<Node>[operands_count]}
            {
            }
            Node::~Node()
            {
                delete[] operands;
            }
            Node Node::BinaryOperation(BinaryOperation::Type type, std::unique_ptr<Node> &&left, std::unique_ptr<Node> &&right)
            {
                Node result(2);
                result.type = Type::BINARY_OPERATION;
                result.operands[0] = std::move(left);
                result.operands[1] = std::move(right);
                return result;
            }
            Node Node::UnaryOperation(UnaryOperation::Type type, std::unique_ptr<Node> &&operand)
            {
                Node result(1);
                result.type = Type::UNARY_OPERATION;
                result.operands[0] = std::move(operand);
            }
            Node Node::Literal(value_t value)
            {
                Node result;
                result.value = value;
                return result;
            }*/

            /*BinaryOperation::BinaryOperation(Type type, std::unique_ptr<Node> &&left, std::unique_ptr<Node> &&right)
                : type {type}, left {std::move(left)}, right {std::move(right)}
            {
            }
            BinaryOperation::BinaryOperation(BinaryOperation &&operation)
                : type {operation.type}, left {std::move(operation.left)}, right {std::move(operation.right)}
            {
            }
            BinaryOperation &BinaryOperation::operator=(BinaryOperation &&operation)
            {
                type = operation.type;
                left = std::move(operation.left);
                right = std::move(operation.right);
                return *this;
            }*/

            int BinaryOperation::getPriority(Type type)
            {
                switch (type) {
                case Type::ADDITION:
                case Type::SUBTRACTION:
                    return 1;
                case Type::MULTIPLICATION:
                case Type::DIVISION:
                    return 2;
                default:
                    return 0;
                }
            }

            static int parseExpression(
                const std::wstring &str,
                const std::vector<Tokens::Token> &tokens,
                unsigned int base,
                size_t &i,
                std::unique_ptr<Node> &result
            )
            {
                using Tokens::Token;

                std::unique_ptr<Node> root = nullptr;
                std::unique_ptr<Node> *ptr = &root;
                int lastPriority = -1;

                bool isValidLastValue = false;
                std::unique_ptr<Node> lastValueRoot = nullptr;
                std::unique_ptr<Node> *lastValue = &lastValueRoot;

                for (size_t s = tokens.size(); i < s; i++) {
                    const Token &token = tokens[i];

                    if (token.type == Token::Type::NUMBER) {
                        bool hadPoint = false;
                        long double whole = 0, decimal = 0;

                        for (size_t j = token.start; j < token.end; j++) {
                            if (str[j] == L',') {
                                hadPoint = true;
                                continue;
                            }
                            if (!hadPoint) {
                                whole *= base;
                                whole += str[j] - L'0';
                            } else {
                                decimal *= base;
                                decimal += str[j] - L'0';
                            }
                        }
                        while (decimal >= 1) {
                            decimal /= base;
                        }

                        *lastValue = std::make_unique<Literal>(whole + decimal);
                        isValidLastValue = true;
                        continue;
                    }

                    if (token.type == Token::Type::PARENTHESIS_OPEN) {
                        *lastValue = std::make_unique<Node>();

                        ++i;
                        parseExpression(str, tokens, base, i, *lastValue);

                        isValidLastValue = true;
                        continue;
                    }

                    if (token.type == Token::Type::PARENTHESIS_CLOSE) {
                        break;
                    }

                    if (token.type == Token::Type::OPERATION) {
                        if (token.end - token.start != 1) {
                            return 1;
                        }

                        if (!isValidLastValue) {
                            if (str[token.start] != '-') {
                                return 1;
                            }

                            UnaryOperation *operation = new UnaryOperation {UnaryOperation::Type::MINUS, nullptr};
                            *lastValue = std::unique_ptr<Node>(operation);
                            lastValue = &operation->operand;
                            continue;
                        }

                        BinaryOperation::Type type;
                        switch (str[token.start]) {
                        case L'-':
                            type = BinaryOperation::Type::SUBTRACTION;
                            break;
                        case L'+':
                            type = BinaryOperation::Type::ADDITION;
                            break;
                        case L'*':
                            type = BinaryOperation::Type::MULTIPLICATION;
                            break;
                        case L'/':
                            type = BinaryOperation::Type::DIVISION;
                            break;
                        default:
                            return 1;
                        }

                        int p1 = lastPriority;
                        int p2 = BinaryOperation::getPriority(type);

                        if (p2 > p1) {
                            BinaryOperation *operation = new BinaryOperation {type, std::move(lastValueRoot), nullptr};
                            *ptr = std::unique_ptr<Node>(operation);
                            ptr = &operation->right;
                        } else {
                            *ptr = std::move(lastValueRoot);

                            BinaryOperation *operation = new BinaryOperation {type, std::move(root), nullptr};
                            root = std::unique_ptr<Node>(operation);
                            ptr = &operation->right;
                        }

                        lastValueRoot = nullptr;
                        lastValue = &lastValueRoot;
                        lastPriority = p2;

                        continue;
                    }
                }

                if (lastValue) {
                    *ptr = std::move(lastValueRoot);
                    lastValueRoot = nullptr;
                    lastValue = &lastValueRoot;
                }

                result = std::move(root);
                return 0;
            }

            int parse(const std::wstring &str, unsigned int base, std::unique_ptr<Node> &result)
            {
                using Tokens::Token;

                std::vector<Token> tokens;
                if (Tokens::tokenize(str, tokens)) {
                    return 1; // Tokenization error
                }
                size_t i = 0;
                if (parseExpression(str, tokens, base, i, result)) {
                    return 2; // Parsing error
                }
                return 0;
            }
        } // namespace Parser

        static long double evaluate(const Parser::Node &node)
        {
            using namespace Parser;

            if (auto *literal = dynamic_cast<const Literal *>(&node)) {
                return literal->value;
            }
            if (auto *unaryOperation = dynamic_cast<const UnaryOperation *>(&node)) {
                long double operandValue = evaluate(*unaryOperation->operand);

                switch (unaryOperation->type) {
                case UnaryOperation::Type::MINUS:
                    return -operandValue;
                }
                return operandValue;
            }
            if (auto *binaryOperation = dynamic_cast<const BinaryOperation *>(&node)) {
                long double left = evaluate(*binaryOperation->left);
                long double right = evaluate(*binaryOperation->right);

                if (binaryOperation->left == nullptr) {
                    return right;
                }
                if (binaryOperation->right == nullptr) {
                    return left;
                }

                switch (binaryOperation->type) {
                case BinaryOperation::Type::ADDITION:
                    return left + right;
                case BinaryOperation::Type::SUBTRACTION:
                    return left - right;
                case BinaryOperation::Type::MULTIPLICATION:
                    return left * right;
                case BinaryOperation::Type::DIVISION:
                    return left / right;
                }
                return left * right;
            }

            return 0;
        }

        int compute(const std::wstring &str, unsigned int base, value_t &result)
        {
            std::unique_ptr<Parser::Node> node = nullptr;
            if (Parser::parse(str, base, node)) {

                return 1;
            }

            result = evaluate(*node);
            return 0;
        }
    } // namespace Math
} // namespace Calculator
