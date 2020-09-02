#if !defined(_SOLVER_H)
#define _SOLVER_H

#include "ArithmeticExpr.h"
#include <string>
#include <list>

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
    void applyHighestPriority();
    int getHighestPriorityIndex();
    void mergeExpressionPair(int index);

    int parseChar(int pos);
    int findBracketEnd(int bracketStart);

    bool isDigit(char c);
};

#endif // _SOLVER_H
