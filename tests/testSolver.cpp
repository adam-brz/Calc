#include "catch.hpp"
#include "Solver.h"
#include "SolverException.h"

TEST_CASE("Pass empty string", "[Solver]")
{
    Solver solver("");
    CHECK_THROWS_AS(solver.interpret(), SolverException);
}

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

TEST_CASE("Solving equations with more operators", "[Solver]")
{
    Solver solver1("2 + 2 * 2");
    Solver solver2("3 * 2 + 4 - 3");
    Solver solver3("8 / 2 + 2 * 2");
    Solver solver4("3 - 4 * 3 * 2");

    CHECK(solver1.interpret() == Approx(6));
    CHECK(solver2.interpret() == Approx(7));
    CHECK(solver3.interpret() == Approx(8));
    CHECK(solver4.interpret() == Approx(-21));
}

TEST_CASE("Solving equations with brackets", "[Solver]")
{
    Solver solver1("(2 + 2) * 2");
    Solver solver2("3 * ((2 + 4) - 3)");
    Solver solver3("8 / (2 + 2) * 2");
    Solver solver4("(((3 - 4) * 3 )+ 2)");

    CHECK(solver1.interpret() == Approx(8));
    CHECK(solver2.interpret() == Approx(9));
    CHECK(solver3.interpret() == Approx(4));
    CHECK(solver4.interpret() == Approx(-1));
}

TEST_CASE("Solving stacked", "[Solver]")
{
    Solver solver1("1+1+1+1");
    Solver solver2("1-1-1-1");
    Solver solver3("2*2*2*2");
    Solver solver4("8/2/2/2");

    CHECK(solver1.interpret() == Approx(4));
    CHECK(solver2.interpret() == Approx(-2));
    CHECK(solver3.interpret() == Approx(16));
    CHECK(solver4.interpret() == Approx(1));
}

TEST_CASE("Exception throwing", "[Solver]")
{
    Solver solver1("1+");
    Solver solver2("1-1-'-1");
    Solver solver3("2+(2*2+2");
    Solver solver4("8/2-2)/2");

    CHECK_THROWS_AS(solver1.interpret(), SolverException);
    CHECK_THROWS_AS(solver2.interpret(), SolverException);
    CHECK_THROWS_AS(solver3.interpret(), SolverException);
    CHECK_THROWS_AS(solver4.interpret(), SolverException);
}

TEST_CASE("Pow functionality", "[Solver]")
{
    Solver solver1("2^3");
    Solver solver2("2*(1+2)^2");
    Solver solver3("2^3^2");
    Solver solver4("1+9^0.5");

    CHECK(solver1.interpret() == Approx(8));
    CHECK(solver2.interpret() == Approx(18));
    CHECK(solver3.interpret() == Approx(64));
    CHECK(solver4.interpret() == Approx(4));
}
