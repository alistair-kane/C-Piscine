/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:25:19 by alkane            #+#    #+#             */
/*   Updated: 2022/09/08 14:14:52 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int int_array[] = {7, 6, 4, 5, 4};
	float float_array[] = {4.5, 3.3, 5.3, 600.3, 49.2};
	std::string string_array[] = {"test", "words", "in", "my", "array"};
	
	iter(int_array, 5, print_element);
	std::cout << std::endl;
	iter(float_array, 5, print_element);
	std::cout << std::endl;
	iter(string_array, 5, print_element);
	
	return 0;
}
