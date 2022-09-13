/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:25:19 by alkane            #+#    #+#             */
/*   Updated: 2022/09/13 14:49:09 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v_nums;
	v_nums.push_back(1);
	v_nums.push_back(100);
	v_nums.push_back(10);
	v_nums.push_back(70);
	v_nums.push_back(99);
	try
	{
		std::cout << "Matching vector number is: " << *(easyfind(v_nums, 70)) << " <-- this" << std::endl;
	}
	catch (std::out_of_range const&) 
	{
		std::cout << "Int not found" << std::endl;
	};
	
	std::list<int> l_nums;
	for (int i = 0; i < 10; ++i)
	{
		l_nums.push_back(i * 2);
	}
	try
	{
		std::cout << "Matching list number is: " << *(easyfind(l_nums, 18)) << " <-- this" << std::endl;
	}
	catch (std::out_of_range const&) 
	{
		std::cout << "Int not found" << std::endl;
	};
	
	std::deque<int> dq_nums;
	dq_nums.push_back(10);
	dq_nums.push_front(20);
	dq_nums.push_back(30);
	dq_nums.push_front(15);
	try
	{
		std::cout << "Matching deque number is: " << *(easyfind(dq_nums, 20)) << " <-- this" << std::endl;
	}
	catch (std::out_of_range const&) 
	{
		std::cout << "Int not found" << std::endl;
	};
}