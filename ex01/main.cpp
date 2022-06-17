/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:33:20 by alkane            #+#    #+#             */
/*   Updated: 2022/06/17 18:52:14 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	AmazingPhoneBook;
	std::string	input;

	do
	{
		std::cout << 
			"Please enter one of the following commands: [ADD] [SEARCH] [EXIT]"
				<< std::endl;
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			AmazingPhoneBook.add_entry();
		else if (input.compare("SEARCH") == 0)
			AmazingPhoneBook.search_entry();
		else
			std::cerr << input << " : Invalid input" << std::endl;
	}
	while (input.compare("EXIT") != 0 );
	return (0);
}