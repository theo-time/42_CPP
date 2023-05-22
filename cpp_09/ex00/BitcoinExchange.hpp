#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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

class BitcoinExchange
{

    private:
        std::map<std::string, float> _rates;
        std::map<std::string, float> _amounts;

    public:
        /* Coplian */
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange &operator=(BitcoinExchange const &other);
        ~BitcoinExchange();

        /* Methods */
        // void    importData();
        void            importRates();
        void            convert(std::string filename);
        void            convertAmount(std::string date, float amount);
        int             isValidDate(std::string date) const;
        void            convertToClosestDate(std::string date, float amount) const;

        /* logs */
        void  printRates(void);
        void  importSuccessMsg(void) const;
        void  importErrorMsg(void) const;
        void  convertSuccessMsg(void) const;

        /* Exceptions */
        class OpenFileError: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif