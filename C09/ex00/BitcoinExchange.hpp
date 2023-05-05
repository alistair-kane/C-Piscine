#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange(void);
		BitcoinExchange(std::string filename);
		// Copy (cannonical)
		BitcoinExchange(BitcoinExchange const & copy);
		// Destructor
		~BitcoinExchange(void);
		
		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &copy);
		
		// Getters / Setters
		void	printValues(void);

	private:
		std::map<std::string, double>	database;

};

#endif