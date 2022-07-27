/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:10:44 by alkane            #+#    #+#             */
/*   Updated: 2022/07/27 18:05:25 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate(void)
{
	Base *pointer = NULL;

	int r_val = std::rand() % 3;
	if (r_val == 0)
	{
		std::cout << "A" << std::endl;
		pointer = new A();
	}
	else if (r_val == 1)
	{
		std::cout << "B" << std::endl;
		pointer = new B();
	}
	else
	{
		std::cout << "C" << std::endl;
		pointer = new C();
	}
	return pointer;
}

int	main(void)
{
	std::srand(std::time(0));
	
	for (int i = 0; i < 20; i++)
	{
		Base *base = generate();
		delete base;
	}
	return 0;
}
