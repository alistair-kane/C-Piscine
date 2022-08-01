/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:58:50 by alkane            #+#    #+#             */
/*   Updated: 2022/08/01 13:55:38 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat Tony("Tony", 40);
	std::cout << Tony << std::endl;

	Bureaucrat Bob("Bob", 150);
	std::cout << Bob << std::endl;

	Bureaucrat Joe("Joe", 1);
	std::cout << Joe << std::endl;

	// Invalid form
	Form *City_Deregistration;
	try
	{
		City_Deregistration = new Form("City deregistration", 200, -1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	// Valid form
	Form *City_Registration;
	try
	{
		City_Registration = new Form("City registration", 100, 30);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Signed status: " << (*City_Registration).getSigned() << std::endl;
	std::cout << "Grade needed to be signed: " << (*City_Registration).getSign_grade() << std::endl;
	std::cout << std::endl;

	// try and sign the form with a bureaucrat of "low level"
	try
	{
		Bob.signForm(*City_Registration);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	// try and sign the form with a bureaucrat of "medium level"
	try
	{
		Tony.signForm(*City_Registration);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	delete City_Registration;
	return (0);
}