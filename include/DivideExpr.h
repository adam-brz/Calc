#if !defined(_DIVIDE_EXPR_H)
#define _DIVIDE_EXPR_H

#include "ArithmeticExpr.h"

class DivideExpr : ArithmeticExpr
{
private:
    ArithmeticExpr *op1;
    ArithmeticExpr *op2;

public:
    DivideExpr(ArithmeticExpr *op1, ArithmeticExpr *op2);
    Value interpret() override;
};

#endif // _DIVIDE_EXPR_H
