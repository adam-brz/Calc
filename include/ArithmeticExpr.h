#if !defined(_ARITHMETIC_EXPR_H)
#define _ARITHMETIC_EXPR_H

#include "Value.h"

class ArithmeticExpr
{
public:
    virtual Value interpret() = 0;
};

#endif // _ARITHMETIC_EXPR_H
