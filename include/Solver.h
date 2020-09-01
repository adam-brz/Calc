#if !defined(_SOLVER_H)
#define _SOLVER_H

#include "ArithmeticExpr.h"
#include <string>
#include <list>
#include <utility>

class Solver : ArithmeticExpr
{
    std::string literal;

    std::list<char> operators;
    std::list<ArithmeticExpr*> expressions;

public:
    Solver(const std::string &literal);
    ~Solver();
    
    Value interpret() override;

private:
    ArithmeticExpr* parseSubLiteral(std::string literal);
    bool isDigit(char c);

    void applyOperator();

    int findBracketEnd(std::string literal, int bracketStart);
    void clearMemory();
};

class Operator
{
    static const std::list<std::pair<char, int>> operators;

public:
    static bool isOperator(char c);
    static bool hasHigherPriority(char op1, char op2);
    static int getPriority(char op);
};

#endif // _SOLVER_H
