/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:25:19 by alkane            #+#    #+#             */
/*   Updated: 2023/05/04 15:16:56 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool in_range(long value, long min, long max)
{
	if (value >= min && value <= max)
		return true;
	return false;
}

long check_year(std::string input)
{
	const char *holder = input.c_str();
	long year = atol(holder);
	if (in_range(year, 2009, 2023) == true)
		return year;
	return -1;
}

long check_month(std::string input)
{
	const char *holder = input.c_str();
	long month = atol(holder);
	if (in_range(month, 1, 12) == true)
		return month;
	return -1;
}

long check_day(std::string input)
{
	const char *holder = input.c_str();
	long day = atol(holder);
	if (in_range(day, 1, 31) == true)
		return day;
	return -1;
}

bool date_valid(std::string s_year, std::string s_month, std::string s_day)
{
	long l_year = check_year(s_year);
	long l_month = check_month(s_month);
	long l_day = check_day(s_day);

	if (l_year < 0 || l_month < 0 || l_day < 0)
		return false;

    long entryDate = (l_year * 10000) + (l_month * 100) + l_day;
    long startDate = 20090102;
    long endDate = 20220329;

    if (entryDate >= startDate && entryDate <= endDate)
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
	BitcoinExchange btc = BitcoinExchange("shorter.csv");
	// send data.csv into bitcoinexchange constructor for parsing (method) into container

	// btc.printValues();
	
	// check argc
	if (argc != 2)
	{
		std::cerr << "Invalid amount of arguments passed [" << argc << "]" << std::endl; 
	}

	// check file open, handle exceptions
	std::ifstream data(argv[1]);
	if (!data.is_open())
	{
		std::exit(EXIT_FAILURE);
	}
    std::string line;
	// skip first line
    std::getline(data, line);
	// getline

    while(std::getline(data, line))
	{
        std::istringstream	dateStream(line.substr(0, line.find("|")));
		int year, month, day;
		char del1;
		char del2;

		dateStream >> year >> del1 >> month >> del2 >> day;

		std::cout << year << ' ' << month << ' ' << day << std::endl;
		std::cout << del1 << ' ' << del2 << "$" << std::endl;
		
		// std::string year = line.substr(0, line.find("-"));
        // std::string month = line.substr(line.find("-") + 1, line.find("-") - 2);
		// try
		// {
		// 	line = line.substr(8);
		// }
		// catch(std::out_of_range&)
		// {
		// 	std::cerr << "Error: bad input" << std::endl;
		// 	std::exit(EXIT_FAILURE);
		// }
		// std::string day = line.substr(0, 2);

		// if (date_valid(year, month, day) == true)
		// {
		// 	std::cout << year << "-" << month << "-" << day 
		// 		<< " => " << std::endl;		
		// }
		// else
		// 	std::cout << "Error: bad input => "
		// 		<< year << "-" << month << "-" << day << std::endl;
	}
		// check each line for:
			// valid date
				// greater than btc inauguration (year greater than, day greater month)
				// YYYY-MM-DD dash seperated format > if valid store in date_string
				// pipe symbol
				// value > 0 && < MAXINT > if valid store in value_string
	
			// valid date and value passed to bitcoinexchange class member lookup member function
	return 0;
}
