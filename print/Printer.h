#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../parser/AST/AST.h"
#include "../tokenizer/data/TokenType.h"
#include "../tokenizer/data/Token.h"

std::string tokenTypeToString(TokenType type);
void tokenTypeToString(std::vector<Token> tokens);
void printTree(const Expr* node, int depth = 0);