#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "../AST/AST.h"
#include "../../tokenizer/data/Token.h"

class Parser {

public:
    std::unique_ptr<Expr> root = nullptr;
    Parser(std::vector<Token> tokens);
    std::unique_ptr<Expr> parseToken();

private:
    int pos_ = 0;

    std::vector<Token> tokens_;

    Token consume();
    Token peek();
    bool match(char c);
    bool isAtEnd();

    std::unique_ptr<Expr> parseExpression();
    std::unique_ptr<Expr> parseTerm();
    std::unique_ptr<Expr> parseFactor();
};