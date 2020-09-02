#include "ExprFactory.h"

#include "ValueExpr.h"
#include "AddExpr.h"
#include "SubtractExpr.h"
#include "MultiplyExpr.h"
#include "DivideExpr.h"
#include "PowExpr.h"

const std::list<std::pair<char, int>> ExprFactory::operators = 
{
    std::make_pair('-', 1),
    std::make_pair('+', 1),
    std::make_pair('/', 2),
    std::make_pair('*', 2),
    std::make_pair('^', 3)
};

ArithmeticExpr *ExprFactory::makeExpression(char operation,
                                ArithmeticExpr *op1,
                                ArithmeticExpr *op2)
{
    switch (operation)
    {
    case '-':
        return new SubtractExpr(op1, op2);

    case '+':
        return new AddExpr(op1, op2);

    case '/':
        return new DivideExpr(op1, op2);

    case '*':
        return new MultiplyExpr(op1, op2);

    case '^':
        return new PowExpr(op1, op2);
    }

    return nullptr;
}

ArithmeticExpr *ExprFactory::makeValueExpression(Value value)
{
    return new ValueExpr(value);
}

bool ExprFactory::isOperator(char c)
{
    for(auto pair : operators)
        if(pair.first == c)
            return true;

    return false;
}

bool ExprFactory::hasHigherPriority(char op1, char op2)
{           
    return getPriority(op1) > getPriority(op2);
}

int ExprFactory::getPriority(char op)
{
    for(auto pair : operators)
        if(pair.first == op)
            return pair.second;

    return -1;
}