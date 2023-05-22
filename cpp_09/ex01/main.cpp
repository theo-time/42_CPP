#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./rpn [reverse polish expression]" << std::endl;
        return 1;
    }
    std::string expr = argv[1];

    std::stack<double> stack;

    if(expr.length() == 0)
    {
        std::cout << RED << "[Error] Empty expression" << DEFAULT << std::endl;
        return 1;
    }

    if(strspn(expr.c_str(), "0123456789+-*/ ") != expr.length())
    {
        std::cout << RED << "[Error] Invalid character in expression" << DEFAULT << std::endl;
        return 1;
    }

    while (expr.length() > 0)
    {
        if (expr[0] == ' ')
            expr.erase(0, 1);
        else if (expr[0] >= '0' && expr[0] <= '9')
        {
            std::string token = expr.substr(0, expr.find(' '));
            if(token.length() != 1 || strspn(token.c_str(), "0123456789") != token.length())
            {
                std::cout << RED << "[Error] Invalid number : " << token << DEFAULT << std::endl;
                return 1;
            }
            stack.push(std::atof(token.c_str()));
            expr.erase(0, expr.find(' '));
        }
        else if (expr[0] == '+' || expr[0] == '-' || expr[0] == '*' || expr[0] == '/')
        {
            if (stack.size() < 2)
            {
                std::cout << RED << "[Error] Not enough values in stack" << DEFAULT << std::endl;
                return 1;
            }
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            if (expr[0] == '+')
                stack.push(b + a);
            else if (expr[0] == '-')
                stack.push(b - a);
            else if (expr[0] == '*')
                stack.push(b * a);
            else if (expr[0] == '/')
            {
                if (a == 0)
                {
                    std::cout << RED << "[Error] Division by zero" << DEFAULT << std::endl;
                    return 1;
                }
                stack.push(b / a);
            }
            expr.erase(0, 1);
        }
        else
        {
            std::cout << RED << "[Error] Invalid character: " << expr[0] << DEFAULT << std::endl;
            return 1;
        }
    }

    if(stack.size() != 1)
    {
        std::cout << RED << "[Error] Too many values in stack" << DEFAULT << std::endl;
        return 1;
    }
    std::cout << stack.top() << std::endl;

    return 0;
}