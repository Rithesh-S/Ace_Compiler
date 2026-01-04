#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <typeinfo>
#include "../data/Token.h"
#include "../data/TokenType.h"

class Lexer {
    public:
        Lexer(std::string source);
        void scanTokens();
        std::vector<Token> tokens;
        
    private:
        std::string source_;
        std::string lex;

        char curr_;
        int pos_ = 0;
        int line;

        void scanToken();
        bool isAtEnd();
        bool isDigit(char c);
        void consume(TokenType type);
        void next();

};