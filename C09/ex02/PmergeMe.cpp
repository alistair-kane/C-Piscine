/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:18 by alistair          #+#    #+#             */
/*   Updated: 2023/05/07 19:50:13 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe(void)
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
}

double GetTimeStamp() {
    struct timeval tv;
    double time;
    gettimeofday(&tv,NULL);
    time = tv.tv_sec + tv.tv_usec *1e-6;
    return time;
}

PmergeMe::merge_insertion_sort()

PmergeMe::PmergeMe(char *argv[])
{
    double begin = GetTimeStamp();

    for (int i = 1; argv[i] != NULL; i++) 
    {
        long val = std::atol(argv[i]);
        if (val <= 0 || val > INT_MAX)
            throw std::invalid_argument("Value must be >0 and <INT_MAX.");
        _list.push_back(static_cast<int>(val));
        _deque.push_back(static_cast<int>(val));
    }

    std::cout << "Before:\t";
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    double elapsed = GetTimeStamp() - begin;
    std::cout << "Time measured: ";
    std::cout << std::fixed << std::setprecision(10) << elapsed / 1000 << "μs" << std::endl;
    
    // uint64_t list_begin = micros();
    
    // uint64_t list_sort_time = micros() - list_begin;



    // uint64_t deque_begin = micros();
    
    // uint64_t deque_input_time = micros() - deque_begin;

}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	*this = copy;
}

// Destructor
PmergeMe::~PmergeMe()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

// Operators
PmergeMe & PmergeMe::operator=(const PmergeMe &copy)
{
	std::cout << "\e[0;36mCopy assignment operator called\e[0m" << std::endl;
	this->_deque = copy._deque;
	this->_list = copy._list;
	return (*this);
}