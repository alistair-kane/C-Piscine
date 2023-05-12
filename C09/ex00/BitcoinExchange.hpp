#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <iomanip>
# include <cstdlib>
# include <sstream>

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange(void);
		BitcoinExchange(const char *filename);
		// Copy (cannonical)
		BitcoinExchange(BitcoinExchange const & copy);
		// Destructor
		~BitcoinExchange(void);
		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &copy);
		
		void	printValues(void);
		double	exchangeMultiple(std::string date);

	private:
		std::map<std::string, double>	database;

};

#endif
