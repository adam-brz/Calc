#include "catch.hpp"
#include "ValueExpr.h"

TEST_CASE("Value expressions", "[ValueExpr]")
{
    ValueExpr value(3);
    CHECK(value.interpret() == Approx(3));
}
