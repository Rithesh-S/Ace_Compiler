#pragma once

#include <memory>
#include <iostream>
#include "../parser/AST/AST.h"
#include "../parser/parser/Parser.h"

class Interpreter {

    public: 
        Interpreter(std::unique_ptr<Expr> root);
        double evaluate();

    private:
        std::unique_ptr<Expr> root_;
        double traverseTree(std::unique_ptr<Expr> root);

};