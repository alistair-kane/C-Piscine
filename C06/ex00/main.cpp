/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:38:48 by alkane            #+#    #+#             */
/*   Updated: 2022/07/29 17:05:14 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cerrno>
#include <cstdlib>

typedef enum
{
	TYPE_INVALID = 1,
	TYPE_SPECIAL,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE
}	TYPE_T;

static bool	is_special(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf" 
		|| input == "-inf" || input == "+inf" || input == "nan")
		return true;
	return false;
}

static bool	is_int(std::string input)
{
	size_t	i = 0;
	bool	digit = false;

	if (input[0] == '+' || input[0] == '-')
		i++;
	for (;i < input.length(); i++)
	{
		if (std::isdigit(input[i]) == false)
			return false;
		else
			digit = true;
	}
	return digit;
}

static bool	is_float(std::string input)
{
	size_t	i = 0;
	bool	digit = false;
	bool	commaflag = false;

	if (input[0] == '+' || input[0] == '-')
		i++;
	for (; i < input.length(); i++)
	{
		if (std::isdigit(input[i]) == false)
		{
			if (input[i] == '.' && commaflag == false)
				commaflag = true;
			else
				break;
		}
		else
			digit = true;
	}
	if (i == (input.length() - 1) && commaflag == true && digit == true
		&& (input[i] == 'f' || input[i] == 'F'))	
		return true;
	return false;
}

static bool	is_double(std::string input)
{
	size_t	i = 0;
	bool	commaflag = false;

	if (input[0] == '+' || input[0] == '-')
		i++;
	for (; i < input.length(); i++)
	{
		if (std::isdigit(input[i]) == false)
		{
			if (input[i] == '.' && commaflag == false)
				commaflag = true;
			else
				break;
		}
	}
	if (i == input.length())
		return true;
	return false;
}

static bool	is_char(std::string input)
{
	// if before int check is done - dont need to check if digit
	if (input.length() == 1)
		return true;
	return false;
}

static int	get_type(std::string input)
{
	if (is_special(input) == true)
		return (TYPE_SPECIAL);
	if (is_int(input) == true)
		return (TYPE_INT);
	if (is_char(input) == true)
		return (TYPE_CHAR);
	if (is_float(input) == true)
		return (TYPE_FLOAT);
	if (is_double(input) == true)
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

static void	print_char(char c, int type, bool overflow)
{
	std::cout << "char: ";
	if (type == TYPE_INVALID)
		std::cout << "Invalid type" << std::endl;
	else if (type == TYPE_SPECIAL || overflow == true)
		std::cout << "impossible" << std::endl;
	else if (isprint(c) == false)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'"<< c << "'" << std::endl;
}

static void	print_int(int i, int type, bool overflow)
{
	std::cout << "int: ";
	if (type == TYPE_INVALID)
		std::cout << "Invalid type" << std::endl;
	else if (type == TYPE_SPECIAL || overflow == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
}

static void	print_float(float f, int type, bool overflow, std::string input)
{
	std::cout << "float: ";
	if (type == TYPE_INVALID)
		std::cout << "Invalid type" << std::endl;
	else if (overflow == true)
		std::cout << "impossible" << std::endl;
	else if (type == TYPE_SPECIAL)
	{
		if (input == "-inff" || input == "+inff" || input == "nanf")
			std::cout << input << std::endl;
		else
			std::cout << input << "f" << std::endl;
	}
	else
		std::cout << std::setprecision(1) << std::fixed << f << "f" << std::endl;
}

static void	print_double(double d, int type, bool overflow, std::string input)
{
	std::cout << "double: ";
	if (type == TYPE_INVALID)
		std::cout << "Invalid type" << std::endl;
	else if (overflow == true)
		std::cout << "impossible" << std::endl;
	else if (type == TYPE_SPECIAL)
	{
		if (input == "-inf" || input == "+inf" || input == "nan")
			std::cout << input << std::endl;
		else
		{
			input.erase(input.end() - 1, input.end());
			std::cout << input << std::endl;
		}
	}
	else
		std::cout << std::setprecision(1) << std::fixed << d << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please provide 1 argument" << std::endl;
		return 1;
	}
	std::string input = argv[1];

	char	ph_char = ' ';
	int		ph_int = 0;
	float	ph_float = 0.0f;
	double	ph_double = 0.0;

	bool	char_overflow = false;
	bool	int_overflow = false;
	bool	float_overflow = false;
	bool	double_overflow = false;

	int		type = get_type(input);
	switch(type)
	{
		case TYPE_CHAR:
			ph_char = input[0];
			ph_int = static_cast<int>(ph_char);
			ph_float = static_cast<float>(ph_char);
			ph_double = static_cast<double>(ph_char);
			break ;
		case TYPE_INT:
			long int	holder;
			holder = atol(argv[1]);
			if (input.length() > 11 || holder > std::numeric_limits<int>::max() || holder < std::numeric_limits<int>::min())
			{
				int_overflow = true;
				float_overflow = true;
				double_overflow = true;
			}
			if (holder > std::numeric_limits<char>::max() || holder < std::numeric_limits<char>::min())
				char_overflow = true;
			ph_int = atoi(argv[1]);
			ph_char = static_cast<char>(ph_int);
			ph_float = static_cast<float>(ph_int);
			ph_char = static_cast<double>(ph_int);
			break ;
		case TYPE_FLOAT:
			double temp_double;
			temp_double = std::strtod(argv[1], NULL);
			ph_float = static_cast<float>(temp_double);
			if (errno == ERANGE)
			{
				char_overflow = true;
				int_overflow = true;
				float_overflow = true;
			}
			else
			{
				if (input.length() > 11 || temp_double > std::numeric_limits<int>::max() || temp_double < std::numeric_limits<int>::min())
					int_overflow = true;
				if (temp_double > std::numeric_limits<char>::max() || temp_double < std::numeric_limits<char>::min())
					char_overflow = true;
				if (temp_double > std::numeric_limits<float>::max() || temp_double < -std::numeric_limits<float>::max())
					float_overflow = true;
			}
			ph_char = static_cast<char>(ph_float);
			ph_double = static_cast<double>(ph_float);
			ph_int = static_cast<int>(ph_float);
			break ;
		case TYPE_DOUBLE:
			ph_double = std::strtod(argv[1], NULL);
			if (errno == ERANGE)
			{
				char_overflow = true;
				int_overflow = true;
				float_overflow = true;
				double_overflow = true;
				break ;
			}
			if (input.length() > 11 || ph_double > std::numeric_limits<int>::max() || ph_double < std::numeric_limits<int>::min())
				int_overflow = true;
			if (ph_double > std::numeric_limits<char>::max() || ph_double < std::numeric_limits<char>::min())
				char_overflow = true;
			if (ph_double > std::numeric_limits<float>::max() || ph_double < -std::numeric_limits<float>::max())
				float_overflow = true;
			ph_char = static_cast<char>(ph_double);
			ph_float = static_cast<float>(ph_double);
			ph_int = static_cast<int>(ph_double);
			break ;
		case TYPE_SPECIAL:
			break ;
		default:
			std::cout << "Invalid" << std::endl;
	}
	print_char(ph_char, type, char_overflow);
	print_int(ph_int, type, int_overflow);
	print_float(ph_float, type, float_overflow, input);
	print_double(ph_double, type, double_overflow, input);
}
