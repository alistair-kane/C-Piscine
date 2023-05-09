/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:33:13 by alistair          #+#    #+#             */
/*   Updated: 2023/05/09 14:10:45 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
    if (argc <= 3) 
    {
        std::cerr << "Error: you need to provide at least two numbers" << std::endl;
        return (1);
    }
    try 
    {
        for (int i = 2; i < 3000; i++)
            PmergeMe    obj(argv, i);
    }
    catch (std::exception & err) 
    {
        std::cerr <<  err.what() << std::endl;
    }
    return 0;
} 