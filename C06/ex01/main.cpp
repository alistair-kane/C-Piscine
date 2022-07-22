/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:08:32 by alkane            #+#    #+#             */
/*   Updated: 2022/07/22 19:20:10 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <stdint.h>

struct  Data
{
	std::string	name;
	float		price;
};

uintptr_t	serialize(Data *ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data    *deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data		stock_item_1;
	Data		*new_item;
	uintptr_t	storage;

	stock_item_1.name = "BurgerKingPotato";
	stock_item_1.price = 4.20;
	
	storage = serialize(&stock_item_1);
	new_item = deserialize(storage);
	
	std::cout << "Name: " << new_item->name << std::endl;
	std::cout << "Price: " << new_item->price << std::endl;
	return 0;
}