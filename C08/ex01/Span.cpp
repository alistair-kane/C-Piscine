/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:06:46 by alkane            #+#    #+#             */
/*   Updated: 2022/09/15 13:07:51 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(0) {}

Span::Span(unsigned int n) : _n(n) 
{
	_storage = new std::vector<int>(n);
	if (_storage == NULL)
		throw std::bad_alloc();
	_idx = 0;
}

Span::Span(const Span &copy)
{
	this->_n = 0;
	*this = copy;
}

// Destructor
Span::~Span(void)
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
	// checks if vector is full
	if (_idx == _n)
		throw std::out_of_range("No more space in Span!");
	_storage->at(_idx) = n;
	_idx++;
}

unsigned int	Span::shortestSpan(void)
{
	if (_n < 2)
		throw std::out_of_range("Not enough numbers for shortest Span!");
	std::vector<int> storage_copy = *_storage;
	std::adjacent_difference(storage_copy.begin(), storage_copy.end(), storage_copy.begin());
	for_each(storage_copy.begin(), storage_copy.end(), Span::makePositive);
	return (static_cast<unsigned int>(*std::min_element(storage_copy.begin(), storage_copy.end())));
}

unsigned int	Span::longestSpan(void)
{
	int	min;
	int	max;

	if (_n < 2)
		throw std::out_of_range("Not enough numbers for longest Span!");
	min = *std::min_element(_storage->begin(), _storage->end());
	max = *std::max_element(_storage->begin(), _storage->end());
	return (static_cast<unsigned int>(max - min));
}

void	Span::randomFill()
{
	std::srand(time(NULL));
	std::generate(_storage->begin(), _storage->end(), Span::randomNumberGen);
	// indicates vector is now full
	_idx = _n;
}

int	Span::randomNumberGen(void)
{
	return (std::rand() % INT_MAX);
}

void	Span::makePositive(int &number)
{
	if (number < 0)
		number *= -1;
}