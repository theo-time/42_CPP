#ifndef BITCOINCONVERTER_HPP
#define BITCOINCONVERTER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdint.h>
#include <string.h>
#include <cstdlib>
#include <map>
#include <algorithm>

#include "Colors.hpp"

class BitcoinConverter
{

    private:
        std::map<std::string, float> _rates;
        std::map<std::string, float> _amounts;

    public:
        /* Coplian */
        BitcoinConverter();
        BitcoinConverter(BitcoinConverter const &other);
        BitcoinConverter &operator=(BitcoinConverter const &other);
        ~BitcoinConverter();

        /* Methods */
        void    importData();
        void    importCSV(std::string filename);
        void    convert(float amount);
        int     isValidDate(std::string date) const;

        /* logs */
        void  printRates(void);
        void  importSuccessMsg(void) const;
        void  importErrorMsg(void) const;
        void  convertSuccessMsg(void) const;
        float convertAmount(std::string date, float amount);

        /* Exceptions */
        class OpenFileError: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif