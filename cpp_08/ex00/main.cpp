#include <iostream>
#include <vector>
#include "easyfind.hpp"
#include "Colors.hpp"

int main()
{
    std::vector<int> vec;
    std::vector<int> empty_vec;
    std::vector<std::string> string_vec;

    try
    {
        // Basic tests
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        std::cout << std::endl;
        std::cout << GREEN << " [ Basic tests ]" << DEFAULT << std::endl;
        std::cout << std::endl;
        std::cout << "vec = {10, 20, 30, 40}" << std::endl;
        std::cout << "easyfind(vec, 30) = " << *easyfind(vec, 30) << std::endl;
        std::cout << "easyfind(vec, 8) = " << *easyfind(vec, 8) << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << std::endl << RED << " [Error] ";
        std::cerr << e.what() << DEFAULT << std::endl;
    }

    try
    {
        // Empty vector
        std::cout << std::endl;
        std::cout << GREEN << " [ Empty vector ]" << DEFAULT << std::endl;
        std::cout << std::endl;
        std::cout << "vec = {}" << std::endl;
        std::cout << "easyfind(vec, 30) = " << *easyfind(empty_vec, 30) << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << std::endl << RED << " [Error] ";
        std::cerr << e.what() << DEFAULT << std::endl;
    }
}