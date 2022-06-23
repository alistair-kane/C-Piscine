/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:18:53 by alistair          #+#    #+#             */
/*   Updated: 2022/06/15 18:48:38 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc > 1)
		for (int i = 1; i < argc; i++)
			for (int j = 0; argv[i][j] != '\0'; j++)
				std::cout << (char)(isalnum(argv[i][j]) ? toupper(argv[i][j]) : argv[i][j]);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
	std::cout << std::endl;
	return (0);
}
