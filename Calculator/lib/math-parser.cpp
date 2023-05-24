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
                    bool has_number = false;
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
                            has_number = true;
                            break;
                        default:
                            goto end_number;
                        }
                    }
                end_number:;

                    if (has_number) {
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

            static int parseBinaryOperation(
                BinaryOperation::Type type,
                int &last_priority,
                std::unique_ptr<Node> &root,
                std::unique_ptr<Node> *&ptr,
                std::unique_ptr<Node> &&last_value_root
            )
            {
                int p1 = last_priority;
                int p2 = BinaryOperation::getPriority(type);

                if (p2 > p1) {
                    BinaryOperation *operation = new BinaryOperation {type, std::move(last_value_root), nullptr};
                    *ptr = std::unique_ptr<Node>(operation);
                    ptr = &operation->right;
                } else {
                    *ptr = std::move(last_value_root);

                    BinaryOperation *operation = new BinaryOperation {type, std::move(root), nullptr};
                    root = std::unique_ptr<Node>(operation);
                    ptr = &operation->right;
                }

                return p2;
            }

            static int parseExpression(
                const std::wstring &str,
                const std::vector<Tokens::Token> &tokens,
                unsigned int base,
                size_t &i,
                std::unique_ptr<Node> &result,
                bool is_nested = false
            )
            {
                using Tokens::Token;

                std::unique_ptr<Node> root = nullptr;
                std::unique_ptr<Node> *ptr = &root;
                int last_priority = -1;

                bool is_valid_last_value = false;
                std::unique_ptr<Node> last_value_root = nullptr;
                std::unique_ptr<Node> *last_value = &last_value_root;

                for (size_t s = tokens.size(); i < s; i++) {
                    const Token &token = tokens[i];

                    if (token.type == Token::Type::NUMBER) {
                        // Example string when this branch is possible: "5)2"
                        if (is_valid_last_value) {
                            last_priority = parseBinaryOperation(
                                BinaryOperation::Type::MULTIPLICATION,
                                last_priority,
                                root,
                                ptr,
                                std::move(last_value_root)
                            );

                            last_value_root = nullptr;
                            last_value = &last_value_root;
                            is_valid_last_value = false;
                        }

                        bool had_point = false;
                        short whole_length = 0, decimal_length = 0;
                        long double whole = 0, decimal = 0;

                        for (size_t j = token.start; j < token.end; j++) {
                            if (str[j] == L',') {
                                if (had_point) {
                                    return 11; // Unexpected point
                                }
                                had_point = true;
                                continue;
                            }
                            if (!had_point) {
                                whole *= base;
                                whole += str[j] - L'0';
                                ++whole_length;
                            } else {
                                decimal *= base;
                                decimal += str[j] - L'0';
                                ++decimal_length;
                            }
                        }
                        if (whole_length > 9 || decimal_length > 9) {
                            return 10; // Overflow
                        }
                        while (decimal >= 1) {
                            decimal /= base;
                        }

                        *last_value = std::make_unique<Literal>(whole + decimal);
                        is_valid_last_value = true;
                        continue;
                    }

                    if (token.type == Token::Type::PARENTHESIS_OPEN) {
                        // Example string when this branch is possible: "5)2"
                        if (is_valid_last_value) {
                            last_priority = parseBinaryOperation(
                                BinaryOperation::Type::MULTIPLICATION,
                                last_priority,
                                root,
                                ptr,
                                std::move(last_value_root)
                            );

                            last_value_root = nullptr;
                            last_value = &last_value_root;
                            is_valid_last_value = false;
                        }

                        *last_value = std::make_unique<Node>();

                        ++i;
                        parseExpression(str, tokens, base, i, *last_value, true);

                        is_valid_last_value = true;
                        continue;
                    }

                    if (token.type == Token::Type::PARENTHESIS_CLOSE) {
                        if (is_nested) {
                            break;
                        } else {
                            *ptr = std::move(last_value_root);
                            last_value_root = std::move(root);
                            last_value = &last_value_root;
                            is_valid_last_value = true;
                            ptr = &root;
                        }
                    }

                    if (token.type == Token::Type::OPERATION) {
                        if (token.end - token.start != 1) {
                            return 1;
                        }

                        if (!is_valid_last_value) {
                            if (str[token.start] != '-') {
                                return 1;
                            }

                            UnaryOperation *operation = new UnaryOperation {UnaryOperation::Type::MINUS, nullptr};
                            *last_value = std::unique_ptr<Node>(operation);
                            last_value = &operation->operand;
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

                        last_priority = parseBinaryOperation(type, last_priority, root, ptr, std::move(last_value_root));

                        last_value_root = nullptr;
                        last_value = &last_value_root;
                        is_valid_last_value = false;
                        continue;
                    }
                }

                if (last_value) {
                    *ptr = std::move(last_value_root);
                    last_value_root = nullptr;
                    last_value = &last_value_root;
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

        static int evaluate(const Parser::Node &node, long double &result)
        {
            using namespace Parser;

            if (auto *literal = dynamic_cast<const Literal *>(&node)) {
                result = literal->value;
                return 0;
            }
            if (auto *unary_operation = dynamic_cast<const UnaryOperation *>(&node)) {
                long double operand_value;
                if (int error = evaluate(*unary_operation->operand, operand_value)) {
                    return error;
                }

                switch (unary_operation->type) {
                case UnaryOperation::Type::MINUS:
                    result = -operand_value;
                    return 0;
                }
                result = operand_value;
                return 0;
            }
            if (auto *binary_operation = dynamic_cast<const BinaryOperation *>(&node)) {
                if (binary_operation->left == nullptr) {
                    return evaluate(*binary_operation->right, result);
                }
                if (binary_operation->right == nullptr) {
                    return evaluate(*binary_operation->left, result);
                }

                long double left, right;
                if (int error = evaluate(*binary_operation->left, left)) {
                    return error;
                }
                if (int error = evaluate(*binary_operation->right, right))
                {
                    return error;
                }

                switch (binary_operation->type) {
                case BinaryOperation::Type::ADDITION:
                    result = left + right;
                    return 0;
                case BinaryOperation::Type::SUBTRACTION:
                    result = left - right;
                    return 0;
                case BinaryOperation::Type::MULTIPLICATION:
                    result = left * right;
                    return 0;
                case BinaryOperation::Type::DIVISION:
                    result = left / right;
                    return 0;
                }
                result = left * right;
                return 0;
            }

            result = 0;
            return 0;
        }

        int compute(const std::wstring &str, unsigned int base, value_t &result)
        {
            std::unique_ptr<Parser::Node> node = nullptr;
            if (int error = Parser::parse(str, base, node)) {
                return error;
            }

            if (int error = evaluate(*node, result)) {
                return error;
            }
            return 0;
        }
    } // namespace Math
} // namespace Calculator
