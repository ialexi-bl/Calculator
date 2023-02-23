#pragma once

#include <memory>
#include <vector>
#include <string>

namespace Calculator
{
    namespace Tokenizer
    {
        struct NumberToken {
            bool hasPoint = false;
            std::string whole = "";
            std::string decimal = "";
        };

        struct Token {
            enum class Type {
                OPERATION = 0,
                NUMBER = 1,
                PARENTHESIS = 2,
            };

            Type type;
            union {
                char operation;
                char parenthesis;
                NumberToken number;
            };

            Token();
            ~Token();
        };

        int tokenize(System::String ^ str, int base, std::vector<Token> &result);
    } // namespace Tokenizer
    namespace Parser
    {
        struct BinaryOperation {
            enum class Type;
            struct Node;

            static int getPriority(Type);
        };
        struct UnaryOperation {
            enum class Type;
            struct Node;
        };
        struct Literal {
            struct Node;
        };
        struct Parentheses {
            struct Node;
        };

        struct Node {
            enum class Type {
                BINARY_OPERATION = 0,
                UNARY_OPERATION = 1,
                LITERAL = 2,
                PARENTHESES = 3,
            };

          public:
            Type type;

          private:
            union {
                BinaryOperation::Node *binaryOperation;
                UnaryOperation::Node *unaryOperation;
                Literal::Node *literal;
                Parentheses::Node *parentheses;
            };

          private:
            Node(Type);
            void *&getPointer();

          public:
            ~Node();
            Node(Node &&);
            Node &operator=(Node &&);

            static Node Empty() noexcept;
            static Node Binary(BinaryOperation::Type type, Node &&left, Node &&right) noexcept;
            static Node Unary(UnaryOperation::Type type, Node &&operand) noexcept;
            static Node Parentheses(Node &&expression) noexcept;
            static Node Literal(long double value) noexcept;

            long double evaluate() const noexcept;

            friend int parseExpression(int &i, const std::vector<Tokenizer::Token> &tokens, int base, Node &result);
        };

        enum class BinaryOperation::Type {
            PLUS = 0,
            MINUS = 1,
            MULTIPLY = 2,
            DIVIDE = 3,
        };
        struct BinaryOperation::Node {
            Type type;
            Parser::Node left, right;

            long double evaluate() const noexcept;
        };

        enum class UnaryOperation::Type {
            MINUS = 0,
        };
        struct UnaryOperation::Node {
            Type type;
            Parser::Node operand;

            long double evaluate() const noexcept;
        };

        struct Parentheses::Node {
            Parser::Node expression;

            long double evaluate() const noexcept;
        };

        struct Literal::Node {
            long double value;

            long double evaluate() const noexcept;
        };

        int parse(System::String ^ str, int base, Node &result);
    } // namespace Parser

    long double compute(System::String ^);
} // namespace Calculator
