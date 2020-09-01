#include "Solver.h"
#include <iostream>

int main()
{
    Solver solver("(10 + 2) * 2");
    std::cout << solver.interpret() << std::endl;

    return 0;
}