#if !defined(_VALUE_EXPR_H)
#define _VALUE_EXPR_H

#include "ArithmeticExpr.h"

class ValueExpr : public ArithmeticExpr
{
private:
    Value value;

public:
    ValueExpr(const Value &value);
    virtual Value interpret() override;
};

#endif // _VALUE_EXPR_H
