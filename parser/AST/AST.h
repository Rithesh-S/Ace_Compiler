#pragma once

#include <memory>

struct Expr {
    virtual ~Expr() = default;
};

struct Binary : public Expr {
    std::unique_ptr<Expr> left;
    char opr;
    std::unique_ptr<Expr> right;

    Binary(std::unique_ptr<Expr> left, char opr, std::unique_ptr<Expr> right) :
        left(std::move(left)), opr(opr), right(std::move(right)) {}

};

struct Literal : public Expr {
    double val;

    Literal(double val) : val(val) {}

};