#include "BitcoinExchange.hpp"

// Trim utils ====================================================================

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

// Constructor - Destructor ====================================================

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
    {
        this->_rates = other._rates;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

// Methods =======================================================================

void BitcoinExchange::importRates()
{
    // Open file
    std::ifstream fin("data.csv", std::ios::in);

    // Check if file opened successfully
    if (!fin) { 
        throw BitcoinExchange::OpenFileError();
    }

    // import CSV in the map
    std::string line;
    std::getline(fin, line); // skip first line
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string key, value;
        std::getline(ss, key, ',');
        key = trim(key);
        if(!isValidDate(key))
        {
            std::cout << RED << "[Error] data.csv: invalid date format: ";
            std::cout << key << DEFAULT << std::endl;
            continue;
        }
        std::getline(ss, value, ',');
        _rates[key] = std::atof(value.c_str());
    }
    importSuccessMsg();
    // Close file
    fin.close();
}


void BitcoinExchange::convert(std::string filename)
{
    // Open file
    std::ifstream fin(filename.c_str(), std::ios::in);

    // Check if file opened successfully
    if (!fin) { 
        throw BitcoinExchange::OpenFileError();
    }   

     // read CSV line by line
    std::string line;
    std::getline(fin, line); // skip first line
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string date, value;
        float amount;
        std::getline(ss, date, '|');
        date = trim(date);
        if(!isValidDate(date))
        {
            std::cout << RED << "[Error] data.csv: invalid date format: ";
            std::cout << date << DEFAULT << std::endl << std::endl;
            continue;
        }
        std::getline(ss, value, '|');
        amount = std::atof(value.c_str());
        convertAmount(date, amount);
    }   
}

void BitcoinExchange::convertToClosestDate(std::string date, float amount) const
{
    std::map<std::string, float>::const_iterator it;
    std::string closestDate;
    float diff = 0.0f;

    for (it = _rates.begin(); it != _rates.end(); it++)
    {
        diff = strcmp(it->first.c_str(), date.c_str());
        if(diff > 0)
            break;
        else    
            closestDate = it->first;
    }
    if(closestDate.empty())
    {
        std::cout << RED << "[Error] data.csv: no rate for date: <";
        std::cout << date << ">." << DEFAULT << std::endl << std::endl;
        return ;
    }
    else 
    {
        std::cout << YELLOW << "[Warning] data.csv: no rate for date: ";
        std::cout << date << ". Closest date used: ";
        std::cout << closestDate << " = " << amount * it->second << " USD" << DEFAULT << std::endl << std::endl;
    }
}


void BitcoinExchange::convertAmount(std::string date, float amount)
{
    if(_rates.find(date) == _rates.end())
    {
        convertToClosestDate(date, amount);
        return ;
    }
    if(amount < 0)
    {
        std::cout << RED << "[Error] data.csv: negative amount: ";
        std::cout << amount << DEFAULT << std::endl << std::endl;
        return ;
    }
    if(amount > 1000.0f)
    {
        std::cout << RED << "[Error] data.csv: amount too big: ";
        std::cout << amount << DEFAULT << std::endl << std::endl;
        return ;
    }
    std::cout << date << ": " << amount << " BTC = " << amount * _rates[date] << " USD" << std::endl << std::endl;
}


int BitcoinExchange::isValidDate(std::string dateString) const
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

void BitcoinExchange::printRates(void)
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

void BitcoinExchange::importSuccessMsg(void) const
{
    std::cout << GREEN << "[Success] Rates imported sucessfully." << DEFAULT << std::endl << std::endl;
}

void BitcoinExchange::importErrorMsg(void) const
{
    std::cout << RED << "[Error] Could not import rates." << DEFAULT << std::endl << std::endl;
}

void BitcoinExchange::convertSuccessMsg(void) const
{
    std::cout << GREEN << "[Success] Conversion done." << DEFAULT << std::endl << std::endl;
}

// Exceptions ====================================================================

const char* BitcoinExchange::OpenFileError::what() const throw()
{
    return ("Could not open file.");
}