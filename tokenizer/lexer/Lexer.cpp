#include "Lexer.h"

Lexer::Lexer(std::string source) : source_(move(source)) {};

void Lexer::scanTokens() {
    curr_ = source_[pos_];
    while(!isAtEnd()) {
        scanToken();
    }
    tokens.push_back(Token(TokenType::END_OF_FILE,""));
    return;
}

void Lexer::scanToken() {
    switch(curr_) {
        case '(':
        case ')':
            consume(TokenType::PARENTHESES);
            break;

        case '+':
            consume(TokenType::PLUS);
            break;
        
        case '-':
            consume(TokenType::MINUS);
            break;

        case '*':
            consume(TokenType::ASTERISK);
            break;

        case '/':
            consume(TokenType::SLASH);
            break;

        case '\n':
        case '\r':
        case ' ':
            next();
            break;

        default:
            if(isDigit(curr_)) {
                std::string num = "";
                while(isDigit(curr_)) {
                    num += curr_;
                    next();
                }
                consume(TokenType::NUMBER, num);
            } else {
                std::cerr << "\033[31mERROR: Undefined Data Type Provided: " << curr_ << "\033[0m" << std::endl;
                next();
            }
            break;
    }
}

bool Lexer::isAtEnd() {
    return pos_ >= source_.length(); 
}

bool Lexer::isDigit(char c) {
    return c <= '9' && c >= '0';
}

void Lexer::consume(TokenType type, std::string num) {
    if(num != "")  tokens.push_back(Token(type, num));
    else  tokens.push_back(Token(type,curr_));
    next();
}

void Lexer::next() {
    pos_++;
    curr_ = source_[pos_];
}

