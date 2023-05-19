#pragma once

#include <vector>
#include <string>
#include <memory>

namespace Calculator
{
    namespace Math
    {
        using value_t = long double;

        namespace Tokens
        {
            struct Token {
                enum class Type {
                    NUMBER = 0,
                    OPERATION = 1,
                    PARENTHESIS_OPEN = 2,
                    PARENTHESIS_CLOSE = 3,
                };

              public:
                Type type;
                size_t start;
                size_t end;
            };

            int tokenize(const std::wstring &str, std::vector<Token> &result);
        } // namespace Tokens

        namespace Parser
        {
            struct Node {
                virtual ~Node();
            };

            struct BinaryOperation : public Node {
                enum class Type {
                    ADDITION = '+',
                    SUBTRACTION = '-',
                    MULTIPLICATION = '*',
                    DIVISION = '/',
                };
                static int getPriority(Type type);

              public:
                Type type = Type::ADDITION;
                std::unique_ptr<Node> left;
                std::unique_ptr<Node> right;

                virtual ~BinaryOperation();
                BinaryOperation(Type type, std::unique_ptr<Node> &&left, std::unique_ptr<Node> &&right);
            };

            struct UnaryOperation : public Node {
                enum class Type {
                    MINUS = '-',
                };

              public:
                Type type;
                std::unique_ptr<Node> operand;

                virtual ~UnaryOperation();
                UnaryOperation(Type, std::unique_ptr<Node> &&);
            };

            struct Literal : public Node {
                value_t value;

                virtual ~Literal();
                Literal(value_t);
            };



            int parse(const std::wstring &str, unsigned int base, std::unique_ptr<Node> &result);
        } // namespace Parser

        int compute(const std::wstring &str, unsigned int base, value_t &result);
    } // namespace Math
} // namespace Calculator
