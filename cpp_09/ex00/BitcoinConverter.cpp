#include "BitcoinConverter.hpp"

// Constructor - Destructor ====================================================

BitcoinConverter::BitcoinConverter()
{

}

BitcoinConverter::BitcoinConverter(BitcoinConverter const &other)
{
    *this = other;
}

BitcoinConverter &BitcoinConverter::operator=(BitcoinConverter const &other)
{
    if (this != &other)
    {
        this->_rates = other._rates;
    }
    return (*this);
}

BitcoinConverter::~BitcoinConverter()
{

}

// Methods =======================================================================

void BitcoinConverter::importCSV(std::string filename)
{
    // Open file
    std::ifstream fin(filename.c_str(), std::ios::in);

    // Check if file opened successfully
    if (!fin) { 
        throw BitcoinConverter::OpenFileError();
    }

    std::map<std::string,double> data;

    // import CSV in the map
    std::string line;
    std::getline(fin, line); // skip first line
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string key, value;
        std::getline(ss, key, ',');
        if(!isValidDate(key))
        {
            std::cout << RED << "[Error] data.csv: invalid date format: ";
            std::cout << key << DEFAULT << std::endl;
            continue;
        }
        std::getline(ss, value, ',');
        data[key] = std::atof(value.c_str());
    }
    importSuccessMsg();
    // Close file
    fin.close();
}

float BitcoinConverter::convertAmount(std::string date, float amount)
{
    return (amount * _rates[date]);
}


int BitcoinConverter::isValidDate(std::string dateString) const
{
    if(std::count(dateString.begin(), dateString.end(), '-') != 2)
        return 0;
    if (strspn(dateString.c_str(), "0123456789-") != dateString.length())
        return 0;
    if(dateString.length() != 10)
        return 0;
    if(dateString[4] != '-' || dateString[7] != '-')
        return 0;
    int month = std::atoi(dateString.substr(5,2).c_str());
    if(month < 1 || month > 12)
        return 0;
    int day = std::atoi(dateString.substr(8,2).c_str());
    if(day < 1 || day > 31)
        return 0;
    int year = std::atoi(dateString.substr(0,4).c_str());
    if(year < 1970 || year > 3000)
        return 0;
    // Check 30/31 days months
    if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        if(day > 30)
            return 0;
    }
    // Check February
    if(month == 2)
    {
        if(day > 29)
            return 0;
        if(day == 29)
        {
            if(year % 4 != 0)
                return 0;
            if(year % 100 == 0 && year % 400 != 0)
                return 0;
        }
    }
    return 1;
}


// logs =========================================================================

void BitcoinConverter::printRates(void)
{
    std::map<std::string,float>::iterator it;

    for (it = _rates.begin(); it != _rates.end(); it++)
    {
        std::cout << it->first    // string (key)
                << ':'
                << it->second   // string's value 
                << std::endl;
    }
}

void BitcoinConverter::importSuccessMsg(void) const
{
    std::cout << GREEN << "[Success] Rates imported sucessfully." << DEFAULT << std::endl;
}

void BitcoinConverter::importErrorMsg(void) const
{
    std::cout << RED << "[Error] Could not import rates." << DEFAULT << std::endl;
}

void BitcoinConverter::convertSuccessMsg(void) const
{
    std::cout << GREEN << "[Success] Conversion done." << DEFAULT << std::endl;
}

// Exceptions ====================================================================

const char* BitcoinConverter::OpenFileError::what() const throw()
{
    return ("Could not open file.");
}