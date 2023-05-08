/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:18 by alistair          #+#    #+#             */
/*   Updated: 2023/05/08 13:48:37 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const std::string RPN::_allowed[5] = {"0", "+", "-", "/", "*"};

// Constructors
RPN::RPN(void)
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
}

RPN::RPN(char *argv[])
{   
	for (int i = 1; argv[i] != NULL; i++) 
	{
        if (std::find(std::begin(_allowed), std::end(_allowed), argv[i]) != std::end(_allowed))
            _data.push_back(argv[i]);
        else
        {
		    long val = std::atol(argv[i]);
		    if (val <= 0 || val > 9)
			    throw std::invalid_argument("Value must be >0 and <INT_MAX.");
        }
	}
}

RPN::RPN(const RPN &copy)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	*this = copy;
}

// Destructor
RPN::~RPN()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

// Operators
RPN & RPN::operator=(const RPN &copy)
{
	std::cout << "\e[0;36mCopy assignment operator called\e[0m" << std::endl;
	this->_data = copy._data;
	return (*this);
}