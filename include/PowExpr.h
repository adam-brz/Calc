#if !defined(_POW_EXPR_H)
#define _POW_EXPR_H

#include "ArithmeticExpr.h"

class PowExpr : public ArithmeticExpr
{
private:
    ArithmeticExpr *op1;
    ArithmeticExpr *op2;

public:
    PowExpr(ArithmeticExpr *op1, ArithmeticExpr *op2);
    ~PowExpr();
    
    Value interpret() override;
};

#endif // _POW_EXPR_H
