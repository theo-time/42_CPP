#include "ScalarConverter.hpp"

/* Coplian Functions */

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter &rhs)
{
    (void)rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs)
{
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

/* Methods */

int isFloat(std::string input)
{
    char *ptr;
    if (strspn(input.c_str(), "0123456789.+-f") != input.length())
        return 0;
    if(std::count(input.begin(), input.end(), '.') > 1 
        || std::count(input.begin(), input.end(), '+') + std::count(input.begin(), input.end(), '-') > 1 
        || std::count(input.begin(), input.end(), 'f') > 1
    )
        return 0;
    ptr = (char*) strchr(input.c_str(), '+');
    if(ptr && input.c_str() - ptr > 0)
        return 0;
    ptr = (char*) strchr(input.c_str(), '-');
    if(ptr && input.c_str() - ptr > 0)
        return 0;
    ptr = (char*) strchr(input.c_str(), '.');
    if(ptr && (input.c_str() - ptr == 0 || ptr - input.c_str() == (long) (input.length() - 1)))
        return 0;
    ptr = (char*) strchr(input.c_str(), 'f');
    if(ptr && ptr - input.c_str() != (long) (input.length() - 1))
        return 0;
    return 1;
}


int isDouble(std::string input)
{
    char *ptr;
    if (strspn(input.c_str(), "0123456789.+-") != input.length())
        return 0;
    if(std::count(input.begin(), input.end(), '.') > 1 
        || std::count(input.begin(), input.end(), '+') + std::count(input.begin(), input.end(), '-') > 1 
    )
        return 0;
    ptr = (char*) strchr(input.c_str(), '+');
    if(ptr && input.c_str() - ptr > 0)
        return 0;
    ptr = (char*) strchr(input.c_str(), '-');
    if(ptr && input.c_str() - ptr > 0)
        return 0;
    ptr = (char*) strchr(input.c_str(), '.');
    if(ptr && (input.c_str() - ptr == 0 || ptr - input.c_str() == (long) (input.length() - 1)))
        return 0;
    return 1;
}

int ScalarConverter::getInputType(std::string input)
{
    if(strcmp(input.c_str(), "-inff") == 0 
            || strcmp(input.c_str(), "+inff") == 0 
            || strcmp(input.c_str(), "nanf") == 0)
        return FLOAT;
    else if(strcmp(input.c_str(), "-inf") == 0 
            || strcmp(input.c_str(), "+inf") == 0 
            || strcmp(input.c_str(), "nan") == 0)
        return DOUBLE;
    if (input.length() == 1 && !isdigit(input[0]))
        return CHAR;
    else if (isFloat(input))
        return FLOAT;
    else if (isDouble(input))
        return DOUBLE;
    else
        return INVALID;
}

void ScalarConverter::convertChar(std::string input)
{
    char _char = input[0];
    printChar(_char);
    printInt(static_cast<int>(_char));
    printFloat(static_cast<float>(_char));
    printDouble(static_cast<float>(_char));
}

void ScalarConverter::convertInt(std::string input)
{
    int _int = static_cast<int>(atof(input.c_str()));
    printChar(static_cast<char>(_int));
    printInt(_int);
    printFloat(static_cast<float>(_int));
    printDouble(static_cast<double>(_int));
}

void ScalarConverter::convertFloat(std::string input)
{
    float _float = static_cast<float>(atof(input.c_str()));
    printChar(static_cast<char>(_float));
    printInt(static_cast<int>(_float));
    printFloat(_float);
    printDouble(static_cast<double>(_float));
}

void ScalarConverter::convertDouble(std::string input)
{
    double _double = static_cast<float>(atof(input.c_str()));
    printChar(static_cast<int>(_double));
    printInt(static_cast<int>(_double));
    printFloat(static_cast<float>(_double));
    printDouble(_double);
}

int ScalarConverter::convert(std::string input)
{
    switch(getInputType(input))
    {
        case CHAR:
            convertChar(input);
            break;
        case INT:
            convertInt(input);
            break;
        case FLOAT: 
            convertFloat(input);
            break;
        case DOUBLE:
            convertDouble(input);
            break;
        case INVALID:
            std::cout << "type conversion impossible" << std::endl;
            break;
    }
    return (1);
}

void ScalarConverter::printChar(char _char)
{
    std::cout << "char: ";
    if (_char < 32 || _char > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << _char<< "'" << std::endl;
}

void ScalarConverter::printInt(int _int)
{
    std::cout << "int: " << _int << std::endl;
}

void ScalarConverter::printFloat(float _float)
{
    std::cout << "float: " << _float << "f" << std::endl;
}

void ScalarConverter::printDouble(double _double)
{
    std::cout << "double: " << _double << "f" << std::endl;
}
