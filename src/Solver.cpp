#include "Solver.h"

#include "ValueExpr.h"
#include "AddExpr.h"
#include "SubtractExpr.h"
#include "MultiplyExpr.h"

#include <iostream>

using namespace std;

const std::list<std::pair<char, int>> Operator::operators = 
{
    std::make_pair('-', 1),
    std::make_pair('+', 1),
    std::make_pair('/', 2),
    std::make_pair('*', 2),
};

Solver::Solver(const std::string &literal) :
    literal(literal)
{

}

Solver::~Solver() 
{
    clearMemory();
}

void Solver::clearMemory()
{
    for(auto expression : expressions)
        delete expression;

    expressions.clear();
}

Value Solver::interpret()
{
    cout << "Solve requested\n";

    ArithmeticExpr* final = parseSubLiteral(literal);
    Value result = 0;

    if(final) {
        result = final->interpret();
    }

    clearMemory();
    return result;
}

ArithmeticExpr* Solver::parseSubLiteral(std::string literal)
{
    size_t idx;
    std::string a;

    cout << "Parsing: " << literal << endl;
    

    for(int i = 0; i < literal.size(); ++i)
    {
        std::getline (std::cin,a);

        cout << "i: " << i << endl;
        

        if(literal[i] == ' ')
            continue;
        else if(isDigit(literal[i]))
        {
            double val = std::stod(literal.substr(i), &idx);
            cout << "Number: " << val << endl;
            
            expressions.push_back(new ValueExpr(val));
            i += idx - 1;
        }
        else if(literal[i] == '(')
        {
            idx = findBracketEnd(literal, i);
            expressions.push_back(parseSubLiteral(literal.substr(i + 1, idx - i - 1)));
            cout << "Parsed brackets: " << i << ":" << idx << endl;
            i = idx;
            
        }
        else if(Operator::isOperator(literal[i]))
        {
            cout << "Operator: " << literal[i] << endl;
            while(!operators.empty() && Operator::hasHigherPriority(operators.back(), literal[i]))
            {
                cout << "Applying: " << operators.back() << endl;
                applyOperator();
            }
            operators.push_back(literal[i]);
        }

        cout << "Expressions: " << expressions.size() << endl;
    }

    while(!operators.empty())
    {
        applyOperator();
    }

    return expressions.front();
}

void Solver::applyOperator()
{
    ArithmeticExpr *newExpr = nullptr;
    ArithmeticExpr *op1, *op2;

    op1 = expressions.back();
    expressions.pop_back();

    op2 = expressions.back();
    expressions.pop_back();

    switch (operators.back())
    {
    case '+':
        newExpr = new AddExpr(op1, op2);
        break;

    case '-':
        newExpr = new SubtractExpr(op1, op2);
        break;

    case '/':
        newExpr = new AddExpr(op1, op2);
        break;

    case '*':
        newExpr = new MultiplyExpr(op1, op2);
        break;
    
    default:
        break;
    }

    operators.pop_back();
    expressions.push_back(newExpr);
}

bool Solver::isDigit(char c)
{
    return (c >= '0') && (c <= '9');
}

int Solver::findBracketEnd(std::string literal, int bracketStart)
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

    return (brackets == 0) ? pos : -1;
}

bool Operator::isOperator(char c)
{
    for(auto pair : operators)
        if(pair.first == c)
            return true;

    return false;
}

bool Operator::hasHigherPriority(char op1, char op2)
{           
    return getPriority(op1) > getPriority(op2);
}

int Operator::getPriority(char op)
{
    for(auto pair : operators)
        if(pair.first == op)
            return pair.second;

    return -1;
}