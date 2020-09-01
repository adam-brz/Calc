#include "SubtractExpr.h"

SubtractExpr::SubtractExpr(ArithmeticExpr *op1, ArithmeticExpr *op2) :
    op1(op1), op2(op2)
{

}

SubtractExpr::~SubtractExpr()
{
    delete op1;
    delete op2;
}

Value SubtractExpr::interpret() 
{
    return op1->interpret() - op2->interpret();
}