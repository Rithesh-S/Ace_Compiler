#include "Interpreter.h"

Interpreter::Interpreter(std::unique_ptr<Expr> root) : root_(std::move(root)) {};

double Interpreter::evaluate() {
    return traverseTree(std::move(root_));
}

double Interpreter::traverseTree(std::unique_ptr<Expr> root) {
    if(!root) return 0.0;

    if(Literal* literal = dynamic_cast<Literal*>(root.get())) {
        return literal -> val;
    }

    if(Binary* binary = dynamic_cast<Binary*>(root.get())) {
        if(binary -> opr == '+') return traverseTree(std::move(binary->left)) + traverseTree(std::move(binary->right));
        if(binary -> opr == '-') return traverseTree(std::move(binary->left)) - traverseTree(std::move(binary->right));
        if(binary -> opr == '*') return traverseTree(std::move(binary->left)) * traverseTree(std::move(binary->right));
        if(binary -> opr == '/') { 
            double leftVal = traverseTree(std::move(binary->left));
            double rightVal = traverseTree(std::move(binary->right));
            if(rightVal == 0.0) {
                std::cerr << "\033[31mError: Cannot divide by Zero...\033[0m" << std::endl;
                return 1;
            }
            return leftVal / rightVal;
        }
    }

    return 0.0;
}