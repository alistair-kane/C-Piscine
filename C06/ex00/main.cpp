/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:38:48 by alkane            #+#    #+#             */
/*   Updated: 2022/07/29 13:57:25 by alkane           ###   ########.fr       */
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
	// if i is last character and its F or f
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
		std::cout << "Not displayable" << std::endl;
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
		std::cout << i << std::endl; //needs quotes?
}

static void	print_float(float f, int type, bool overflow)
{
	std::cout << "float: ";
	if (type == TYPE_INVALID)
		std::cout << "Invalid type" << std::endl;
	else if (overflow == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << "f" << std::endl; //needs quotes?
}

static void	print_double(double d, int type, bool overflow)
{
	std::cout << "double: ";
	if (type == TYPE_INVALID)
		std::cout << "Invalid type" << std::endl;
	else if (overflow == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << std::endl; //needs quotes?
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please provide 1 argument" << std::endl;
		return 1;
	}
	std::string input = argv[1];
	std::string	type_string;

	// ph = placeholder
	char		ph_char = ' ';
	int			ph_int = 0;
	float		ph_float = 0.0f;
	double		ph_double = 0.0;

	int			type = get_type(input);

	long int	holder;

	bool		char_overflow = false;
	bool		int_overflow = false;
	bool		float_overflow = false;
	bool		double_overflow = false;

	switch(type)
	{
		case TYPE_CHAR:
			std::cout << "char" << std::endl;
			ph_char = input[0];
			ph_int = static_cast<int>(ph_char);
			ph_float = static_cast<float>(ph_char);
			ph_double = static_cast<double>(ph_char);
			break ;
		case TYPE_INT:
			std::cout << "char" << std::endl;
		
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
			ph_float = static_cast<float>(std::strtod(argv[1], NULL));
			if (errno == ERANGE)
			{
				char_overflow = true;
				int_overflow = true;
				float_overflow = true;
			}
			holder = static_cast<long>(ph_float);
			if (type_string.length() > 11 || holder > std::numeric_limits<int>::max() || holder < std::numeric_limits<int>::min())
				int_overflow = true;
			if (holder > std::numeric_limits<char>::max() || holder < std::numeric_limits<char>::min())
				char_overflow = true;
			ph_char = static_cast<char>(ph_float);
			ph_float = static_cast<float>(ph_float);
			ph_char = static_cast<double>(ph_float);
			break ;
		case TYPE_DOUBLE:
			ph_double = (std::strtod(argv[1], NULL));
			if (errno == ERANGE)
			{
				char_overflow = true;
				int_overflow = true;
				float_overflow = true;
				double_overflow = true;
				break ;
			}
			holder = static_cast<long>(ph_double);
			if (type_string.length() > 11 || holder > std::numeric_limits<int>::max() || holder < std::numeric_limits<int>::min())
				int_overflow = true;
			if (holder > std::numeric_limits<char>::max() || holder < std::numeric_limits<char>::min())
				char_overflow = true;
			ph_char = static_cast<char>(ph_double);
			ph_float = static_cast<double>(ph_double);
			ph_int = static_cast<int>(ph_double);
			break ;
		default:
			std::cout << "Invalid" << std::endl;
	}
	print_char(ph_char, type, char_overflow);
	print_int(ph_int, type, int_overflow);
	print_float(ph_float, type, float_overflow);
	print_double(ph_float, type, double_overflow);
}
