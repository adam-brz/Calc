#if !defined(_EXPR_FACTORY_H)
#define _EXPR_FACTORY_H

#include "ArithmeticExpr.h"

#include <list>
#include <utility>

class ExprFactory
{
private:
    static const std::list<std::pair<char, int>> operators;

public:
    static ArithmeticExpr *makeExpression(char operation,
                                            ArithmeticExpr *op1,
                                            ArithmeticExpr *op2);

    static ArithmeticExpr *makeValueExpression(Value value);

    static bool isOperator(char c);
    static bool hasHigherPriority(char op1, char op2);
    static int getPriority(char op);
};

#endif // _EXPR_FACTORY_H
