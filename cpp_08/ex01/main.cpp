#include <iostream>
#include <vector>
#include <iomanip>
#include "Span.hpp"
#include "Colors.hpp"

// This function uses <iomanip> to print the string with a fixed width
// and left alignment, with the character '-' as padding.
void printTitle(std::string title)
{
    std::cout << " " << YELLOW << std::setw(50);
    std::cout << std::setfill('-');
    // center the title
    std::cout << std::left;
    std::cout << std::endl;
    std::cout << title << std::endl;
    std::cout << DEFAULT << " " << std::endl;
}

// int main()
// {
//     // Basic tests
//     std::cout << std::setw(2);
//     std::cout << std::endl;
//     printTitle("--[ Basic tests ]");
//     std::cout << std::endl;
//     Span sp(5);
//     sp.addNumber(5);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << "sp = {5, 3, 17, 9, 11}" << std::endl;
//     std::cout << "sp.shortestSpan() = " << sp.shortestSpan() << std::endl;
//     std::cout << "sp.longestSpan() = " << sp.longestSpan() << std::endl;

//     // Exception: Container is full
//     std::cout << std::endl;
//     printTitle("--[ Full container test ]");
//     std::cout << std::endl;
//     try
//     {
//         sp.addNumber(42);
//         sp.addNumber(42);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << std::endl << RED << " [Error] ";
//         std::cerr << e.what() << DEFAULT << std::endl;
//     }

//     // Exception: Container is empty
//     std::cout << std::endl;
//     printTitle("--[ Empty container test ]");
//     std::cout << std::endl;
//     try
//     {
//         Span sp2(5);
//         std::cout << "sp2 = {}" << std::endl;
//         std::cout << "sp2.shortestSpan() = " << sp2.shortestSpan() << std::endl;
//         std::cout << "sp2.longestSpan() = " << sp2.longestSpan() << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << std::endl << RED << " [Error] ";
//         std::cerr << e.what() << DEFAULT << std::endl;
//     }

//     // Exception: Contains only one element
//     std::cout << std::endl;
//     printTitle("--[ One element container test ]");
//     std::cout << std::endl;
//     try
//     {
//         Span sp3(5);
//         sp3.addNumber(42);
//         std::cout << "sp3 = {42}" << std::endl;
//         std::cout << "sp3.shortestSpan() = " << sp3.shortestSpan() << std::endl;
//         std::cout << "sp3.longestSpan() = " << sp3.longestSpan() << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << std::endl << RED << " [Error] ";
//         std::cerr << e.what() << DEFAULT << std::endl;
//     }

//     // Performance test
//     std::cout << std::endl;
//     // std::cout << YELLOW << " [ Performance test ]" << DEFAULT << std::endl;
//     printTitle("--[ Performance test ]");
//     std::cout << std::endl;
//     try
//     {
//         srand(time(NULL));
//         Span sp4(10000);
//         for(int i = 0; i < 10000; i++)
//             sp4.addNumber(rand() % 1000000);
//         std::cout << "sp4 = 10,000 random numbers" << std::endl;
//         std::cout << "sp4.shortestSpan() = " << sp4.shortestSpan() << std::endl;
//         std::cout << "sp4.longestSpan() = " << sp4.longestSpan() << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << std::endl << RED << " [Error] ";
//         std::cerr << e.what() << DEFAULT << std::endl;
//     }

//     // Sequence test
//     std::cout << std::endl;
//     printTitle("--[ Sequence test ]");
//     std::cout << std::endl;
//     try
//     {
//         std::vector<int> vec;
//         vec.push_back(1);
//         vec.push_back(2);
//         vec.push_back(3);
//         vec.push_back(4);
//         vec.push_back(5);
//         Span sp5(5);
//         sp5.addSequence(vec.begin(), vec.end());
//         std::cout << "sp5 = {1, 2, 3, 4, 5}" << std::endl;
//         std::cout << "sp5.shortestSpan() = " << sp5.shortestSpan() << std::endl;
//         std::cout << "sp5.longestSpan() = " << sp5.longestSpan() << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << std::endl << RED << " [Error] ";
//         std::cerr << e.what() << DEFAULT << std::endl;
//     }
// }

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}