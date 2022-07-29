/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:10:44 by alkane            #+#    #+#             */
/*   Updated: 2022/07/29 22:31:19 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate(void)
{
	int r_val = std::rand() % 3;

	if (r_val == 0)
		return new A();
	if (r_val == 1)
		return new B();
	else
		return new C();
}

void	identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	if (a != NULL)
		std::cout << "Object (pointer) is actally of type A" << std::endl;
	B *b = dynamic_cast<B *>(p);
	if (b != NULL)
		std::cout << "Object (pointer) is actally of type B" << std::endl;
	C *c = dynamic_cast<C *>(p);
	if (c != NULL)
		std::cout << "Object (pointer) is actally of type C" << std::endl;
}

void	identify(Base& p)
{
	try 
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "Object (reference) is actally of type A" << std::endl;
	}
	catch (std::exception &bc)
	{}
	try 
	{
		(void) dynamic_cast<B &>(p);
		std::cout << "Object (reference) is actally of type B" << std::endl;
	}
	catch (std::exception &bc)
	{}
	try 
	{
		(void) dynamic_cast<C &>(p);
		std::cout << "Object (reference) is actally of type C" << std::endl;
	}
	catch (std::exception &bc)
	{}
}

int	main(void)
{
	std::srand(std::time(0));

	Base *base = generate();

	identify(base);
	identify(*base);
	delete base;
	return 0;
}
