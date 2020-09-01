#if !defined(_ADD_EXPR_H)
#define _ADD_EXPR_H

#include "ArithmeticExpr.h"

class AddExpr : public ArithmeticExpr
{
private:
    ArithmeticExpr *op1;
    ArithmeticExpr *op2;

public:
    AddExpr(ArithmeticExpr *op1, ArithmeticExpr *op2);
    Value interpret() override;
};

#endif // _ADD_EXPR_H
