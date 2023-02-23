#pragma once

#include <memory>

namespace Calculator
{
    enum class NodeType {
        BINARY_OPERATION = 0,
        UNARY_OPERATION = 1,
        LITERAL = 2,
        PARENTHESES = 3,
    };
    enum class BinaryOperation {
        PLUS = 0,
        MINUS = 1,
        MULTIPLY = 2,
        DIVIDE = 3,
    };
    enum class UnaryOperation {
        MINUS = 0,
    };

    struct BinaryOperationInfo;
    struct UnaryOperationInfo;
    struct LiteralInfo;
    struct ParenthesesInfo;

    struct Node {
      public:
        const NodeType type;

      private:
        union {
            BinaryOperationInfo *binaryOperation;
            UnaryOperationInfo *unaryOperation;
            LiteralInfo *literal;
            ParenthesesInfo *parentheses;
        };

      private:
        Node(NodeType type);

      public:
        ~Node();

        static Node Binary(BinaryOperation type, Node left, Node right) noexcept;
        static Node Unary(UnaryOperation type, Node operand) noexcept;
        static Node Parentheses(Node expression) noexcept;
        static Node Literal(long double value) noexcept;

        long double evaluate() const noexcept;
    };

    struct ParenthesesInfo {
        Node expression;

        long double evaluate() const noexcept;
    };

    struct BinaryOperationInfo {
        BinaryOperation type;
        Node left, right;

        long double evaluate() const noexcept;
    };

    struct UnaryOperationInfo {
        UnaryOperation type;
        Node operand;

        long double evaluate() const noexcept;
    };

    struct LiteralInfo {
        long double value;

        long double evaluate() const noexcept;
    };

    Node parse(System::String ^);
    long double compute(System::String ^);
    long double compute(const Node &);
} // namespace Calculator
