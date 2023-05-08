/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:18 by alistair          #+#    #+#             */
/*   Updated: 2023/05/08 14:55:39 by alistair         ###   ########.fr       */
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

// function to get iterator at index in list
std::list<int>::iterator PmergeMe::getIteratorAtIndex(int index)
{
	// create iterator for list
	std::list<int>::iterator it = _list.begin();
	// iterate to the desired index
	for(int i = 0; i < index; i++)
		it++;
	// return iterator at index
	return it;
}

// function to get iterator at index in list
int PmergeMe::getValueAtIndex(std::list<int> input, int index)
{
	// create iterator for list
	std::list<int>::iterator it = input.begin();
	// iterate to the desired index
	for(int i = 0; i < index; i++)
		it++;
	// return value at index
	return *it;
}

std::list<int>	PmergeMe::copy_list(int start_idx, int end_idx)
{
	std::list<int>::iterator it_s = _list.begin();
	// increase iterator to correct position
	for (int i = 0; i < start_idx; i++)
		++it_s;
		
	std::list<int>::iterator it_e = _list.begin();
	// increase iterator to correct position
	for (int i = 0; i < end_idx; i++)
		++it_e;
		
	std::list<int> copied;
	for (std::list<int>::iterator it = it_s; it != it_e; ++it)
		copied.push_back(*it);
	return (copied);
}

// void	PmergeMe::merge_list(int start_idx, int mid_idx, int end_idx)
// {
// 	int	pos1 = mid_idx - start_idx + 1;
// 	int pos2 = end_idx - mid_idx;
// 	std::list<int> left_list = copy_list(start_idx, mid_idx + 1);
// 	std::list<int> right_list = copy_list(mid_idx + 1, end_idx + 1);
// 	int ridx = 0;
// 	int lidx = 0;

// 	std::list<int>::iterator	it = _list.begin();
// 	for (int i = 0; i < start_idx; i++)
// 		it++;

// 	for (int i = start_idx; i < end_idx - start_idx + 1; i++)
// 	{
// 		if (ridx == pos2)
// 		{
// 			*it = getValueAtIndex(left_list, lidx);
// 			lidx++;
// 		}
// 		else if (lidx == pos1)
// 		{
// 			*it = getValueAtIndex(right_list, ridx);
// 			ridx++;
// 		}
// 		else if (getValueAtIndex(right_list, ridx) > getValueAtIndex(left_list, lidx))
// 		{
// 			*it =  getValueAtIndex(left_list, lidx);
// 			lidx++;
// 		}
// 		else
// 		{
// 			*it =  getValueAtIndex(right_list, ridx);
// 			ridx++;
// 		}
// 		it++;
// 	}
// }

// void	PmergeMe::insert_list(int start_idx, int mid_idx)
// {
// 	std::list<int>::iterator it = _list.begin();
// 	// increase iterator to correct position
// 	for (int i = 0; i < start_idx; i++)
// 		++it;

// 	std::list<int>::iterator start_it = it;
// 	std::list<int>::iterator end_it = _list.begin();
// 	// increase iterator to correct position
// 	for (int i = 0; i < mid_idx; i++)
// 		++end_it;

// 	while (it != end_it) 
// 	{
// 		std::list<int>::iterator insertionPos = start_it;

// 		while (insertionPos != it && *insertionPos <= *it)
// 			++insertionPos;
			
// 		int tmp = *insertionPos;
// 		*insertionPos = *it;
// 		*it = tmp;
		
// 		it = insertionPos;
// 		it++;
		
// 		// _list.insert(insertionPos, *it);
// 		// it = _list.erase(it);
// 	}
// }

// void	PmergeMe::sort_list(int start_idx, int end_idx)
// {
// 	if (end_idx - start_idx > _K)
// 	{
// 		int mid_idx = (start_idx + end_idx) / 2;
// 		sort_list(start_idx, mid_idx);
// 		sort_list(mid_idx + 1, end_idx);
// 		merge_list(start_idx, mid_idx, end_idx);
// 	}
// 	else
// 	{
// 		insert_list(start_idx, end_idx);
// 	}
// 	std::cout << "after insert?:\t";
// 	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

void	PmergeMe::merge_deque(int start_idx, int mid_idx, int end_idx)
{
	int	pos1 = mid_idx - start_idx + 1;
	int pos2 = end_idx - mid_idx;
	std::deque<int> left_deque(_deque.begin() + start_idx, _deque.begin() + mid_idx + 1);
	std::deque<int> right_deque(_deque.begin() + mid_idx + 1, _deque.begin() + end_idx + 1);
	int ridx = 0;
	int lidx = 0;

	for (int i = start_idx; i < end_idx - start_idx + 1; i++)
	{
		if (ridx == pos2)
		{
			_deque[i] = left_deque[lidx];
			lidx++;
		}
		else if (lidx == pos1)
		{
			_deque[i] = right_deque[ridx];
			ridx++;
		}
		else if (right_deque[ridx] > left_deque[lidx])
		{
			_deque[i] = left_deque[lidx];
			lidx++;
		}
		else
		{
			_deque[i] = right_deque[ridx];
			ridx++;
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
	std::deque<int> tmpDeque(_deque.begin() + start_idx, _deque.begin() + mid_idx + 1);
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
	{
		insert_deque(start_idx, end_idx);
	}
	// std::cout << "after insert?:\t";
	// for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
}




PmergeMe::PmergeMe(char *argv[])
{
	// double begin = GetTimeStamp();

	for (int i = 1; argv[i] != NULL; i++) 
	{
		long val = std::atol(argv[i]);
		if (val <= 0 || val > INT_MAX)
			throw std::invalid_argument("Value must be >0 and <INT_MAX.");
		_list.push_back(static_cast<int>(val));
		_deque.push_back(static_cast<int>(val));
	}

	// std::cout << "Before:\t";
	// for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	
	
	std::cout << "Before:\t";
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// double elapsed = GetTimeStamp() - begin;
	// std::cout << "Time measured: ";
	// std::cout << std::fixed << std::setprecision(10) << elapsed / 1000 << "μs" << std::endl;
	
	// uint64_t list_begin = micros();
	
	// uint64_t list_sort_time = micros() - list_begin;
	// sort_list(0, _list.size() - 1);
	// std::cout << "After:\t";
	// for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	
	sort_deque(0, _deque.size() - 1);
	std::cout << "After:\t";
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	

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