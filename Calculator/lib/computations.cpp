#include <pch.h>
#include <utility>
#include "computations.h"

namespace Calculator
{
    Node::Node(NodeType type) : type {type} {};
    Node::~Node()
    {
        switch (type) {
        case NodeType::BINARY_OPERATION:
            delete binaryOperation;
            break;
        case NodeType::UNARY_OPERATION:
            delete unaryOperation;
            break;
        case NodeType::LITERAL:
            delete literal;
            break;
        case NodeType::PARENTHESES:
            delete parentheses;
            break;
        }
    }

    Node Node::Binary(BinaryOperation type, Node left, Node right) noexcept
    {
        Node node(NodeType::BINARY_OPERATION);
        node.binaryOperation = new BinaryOperationInfo {type, left, right};
        return std::move(node);
    }
    Node Node::Unary(UnaryOperation type, Node operand) noexcept
    {
        Node node(NodeType::UNARY_OPERATION);
        node.unaryOperation = new UnaryOperationInfo {type, operand};
        return node;
    }
    Node Node::Parentheses(Node expression) noexcept
    {
        Node node(NodeType::PARENTHESES);
        node.parentheses = new ParenthesesInfo {expression};
        return node;
    }
    Node Node::Literal(long double value) noexcept
    {
        Node node(NodeType::LITERAL);
        node.literal = new LiteralInfo {value};
        return node;
    }

    long double Node::evaluate() const noexcept
    {
        switch (type) {
        case NodeType::LITERAL:
            return literal->evaluate();
        case NodeType::UNARY_OPERATION:
            return unaryOperation->evaluate();
        case NodeType::BINARY_OPERATION:
            return binaryOperation->evaluate();
        case NodeType::PARENTHESES:
            return parentheses->evaluate();
        }
        return 0;
    }

    long double LiteralInfo::evaluate() const noexcept
    {
        return value;
    }

    long double ParenthesesInfo::evaluate() const noexcept
    {
        return expression.evaluate();
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
        return Node::Literal(1);
    }
} // namespace Calculator