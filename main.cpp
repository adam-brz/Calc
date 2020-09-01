#include "Solver.h"
#include "SolverException.h"

#include <iostream>

int main()
{
    std::string input;
    Value result;
    Solver *solver;

    std::cout << "This is calc, type \"quit\" to exit." << std::endl;

    while(true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if(input == "quit")
            break;

        try {
            solver = new Solver(input);
            result = solver->interpret();

            std::cout << "Result: " << result << std::endl;

        } catch (SolverException& error) {
            std::cout << "Invalid expression!" << std::endl;
        }
    }

    return 0;
}