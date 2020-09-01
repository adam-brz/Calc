#if !defined(_MULTIPLY_EXPR_H)
#define _MULTIPLY_EXPR_H

#include "ArithmeticExpr.h"

class MultiplyExpr : public ArithmeticExpr
{
private:
    ArithmeticExpr *op1;
    ArithmeticExpr *op2;

public:
    MultiplyExpr(ArithmeticExpr *op1, ArithmeticExpr *op2);
    Value interpret() override;
};

#endif // _MULTIPLY_EXPR_H
