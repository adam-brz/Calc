#include "MultiplyExpr.h"

MultiplyExpr::MultiplyExpr(ArithmeticExpr *op1, ArithmeticExpr *op2) :
    op1(op1), op2(op2)
{

}

Value MultiplyExpr::interpret() 
{
    return op1->interpret() * op2->interpret();
}