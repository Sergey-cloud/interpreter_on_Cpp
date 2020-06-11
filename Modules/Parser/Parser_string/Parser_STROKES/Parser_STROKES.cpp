#include "Parser_STROKES.h"

    int oo = 0;

    char peek(string expressionToParse) 
    {
        return expressionToParse[oo];
    }

    char get(string expressionToParse)
    {
        return expressionToParse[oo++];
    }

    int expression(string expressionToParse);

    int number(string expressionToParse)
    {
        int result = get(expressionToParse) - '0';
        while (peek(expressionToParse) >= '0' && peek(expressionToParse) <= '9')
        {
            result = 10 * result + get(expressionToParse) - '0';
        }
        return result;
    }

    int factor(string expressionToParse)
    {
        if (peek(expressionToParse) >= '0' && peek(expressionToParse) <= '9')
            return number(expressionToParse);
        else if (peek(expressionToParse) == '(')
        {
            get(expressionToParse); // '('
            int result = expression(expressionToParse);
            get(expressionToParse); // ')'
            return result;
        }
        else if (peek(expressionToParse) == '-')
        {
            get(expressionToParse);
            return -factor(expressionToParse);
        }
        return 0; // error
    }

    int term(string expressionToParse)
    {
        int result = factor(expressionToParse);
        while (peek(expressionToParse) == '*' || peek(expressionToParse) == '/')
            if (get(expressionToParse) == '*')
                result *= factor(expressionToParse);
            else
                result /= factor(expressionToParse);
        return result;
    }

    int expression(string expressionToParse)
    {
        int result = term(expressionToParse);

        while (peek(expressionToParse) == '+' || peek(expressionToParse) == '-')
        {
            if (get(expressionToParse) == '+')
            {
                result += term(expressionToParse);
            }  
            else
            {
                result -= term(expressionToParse);
            }
        }
        return result;
    }

    void exp_int()
    {
        oo = 0;
    }