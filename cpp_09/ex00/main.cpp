#include "BitcoinConverter.hpp"

int main(int argc, char **argv)
{
    // Check if filename is provided
    if(argc != 2)
    {
        std::cout << "Usage: ./a.out <filename>" << std::endl;
        return 1;
    }

    // Create BitcoinConverter object
    BitcoinConverter bc;

    // Import rates from file
    try
    {
        bc.importRates(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << std::endl << RED << " [Error] " << e.what() << DEFAULT << std::endl;
    }

    return 0;
}