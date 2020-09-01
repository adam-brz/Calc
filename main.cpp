#include "Solver.h"
#include <iostream>

int main()
{
    Solver solver("1 + ((2*3 + 1) + (2 + 3*5)*2) - 3*(2 - 1)");
    std::cout << solver.interpret() << std::endl;

    return 0;
}