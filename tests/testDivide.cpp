#include "catch.hpp"
#include "DivideExpr.h"
#include "ValueExpr.h"

TEST_CASE("Divide value expressions", "[DivideExpr]")
{
    DivideExpr divExpr(new ValueExpr(20), new ValueExpr(5));
    CHECK(divExpr.interpret() == Approx(4));
}
