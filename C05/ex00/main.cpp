/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:58:50 by alkane            #+#    #+#             */
/*   Updated: 2022/08/01 14:36:19 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Trump("Trump", 4000);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Einstein("Trump", 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat Tony("Tony", 47);
	std::cout << Tony << std::endl;

	Tony.decrementGrade();
	std::cout << Tony.getName() << " after decrement" << std::endl;
	std::cout << Tony << std::endl;

	Tony.incrementGrade();
	std::cout << Tony.getName() << " after increment" << std::endl;
	std::cout << Tony << std::endl;
	
	Bureaucrat Bob("Bob", 150);
	try
	{
		Bob.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat Joe("Joe", 1);
	try
	{
		Joe.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}