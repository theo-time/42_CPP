#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP
#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <algorithm>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define INVALID 4

class ScalarConverter
{
    
    public:

        /* Coplian */
        ScalarConverter();
        ScalarConverter(ScalarConverter &rhs);
        ScalarConverter& operator=(const ScalarConverter &rhs);
        virtual ~ScalarConverter();

        /* Getters and setters */
        static int     getInt(void);
        static float   getFloat(void);
        static double  getDouble(void);
        static char    getChar(void);

        /* Methods */
        static int    convert(std::string input);
        static void    printInt(int _int);
        static void    printFloat(float _float);
        static void    printDouble(double _double);
        static void    printChar(char _char);
        static void    print();
        static int     getInputType(std::string input);
        static void    convertChar(std::string input);
        static void    convertInt(std::string input);
        static void    convertFloat(std::string input);
        static void    convertDouble(std::string input);
};

#endif