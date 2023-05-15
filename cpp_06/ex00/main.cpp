#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if(argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    // std::cout << ScalarConverter.getInt() << std::endl;
    // std::cout << ScalarConverter.getFloat() << std::endl;
    // std::cout << ScalarConverter.getDouble() << std::endl;
    // std::cout << ScalarConverter.getChar() << std::endl;

    return 0;
}