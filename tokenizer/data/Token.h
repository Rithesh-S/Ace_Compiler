#pragma once

#include <string>
#include "TokenType.h"

struct Token {
    TokenType type;
    std::string token;

    Token(TokenType type, std::string token) : type(type), token(token) {};
    Token(TokenType type, char token) : type(type), token(std::string(1,token)) {};
};

