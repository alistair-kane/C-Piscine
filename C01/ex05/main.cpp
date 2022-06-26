/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:47:47 by alistair          #+#    #+#             */
/*   Updated: 2022/06/26 01:57:29 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl		harl;
	std::string inputs[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	srand(time(NULL)); // random seed
	for (int i = 0; i < 10; i++)
		harl.complain(inputs[rand() % 4]);
}