#include <pch.h>
#include "computations.h"

namespace Calculator
{
    Node Node::Binary(BinaryOperation type, Node left, Node right) noexcept
    {
        return {
            .type {NodeType::BINARY_OPERATION},
            .binaryOperation {
                .type {type},
                .left {left},
                .right {right},
            },
        };
    }
    Node Node::Unary(UnaryOperation type, Node operand) noexcept
    {
        return {
            .type {NodeType::UNARY_OPERATION},
            .unaryOperation {
                .type {type},
                .operand {operand},
            },
        };
    }
    Node Node::Parentheses(Node expression) noexcept
    {
        return {
            .type {NodeType::PARENTHESES},
            .parentheses {expression},
        };
    }
    Node Node::Literal(long double value) noexcept
    {
        return {
            .type {NodeType::LITERAL},
            .literal {value},
        };
    }

    long double Node::evaluate() const noexcept
    {
        switch (type) {
        case NodeType::LITERAL:
            return literal.evaluate();
        case NodeType::UNARY_OPERATION:
            return unaryOperation.evaluate();
        case NodeType::BINARY_OPERATION:
            return binaryOperation.evaluate();
        case NodeType::PARENTHESES:
            return parentheses.evaluate();
        }
        return 0;
    }

    long double LiteralInfo::evaluate() const noexcept
    {
        return value;
    }

    long double UnaryOperationInfo::evaluate() const noexcept
    {
        long double x = operand.evaluate();
        switch (type) {
        case UnaryOperation::MINUS:
            return -x;
        }
        return x;
    }

    long double BinaryOperationInfo::evaluate() const noexcept
    {
        long double a = left.evaluate(), b = right.evaluate();
        switch (type) {
        case BinaryOperation::PLUS:
            return a + b;
        case BinaryOperation::MINUS:
            return a - b;
        case BinaryOperation::MULTIPLY:
            return a * b;
        case BinaryOperation::DIVIDE:
            return a / b;
        }
        return 0;
    }

    long double compute(System::String ^ str)
    {

        return parse(str).evaluate();
    }

    Node parse(System::String ^ str)
    {
        auto enumerator = str->GetEnumerator();
        while (enumerator->MoveNext()) {
            wchar_t c = enumerator->Current;
        }
    }
} // namespace Calculator