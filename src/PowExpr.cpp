#include "PowExpr.h"
#include <cmath>

PowExpr::PowExpr(ArithmeticExpr *op1, ArithmeticExpr *op2) :
    op1(op1), op2(op2)
{

}

PowExpr::~PowExpr()
{
    delete op1;
    delete op2;
}

Value PowExpr::interpret() 
{
    return std::pow(op1->interpret(), op2->interpret());
}