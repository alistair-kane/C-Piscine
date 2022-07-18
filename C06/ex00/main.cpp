/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:38:48 by alkane            #+#    #+#             */
/*   Updated: 2022/07/18 21:06:31 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

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
	// if before int check dont need to check if digit
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

static char	convert_char(std::string input)
{
	return input[0];
}

static int	convert_int(std::string input, const char **error)
{
	int	value;

	try
	{
		value = std::stoi(input);
	}
	catch (std::exception &e)
	{
		*error = e.what();
	}
	return (value);
}

static float	convert_float(std::string input, const char **error)
{
	float	value;

	try
	{
		value = std::stof(input);
	}
	catch (std::exception &e)
	{
		*error = e.what();
	}
	return (value);
}

static double	convert_double(std::string input, const char **error)
{
	double	value;

	try
	{
		value = std::stod(input);
	}
	catch (std::exception &e)
	{
		*error = e.what();
	}
	return (value);
}

static void	print_char(char c, int i, float f, double d, int type, const char *error)
{
	char	casted;

	if (type == TYPE_CHAR)
		casted = c;
	else if (type == TYPE_INT)
		casted = static_cast<char>(i);
	else if (type == TYPE_FLOAT)
		casted = static_cast<char>(f);
	else if (type == TYPE_DOUBLE)
		casted = static_cast<char>(d);
	if (error)
		std::cout << "char: " << error << std::endl;
	else if (type == TYPE_SPECIAL)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(casted) == true)
		std::cout << "char: " << casted << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void	print_int(char c, int i, float f, double d, int type, const char *error)
{
	int	casted;

	if (type == TYPE_CHAR)
		casted = static_cast<int>(c);
	else if (type == TYPE_INT)
		casted = i;
	else if (type == TYPE_FLOAT)
		casted = static_cast<int>(f);
	else if (type == TYPE_DOUBLE)
		casted = static_cast<int>(d);
	if (error)
		std::cout << "int: " << error << std::endl;
	else if (type == TYPE_SPECIAL)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << casted << std::endl;
}

static void	print_float(char c, int i, float f, double d, int type, const char *error)
{
	float	casted;

	if (type == TYPE_CHAR)
		casted = static_cast<float>(c);
	else if (type == TYPE_INT)
		casted = static_cast<float>(i);
	else if (type == TYPE_FLOAT)
		casted = f;
	else if (type == TYPE_DOUBLE)
		casted = static_cast<float>(d);
	if (error)
		std::cout << "float:" << error << std::endl;
	else if (type == TYPE_SPECIAL)
	// add nan inf etc
		std::cout << "!!!!" << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << casted << "f" << std::endl;
}

static void	print_double(char c, int i, float f, double d, int type, const char *error)
{
	double	casted;

	if (type == TYPE_CHAR)
		casted = static_cast<double>(c);
	else if (type == TYPE_INT)
		casted = static_cast<double>(i);
	else if (type == TYPE_FLOAT)
		casted = static_cast<float>(f);
	else if (type == TYPE_DOUBLE)
		casted = d;
	if (error)
		std::cout << "double:" << error << std::endl;
	else if (type == TYPE_SPECIAL)
	// add nan inf etc
		std::cout << "!!!!" << std::endl;
	else
		std::cout << "double:" << std::setprecision(1) << std::fixed << casted << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please provide 1 argument" << std::endl;
		return 1;
	}

	// type of cast?
	std::string input = argv[1];
	
	int type = get_type(input);
	
	const char	*error;

	char		ph_char = 0;
	int			ph_int = 0;
	float		ph_float = 0;
	double		ph_double = 0;

	switch(type)
	{
		case TYPE_CHAR:
			ph_char = convert_char(input);
			break ;
		case TYPE_INT:
			ph_int = convert_int(input, &error);
			break ;
		case TYPE_FLOAT:
			ph_float = convert_float(input, &error);
			break ;
		case TYPE_DOUBLE:
			ph_double = convert_double(input, &error);
			break ;
		default:
			std::cout << "Invalid" << std::endl;
	}

	print_char(ph_char, ph_int, ph_float, ph_double, type, error);
	print_int(ph_char, ph_int, ph_float, ph_double, type, error);
	print_float(ph_char, ph_int, ph_float, ph_double, type, error);
	print_double(ph_char, ph_int, ph_float, ph_double, type, error);
	

	// find what type it is
	
	// if len is greater than 1 and the second char is not an int, invalid

	// go through string, + or - ?
	// go through string, if no '.','f' and ints then its int
}
