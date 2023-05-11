/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:18 by alistair          #+#    #+#             */
/*   Updated: 2023/05/10 21:05:24 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe(void)
{
	// std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &copy)
{
	// std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	*this = copy;
}

// Destructor
PmergeMe::~PmergeMe()
{
	// std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

// Operator
PmergeMe & PmergeMe::operator=(const PmergeMe &copy)
{
	// std::cout << "\e[0;36mCopy assignment operator called\e[0m" << std::endl;
	this->_deque = copy._deque;
	this->_list = copy._list;
	this->_begin_time = copy._begin_time;
	return (*this);
}

unsigned long getTimeStamp() 
{
	struct timeval tv;

	gettimeofday(&tv,NULL);	
	return static_cast<unsigned long>(tv.tv_sec) * 1000000 + tv.tv_usec;
}

void	PmergeMe::printTimestamp(std::string container, unsigned long value)
{
	std::cout << "Time to process a range of " << _deque.size() 
		<< " elements with " << container << " : " << value
		<< " μs" << std::endl;
}


void	PmergeMe::printData(unsigned long time)
{
	std::cout << _deque.size() << "," << time << "," << _K << ",";
}


void    PmergeMe::print_list() 
{
    std::list<int>::iterator it;
    for (it = _list.begin(); it != _list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

PmergeMe::PmergeMe(char *argv[])
{
	_begin_time = getTimeStamp();
	for (int i = 1; argv[i] != NULL; i++) 
	{
		long val = std::atol(argv[i]);
		if (val <= 0 || val > INT_MAX)
			throw std::invalid_argument("Value must be >0 and <INT_MAX.");
		_list.push_back(static_cast<int>(val));
		_deque.push_back(static_cast<int>(val));
	}
}

void	PmergeMe::do_sorts(void)
{
	std::cout << "Before:" << std::endl;
	print_list();
	std::cout << std::endl;
	_K = (_deque.size() / 4 > 2) ? (_deque.size() / 4) : 2;
	unsigned long list_timer_start = getTimeStamp();
	unsigned long elapsed = list_timer_start - _begin_time;
	sort_list(0, _list.size() - 1);
	unsigned long list_sort_time = getTimeStamp() - list_timer_start;
	std::cout << "After:" << std::endl;
	print_list();
	unsigned long deque_timer_start = getTimeStamp();
	sort_deque(0, _deque.size() - 1);
	unsigned long deque_sort_time = getTimeStamp() - deque_timer_start;
	printTimestamp("std::list", elapsed + list_sort_time);
	printTimestamp("std::deque", elapsed + deque_sort_time);
	std::cout << std::endl;
}

void	PmergeMe::sort_list(int start_idx, int end_idx)
{
	if (end_idx - start_idx > _K)
	{
		int mid_idx = (start_idx + end_idx) / 2;
		sort_list(start_idx, mid_idx);
		sort_list(mid_idx + 1, end_idx);
		merge_list(start_idx, mid_idx, end_idx);
	}
	else
		insert_list(start_idx, end_idx + 1);
}

void	PmergeMe::merge_list(int start_idx, int mid_idx, int end_idx)
{
	int	n1 = mid_idx - start_idx + 1;
	int n2 = end_idx - mid_idx;
	
	// Create temporary sublists
	std::list<int> LA, RA;

	// Copy data to temporary sublists LA[] and RA[]
	for (int i = 0; i < n1; i++)
		LA.push_back(getValueAtIndex(_list ,start_idx + i));
	for (int j = 0; j < n2; j++)
		RA.push_back(getValueAtIndex(_list, mid_idx + j + 1));

	int RIDX = 0;
	int LIDX = 0;
	
	std::list<int>::iterator	it = _list.begin();
	for (int i = 0; i < start_idx; i++)
		it++;

	for (int i = start_idx; i <= end_idx; i++)
	{
		if (RIDX == n2)
		{
			*it = getValueAtIndex(LA, LIDX);
			LIDX++;
		}
		else if (LIDX == n1)
		{
			*it = getValueAtIndex(RA, RIDX);
			RIDX++;
		}
		else if (getValueAtIndex(RA, RIDX) > getValueAtIndex(LA, LIDX))
		{
			*it =  getValueAtIndex(LA, LIDX);
			LIDX++;
		}
		else
		{
			*it =  getValueAtIndex(RA, RIDX);
			RIDX++;
		}
		it++;
	}
}

void	PmergeMe::insert_list(int start_idx, int mid_idx)
{
	std::list<int>::iterator it = _list.begin();
	for (int i = 0; i < start_idx; i++)
		++it;
	std::list<int>::iterator start_it = it;
	std::list<int>::iterator end_it = _list.begin();
	for (int i = 0; i < mid_idx; i++)
		++end_it;
	while (it != end_it) 
	{
		std::list<int>::iterator insertionPos = start_it;
		while (insertionPos != it && *insertionPos <= *it)
			++insertionPos;
		int tmp = *insertionPos;
		*insertionPos = *it;
		*it = tmp;
		it = insertionPos;
		it++;
	}
}

// function to get value at index in list; it will increment the iterator
// index times to get it to desired position and return its value
int PmergeMe::getValueAtIndex(std::list<int> input, int index)
{
	std::list<int>::iterator it = input.begin();
	for(int i = 0; i < index; i++)
		it++;
	return *it;
}

void	PmergeMe::sort_deque(int start_idx, int end_idx)
{
	if (end_idx - start_idx > _K)
	{
		int mid_idx = (start_idx + end_idx) / 2;
		sort_deque(start_idx, mid_idx);
		sort_deque(mid_idx + 1, end_idx);
		merge_deque(start_idx, mid_idx, end_idx);
	}
	else
		insert_deque(start_idx, end_idx);
}

void	PmergeMe::merge_deque(int start_idx, int mid_idx, int end_idx)
{
	int n1 = mid_idx - start_idx + 1;
	int n2 = end_idx - mid_idx;

	// Create temporary subarrays
	std::deque<int> LA, RA;

	// Copy data to temporary subarrays LA[] and RA[]
	for (int i = 0; i < n1; i++)
		LA.push_back(_deque[start_idx + i]);
	for (int j = 0; j < n2; j++)
		RA.push_back(_deque[mid_idx + j + 1]);

	int RIDX = 0;
	int LIDX = 0;
	for (int i = start_idx; i <= end_idx; i++) {
		if (RIDX == n2) {
			_deque[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			_deque[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			_deque[i] = LA[LIDX];
			LIDX++;
		} else {
			_deque[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void	PmergeMe::insert_deque(int start_idx, int mid_idx)
{
	for (int i = start_idx; i < mid_idx; i++) 
	{
		int tmp = _deque[i + 1];
		int	j = i + 1;
		while (j > start_idx && _deque[j - 1] > tmp)
		{
			_deque[j] = _deque[j - 1];
			j--;
		}
		_deque[j] = tmp;
	}
}
