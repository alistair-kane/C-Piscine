/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:06:46 by alkane            #+#    #+#             */
/*   Updated: 2022/09/14 17:24:32 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(0) {}

Span::Span(const Span &copy)
{
	*this = copy;
	this->_n = copy._n;
}

Span::Span(unsigned int n) : _n(n) 
{
	_storage = new std::vector<int>(n);
	if (_storage == NULL)
		throw std::bad_alloc();
}

// Destructor
Span::~Span()
{
	delete _storage;
}


// Operators
Span & Span::operator=(const Span &assign)
{
	if (this == &assign)
		return (*this);
	if (this->_n > 0)
		delete this->_storage;
	this->_n = assign._n;
	this->_storage = new std::vector<int>(this->_n);
	if (_storage == NULL)
		throw std::bad_alloc();
	for (unsigned int i = 0; i < this->_n; i++)
		this->_storage[i] = assign._storage[i];
	return *this;
}

void	Span::addNumber(int n)
{
	unsigned int i = 0;
	while (_n > 0)
	{
		_storage->insert(i, n);
		_n--;
		i++;
	}
	else
	{
		throw std::out_of_range("No more space in Span!");
	}
}

void	Span::randomFill()
{
	std::srand(time(NULL));
	if (_n > 0)
	{
		std::generate(_storage->begin(), _storage->end(), Span::randomNumberGen);
		_n = 0;
	}
	else
	{
		throw std::out_of_range("No more space in Span!");
	}
}

unsigned int	Span::shortestSpan(void)
{
	int	n = _storage->size();
	int	diff = INT_MAX;

	if (n == 0 || n == 1)
		throw std::out_of_range("Not enough numbers for shortest Span!");
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (abs((*_storage)[i] - (*_storage)[j]) < diff)
				diff = abs((*_storage)[i] - (*_storage)[j]);
	return (diff);
}

unsigned int	Span::longestSpan(void)
{
	int n = _storage->size();
	// std::cout << "N:" << n << std::endl;
	int	diff = 0;

	if (n == 0 || n == 1)
		throw std::out_of_range("Not enough numbers for longest Span!");
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (abs(_storage->at(i) - _storage->at(j)) > diff)
			{
				// std::cout << (*_storage)[i] << std::endl;
				// std::cout << _storage->at(j) << std::endl;
				diff = abs(_storage->at(i) - _storage->at(j));
			}
	return (diff);
}

int	Span::randomNumberGen(void)
{
	return (std::rand() % 100);
}