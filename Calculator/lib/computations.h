#pragma once

#include <vector>
#include <string>

namespace Calculator
{
    namespace Tokenizer
    {
        class NumberToken
        {
          public:
            std::vector<char> whole;
            std::vector<char> decimal;
        };

        class Token
        {
          public:
            enum class Type {
                OPERATION = 0,
                NUMBER = 1,
                OPEN_PARENTHESIS = 2,
                CLOSE_PARENTHESIS = 3,
            };

            Type type;
            union {
                char operation;
                NumberToken* number;
            };

            Token();
            ~Token();

            static Token Number(std::vector<char> whole, std::vector<char> decimal);
        };

        int tokenize(const std::wstring &str, std::vector<Token> &result);
    } // namespace Tokenizer

    namespace Parser
    {
        namespace BinaryOperation
        {
            enum class Type;
            class Node;

            static int getPriority(Type);
        }; // namespace BinaryOperation
        namespace UnaryOperation
        {
            enum class Type;
            class Node;
        }; // namespace UnaryOperation
        namespace Literal
        {
            class Node;
        };
        namespace Parentheses
        {
            class Node;
        };

        class Node
        {
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
            Node();
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

            friend int parseExpression(size_t &i, const std::vector<Tokenizer::Token> &tokens, int base, Node &result);
        };

        enum class BinaryOperation::Type {
            PLUS = 0,
            MINUS = 1,
            MULTIPLY = 2,
            DIVIDE = 3,
        };
        class BinaryOperation::Node
        {
          public:
            Type type;
            Parser::Node left;
            Parser::Node right;

            long double evaluate() const noexcept;
        };

        enum class UnaryOperation::Type {
            MINUS = 0,
        };
        class UnaryOperation::Node
        {
          public:
            Type type;
            Parser::Node operand;

            long double evaluate() const noexcept;
        };

        class Parentheses::Node
        {
          public:
            Parser::Node expression;

            long double evaluate() const noexcept;
        };

        class Literal::Node
        {
          public:
            long double value;

            long double evaluate() const noexcept;
        };

        int parse(const std::wstring &str, int base, Node &result);
    } // namespace Parser

    int compute(const std::wstring &str, int base, long double &out);
} // namespace Calculator
