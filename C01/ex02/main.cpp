/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 01:54:50 by alistair          #+#    #+#             */
/*   Updated: 2022/06/24 02:04:22 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVAR;
	std::string& stringREF = stringVAR;
	
	std::cout << "Memory address of the string variable: " << &stringVAR << std::endl;
	std::cout << "Memory address held by string pointer: " << stringPTR << std::endl;
	std::cout << "Memory address held by string reference: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of the string variable: " << stringVAR << std::endl;
	std::cout << "Value pointed to by string pointer: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by string reference: " << stringREF << std::endl;
	return (0);
}