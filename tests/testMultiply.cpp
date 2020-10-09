#include "catch.hpp"
#include "MultiplyExpr.h"
#include "ValueExpr.h"

TEST_CASE("Multiply value expressions", "[MultiplyExpr]")
{
    MultiplyExpr mulExpr(new ValueExpr(20), new ValueExpr(5));
    CHECK(mulExpr.interpret() == Approx(100));
}
