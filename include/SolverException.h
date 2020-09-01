#if !defined(_SOLVER_EXCEPTION_H)
#define _SOLVER_EXCEPTION_H

#include <exception>

class SolverException : std::exception
{
public:
    const char* what() const noexcept {
        return "Error while solving equation";
    }
};

#endif // _SOLVER_EXCEPTION_H
