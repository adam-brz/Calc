#include "Solver.h"
#include "SolverException.h"

#include <iostream>

int main()
{
    std::string input;
    Solver *solver = nullptr;

    std::cout << "This is calc, type \"quit\" to exit." << std::endl << std::endl;

    std::cout << "Calc is simple interpreter with support" << std::endl
              << "of basic (+, -, *, /) operations." << std::endl
              << "eg: (1 + 2)*2 + 2*2 = 10" << std::endl;

    while(true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if(input == "quit")
            break;

        solver = new Solver(input);
        try {
            std::cout << "Result: " << solver->interpret() << std::endl;
        } catch (SolverException& error) {
            std::cout << "Invalid expression!" << std::endl;
        }

        delete solver;
    }

    return 0;
}