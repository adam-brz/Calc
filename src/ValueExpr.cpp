#include "ValueExpr.h"

ValueExpr::ValueExpr(const Value &value) :
    value(value) 
{
        
}

Value ValueExpr::interpret() 
{
    return value;
}