/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:18 by alistair          #+#    #+#             */
/*   Updated: 2023/05/10 20:49:52 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors
RPN::RPN(void)
{
	// std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
}

RPN::RPN(int argc, char *argv[])
{
	if (argc != 2)
	    throw std::invalid_argument("Please enter just 1 expression");
	if (_calculate(argv) && _data.size() == 1)
    	std::cout << _data.top() << " " << std::endl;
	else
		throw std::invalid_argument("Error: Invalid input");
}

RPN::RPN(const RPN &copy)
{
	// std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	*this = copy;
}

// Destructor
RPN::~RPN()
{
	// std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

// Operators
RPN & RPN::operator=(const RPN &copy)
{
	// std::cout << "\e[0;36mCopy assignment operator called\e[0m" << std::endl;
	this->_data = copy._data;
	return (*this);
}

int	RPN::_top_pop()
{
	if (!_data.empty())
	{
		int val = _data.top();
		_data.pop();
		return (val);
	}
	throw std::invalid_argument("Error: Invalid input (stack_empty)");
}

bool	RPN::_calculate(char *argv[])
{
	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		char c = argv[1][i];
		
		if (c == ' ')
			continue;
		else if (c >= '0' && c <= '9')
			_data.push(c - '0');
		else if(c == '+')
			_data.push(_top_pop() + _top_pop());
		else if(c == '-')
		{
			int num1 = _top_pop();
			int res = _top_pop() - num1;
			_data.push(res);
		}
		else if(c == '*')
			_data.push(_top_pop() * _top_pop());
		else if(c == '/')
		{
			int num1 = _top_pop();
			int res = _top_pop() / num1;
			_data.push(res);
		}
		else
			return false;
	}
	return true;
}
