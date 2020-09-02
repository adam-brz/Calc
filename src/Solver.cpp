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

    if(operators.size() + 1 != expressions.size())
        throw SolverException();

    while(!operators.empty())
        applyHighestPriority();

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
        operators.push_back(chr);
    }
    else if(chr != ' ')
    {
        throw SolverException();
    }

    return pos;
}

void Solver::applyHighestPriority()
{
    const int index = getHighestPriorityIndex();
    mergeExpressionPair(index);
}

int Solver::getHighestPriorityIndex()
{
    int index, newPriority, i;
    int priority = -1;

    i = 0;
    for(const auto &op: operators)
    {
        newPriority = ExprFactory::getPriority(op);

        if(newPriority > priority)
        {
            index = i;
            priority = newPriority;
        }

        ++i;
    }
        
    return index;
}

void Solver::mergeExpressionPair(int index)
{
    ArithmeticExpr *newExpr;
    auto operatorIter = operators.begin();
    auto iter1 = expressions.begin();
    auto iter2 = iter1;
    int i = 0;

    while(iter2 != expressions.end() && i < index)
    {
        ++iter2;
        ++operatorIter;
        ++i;
    }
    
    iter1 = iter2;
    ++iter2;

    newExpr = ExprFactory::makeExpression(*operatorIter, *iter1, *iter2);
    expressions.insert(iter1, newExpr);

    operators.erase(operatorIter);
    expressions.erase(iter1);
    expressions.erase(iter2);
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
