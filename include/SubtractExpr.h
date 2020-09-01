#if !defined(_SUBTRACT_EXPR_H)
#define _SUBTRACT_EXPR_H

#include "ArithmeticExpr.h"

class SubtractExpr : public ArithmeticExpr
{
private:
    ArithmeticExpr *op1;
    ArithmeticExpr *op2;

public:
    SubtractExpr(ArithmeticExpr *op1, ArithmeticExpr *op2);
    ~SubtractExpr();
    
    Value interpret() override;
};

#endif // _SUBTRACT_EXPR_H
