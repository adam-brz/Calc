#include "catch.hpp"
#include "PowExpr.h"
#include "ValueExpr.h"

TEST_CASE("Pow value expressions", "[MultiplyExpr]")
{
    PowExpr powExpr(new ValueExpr(2), new ValueExpr(5));
    CHECK(powExpr.interpret() == Approx(32));
}
