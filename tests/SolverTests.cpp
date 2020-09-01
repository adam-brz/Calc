#include "catch.hpp"
#include "Solver.h"
#include "SolverException.h"

TEST_CASE("Solving simple equations", "[Solver]")
{
    Solver solver1("2 + 2");
    Solver solver2("3 * 2");
    Solver solver3("8 / 2");
    Solver solver4("3 - 4");

    CHECK(solver1.interpret() == Approx(4));
    CHECK(solver2.interpret() == Approx(6));
    CHECK(solver3.interpret() == Approx(4));
    CHECK(solver4.interpret() == Approx(-1));
}
