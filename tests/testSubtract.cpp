#include "catch.hpp"
#include "SubtractExpr.h"
#include "ValueExpr.h"

TEST_CASE("Subtract value expressions", "[SubtractExpr]")
{
    SubtractExpr subExpr(new ValueExpr(4), new ValueExpr(10));
    CHECK(subExpr.interpret() == Approx(-6));
}
