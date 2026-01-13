#include "Printer.h"

std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::NUMBER:      return "NUMBER";
        case TokenType::PLUS:        return "PLUS";
        case TokenType::MINUS:       return "MINUS";
        case TokenType::ASTERISK:    return "ASTERISK";
        case TokenType::SLASH:       return "SLASH";
        case TokenType::EQUAL:       return "EQUAL";
        case TokenType::PARENTHESES: return "PARENTHESES";
        case TokenType::END_OF_FILE: return "END_OF_FILE";
        default:                     return "UNKNOWN";
    }
}

void tokenTypeToString(std::vector<Token> tokens) {
    std::cout << "Token Type to String:" << std::endl;
    for (auto i: tokens) {
        std::cout << tokenTypeToString(i.type) << " " << i.token << std::endl;
    }
}

void printTree(const Expr* node, int depth) {
    if (!node) return;

    if (const Binary* bin = dynamic_cast<const Binary*>(node)) {
        printTree(bin->right.get(), depth + 1);

        std::cout << std::string(depth * 4, ' ') << bin->opr << std::endl;

        printTree(bin->left.get(), depth + 1);
    } else if (const Literal* lit = dynamic_cast<const Literal*>(node)) {
        std::cout << std::string(depth * 4, ' ') << lit->val << std::endl;
    }
}