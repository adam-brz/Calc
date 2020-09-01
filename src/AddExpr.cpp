#include "AddExpr.h"

AddExpr::AddExpr(ArithmeticExpr *op1, ArithmeticExpr *op2) :
    op1(op1), op2(op2)
{

}

AddExpr::~AddExpr()
{
    delete op1;
    delete op2;
}

Value AddExpr::interpret() 
{
    return op1->interpret() + op2->interpret();
}