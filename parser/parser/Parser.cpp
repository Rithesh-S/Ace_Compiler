#include "Parser.h"

Parser::Parser(std::vector<Token> tokens) : tokens_(move(tokens)) {};

void Parser::parseToken() {
    root = parseExpression();
}

std::unique_ptr<Expr> Parser::parseExpression() {
    auto left = parseTerm();
    while (!isAtEnd() && (match('+') || match('-'))) {
        char opr = consume().token[0];
        auto right = parseTerm();
        left = std::make_unique<Binary>(std::move(left), opr, std::move(right));
    }
    return left;
}

std::unique_ptr<Expr> Parser::parseTerm() {
    auto left = parseFactor();
    while (!isAtEnd() && (match('*') || match('/'))) {
        char opr = consume().token[0];
        auto right = parseFactor();
        left = std::make_unique<Binary>(std::move(left), opr, std::move(right));
    }
    return left;
}

std::unique_ptr<Expr> Parser::parseFactor() {
    Token left = consume();
    if (left.type == TokenType::PARENTHESES && left.token == "(") {
        auto right = parseExpression();
        if (isAtEnd() || peek().token != ")") std::cerr << "\033[31mError: Expected ')'\033[0m" << std::endl;
        else consume();
        return right;
    }

    double value = 0.0;
    try {
        value = std::stod(left.token);
    } catch (...) {
        std::cerr << "\033[31mError: Expected number, found " << left.token << "\033[0m" << std::endl;
    }
    return std::make_unique<Literal>(value);
}

Token Parser::consume() {
    Token token = peek();
    if (!isAtEnd()) pos_++;
    return token;
}

bool Parser::match(char c) {
    Token curr = peek();
    return curr.token[0] == c;
}

Token Parser::peek() {
    return tokens_[pos_];
}

bool Parser::isAtEnd() {
    return pos_ >= tokens_.size();
}