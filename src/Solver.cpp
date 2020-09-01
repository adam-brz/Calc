#include "Solver.h"
#include "ExprFactory.h"
#include "SolverException.h"

Solver::Solver(const std::string &literal) :
    literal(literal)
{

}

Solver::~Solver() 
{
    for(auto expression : expressions)
        delete expression;
}

Value Solver::interpret()
{
    for(int i = 0; i < literal.size(); ++i)
        i = parseChar(i);

    while(!operators.empty())
        applyOperator();

    if(expressions.size() != 1)
        throw SolverException();

    return expressions.front()->interpret();
}

int Solver::parseChar(int pos)
{
    char chr = literal[pos];
    size_t idx;

    if (isDigit(chr))
    {
        double val = std::stod(literal.substr(pos), &idx);
        expressions.push_back(ExprFactory::makeValueExpression(val));
        pos += idx - 1;
    }
    else if (chr == '(')
    {
        idx = findBracketEnd(pos);

        if(idx == 0)
            throw SolverException();

        expressions.push_back(new Solver(literal.substr(pos + 1, idx - pos - 1)));
        pos = idx;
    }
    else if (ExprFactory::isOperator(chr))
    {
        while (!operators.empty() &&
                 ExprFactory::hasHigherPriority(operators.back(), chr))
        {
            applyOperator();
        }
        operators.push_back(chr);
    }
    else if(chr != ' ')
    {
        throw SolverException();
    }

    return pos;
}

void Solver::applyOperator()
{
    ArithmeticExpr *newExpr;
    ArithmeticExpr *op1, *op2;

    op2 = expressions.back();
    expressions.pop_back();

    op1 = expressions.back();
    expressions.pop_back();

    newExpr = ExprFactory::makeExpression(operators.back(), op1, op2);
    operators.pop_back();

    expressions.push_back(newExpr);
}

bool Solver::isDigit(char c)
{
    return (c >= '0') && (c <= '9');
}

int Solver::findBracketEnd(int bracketStart)
{
    int pos = bracketStart;
    int brackets = 1;

    while (pos < literal.size() && brackets != 0)
    {
        ++pos;
        if(literal[pos] == '(')
            ++brackets;
        else if(literal[pos] == ')')
            --brackets;
    }

    return (brackets == 0) ? pos : 0;
}
