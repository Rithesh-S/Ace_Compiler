#include <iostream>
#include <vector>
#include <fstream>
#include "./tokenizer/lexer/Lexer.h"

using std::cout;
using std::endl;

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

bool fileFormatChecker(std::string fileName) {
    int pos = fileName.find('.');
    if(fileName.substr(pos + 1) == "a") {
        return true;
    }
    return false;
}

bool checkFileExistance(const std::string& fileName, std::ifstream& inFile) {
    std::string filePath = "./src/" + fileName;
    inFile.open(filePath);
    return inFile.is_open();
}

int main(int argc,char* argv[]) {
    
    if(argc < 2) {
        std::cerr << "\033[31mERROR: Provide Input File: Obtained null\033[0m" << endl;
        return 1;
    }

    std::string fileName = argv[1];
    if(!fileFormatChecker(fileName)) {
        std::cerr << "\033[31mERROR: Unrecognizable File Format: " << fileName << "\033[0m" << endl;
        return 1;
    }

    std::ifstream inFile;
    
    if(!checkFileExistance(fileName, inFile)) {
        std::cerr << "\033[31mERROR: File does'nt exists in src folder: " << fileName << "\033[0m" << endl;
        return 1;
    } 

    std::string line, lines = "";

    while(std::getline(inFile, line)) lines += line + '\n';
    
    Lexer lexer = Lexer(lines);
    lexer.scanTokens();
    for (auto i: lexer.tokens) {
        cout<<tokenTypeToString(i.type)<<" "<<i.token<<endl;
    }
}