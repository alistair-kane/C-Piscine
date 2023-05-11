/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:25:19 by alkane            #+#    #+#             */
/*   Updated: 2023/05/10 20:51:52 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void print_ymd(long year, long month, long day)
{
	std::cout << year << "-";
	std::cout << std::setfill('0') << std::setw(2) << month << "-";
	std::cout << std::setfill('0') << std::setw(2) << day;
}

bool check_range(long value, long min, long max)
{
	if (value >= min && value <= max)
		return true;
	return false;
}

bool date_valid(long year, long month, long day)
{
	if (!check_range(year, 2009, 9999) || !check_range(month, 1, 12) || !check_range(day, 1, 31))
	{
        std::cout << "Error: date out of range => ";
		return false;
	}
    if (year == 2009 && month == 1 && day == 1)
	{
        std::cout << "Error: bitcoin doesn't exist yet => ";
		return false;
	}

    time_t	now = time(0);
    tm		*nowTm = localtime(&now);
    int		nowYear = nowTm->tm_year + 1900;
    int		nowMonth = nowTm->tm_mon + 1;
    int		nowDay = nowTm->tm_mday;
    // std::cout << "Today is: " << nowYear << "-" << nowMonth << "-" << nowDay << std::endl;
    if (year > nowYear)
	{
        std::cout << "Error: date from the future => ";
		return false;
	}
    else if (year == nowYear && (month > nowMonth || (month == nowMonth && day > nowDay)))
	{
        std::cout << "Error: date from the future => ";
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	BitcoinExchange btce = BitcoinExchange("data.csv");

	if (argc != 2)
	{
		std::cerr << "Invalid amount of arguments passed [" << argc << "]" << std::endl; 
		std::exit(EXIT_FAILURE);
	}
	std::ifstream data(argv[1]);
	if (!data.is_open())
		std::exit(EXIT_FAILURE);
    std::string line;

    std::getline(data, line);
    while (std::getline(data, line))
	{
		size_t pos1 = line.find("-");
		size_t pos2 = line.find("-", pos1 + 2);
		size_t pos3 = line.find(" | ", pos2 + 2);

		if (pos1 != 4 || pos2 != 7 || pos3 != 10)
		{
			std::cerr << "Error: invalid input" << std::endl;
			continue;
		}
        std::string datestring = line.substr(0, line.find(" |"));
		long year, month, day;
		char del1, del2;
		
		std::istringstream	dateStream(datestring);
		dateStream >> year >> del1 >> month >> del2 >> day;
		if (date_valid(year, month, day) == true)
		{
			double value = std::strtod(line.substr(pos3 + 3).c_str(), NULL);
			if (value < 0.0)
			{
				std::cout << "Error: not a positive number" << std::endl;
				continue;
			} 
			if (value > 1000.0)
			{
				std::cout << "Error: too large a number" << std::endl;
				continue;
			}
			print_ymd(year, month, day);
			std::cout << " => " << value << " = ";
			std::cout << std::fixed << std::setprecision(2) 
				<< value * btce.exchangeMultiple(datestring);
		}
		else
			print_ymd(year, month, day);
		std::cout << std::endl;
	}
	return 0;
}

// check each line for:
	// valid date
		// greater than btc inauguration (year greater than, day greater month)
		// YYYY-MM-DD dash seperated format > if valid store in date_string
		// pipe symbol
		// value > 0 && < 1000 > if valid store in value_string

	// valid date and value passed to bitcoinexchange class member lookup member function
