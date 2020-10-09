#include "catch.hpp"
#include "AddExpr.h"
#include "ValueExpr.h"

TEST_CASE("Add value expressions", "[AddExpr]")
{
    AddExpr addExpr(new ValueExpr(4), new ValueExpr(10));
    CHECK(addExpr.interpret() == Approx(14));
}
