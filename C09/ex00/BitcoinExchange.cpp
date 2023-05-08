#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
    // populate the map with file
    std::fstream data_file;
    data_file.open(filename, std::ios::in);
    if (data_file.is_open())
    {
        std::string line;
        std::getline(data_file, line);
        while (std::getline(data_file, line))
        {
            std::string date = line.substr(0, line.find(","));
            std::string value = line.substr(line.find(",") + 1);
            database[date] = std::strtod(value.c_str(), NULL);
        }
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	*this = copy;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

// Operators
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	std::cout << "\e[0;36mCopy assignment operator called\e[0m" << std::endl;
	this->database = copy.database;
	return (*this);
}

void BitcoinExchange::printValues(void)
{
    std::map<std::string, double>::iterator itr;
    for(itr = database.begin(); itr != database.end(); ++itr)
        std::cout << itr->first << " " << itr->second << "\n";
}

double	BitcoinExchange::exchangeMultiple(std::string date)
{
    std::map<std::string, double>::iterator it;
    double closest_value = -1;

    for (it = database.begin(); it != database.end(); ++it)
    {
        if (it->first == date)
            return (it->second);
        else if (it->first > date)
            break;
        closest_value = it->second;
    }
    return(closest_value);
}
