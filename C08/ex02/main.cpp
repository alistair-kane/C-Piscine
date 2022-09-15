/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:25:19 by alkane            #+#    #+#             */
/*   Updated: 2022/09/15 14:30:59 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: [" << mstack.top() << "]" << std::endl;
	mstack.pop();
	std::cout << "Size after pop [" << mstack.size() << "]" << std::endl;
	mstack.push(3);
	mstack.push(8);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Size after +4 pushed " << mstack.size() << std::endl;
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << *it << std::endl;
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl << "Comparing with list container" << std::endl;
	std::list<int> tlist;
	
	tlist.push_back(5);
	tlist.push_back(17);
	std::cout << "Top: [" << tlist.back() << "]" << std::endl;
	tlist.pop_back();
	std::cout << "Size after pop [" << tlist.size() << "]" << std::endl;
	tlist.push_back(3);
	tlist.push_back(8);
	tlist.push_back(737);
	tlist.push_back(0);
	std::cout << "Size after +4 pushed " << tlist.size() << std::endl;
	
	std::list<int>::iterator it_list = tlist.begin();
	std::list<int>::iterator ite_list = tlist.end();
	
	std::cout << *it_list << std::endl;
	
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	return 0;
}