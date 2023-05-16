#include <iostream>
#include <string>
# include <stdint.h>

#include "Array.hpp"
#include "Colors.hpp"

int main( void ) {
    Array<int> int_array(10);
    Array<std::string> string_array(10);

    // Basic tests
    std::cout << std::endl;
    std::cout << GREEN << " [Basic tests] " << DEFAULT << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
    {
        int_array[i] = i;
        string_array[i] = "Hello world";
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << int_array[i] << std::endl;
        std::cout << string_array[i] << std::endl;
    }
    std::cout << "size : " << int_array.size() << std::endl;
    std::cout << "size : " << string_array.size() << std::endl;

    // Copy constructor
    std::cout << std::endl;
    std::cout << GREEN << " [Copy constructor tests] " << DEFAULT << std::endl;
    std::cout << std::endl;
    Array<int> int_array_copy(int_array);
    for (int i = 0; i < 10; i++)
    {
        int_array[i] = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << int_array_copy[i] << std::endl;
    }

    // int overflow tests
    std::cout << std::endl;
    std::cout << GREEN << " [int overflow tests] " << DEFAULT << std::endl;
    std::cout << std::endl;
    try
    {
        Array<int> int_array_overflow(2147483648);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "[error] " << e.what()  << DEFAULT << '\n';
    }

    // Out of range tests
    std::cout << std::endl;
    std::cout << GREEN << " [access out of range test] " << DEFAULT << std::endl;
    std::cout << std::endl;
    try
    {
        int_array[10] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "[error] " << e.what()  << DEFAULT << '\n';
    }
    return 0;
}