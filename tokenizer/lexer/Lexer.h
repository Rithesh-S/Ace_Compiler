#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "../data/Token.h"
#include "../data/TokenType.h"

class Lexer {
    public:
        std::vector<Token> tokens;
        Lexer(std::string source);
        void scanTokens();
        
    private:
        std::string source_;
        std::string lex;

        char curr_;
        int pos_ = 0;
        int line = 1;

        void scanToken();
        bool isAtEnd();
        bool isDigit(char c);
        void consume(TokenType type, std::string num = "");
        void next();

};