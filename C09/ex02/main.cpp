/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:33:13 by alistair          #+#    #+#             */
/*   Updated: 2023/05/10 21:05:10 by alistair         ###   ########.fr       */
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
    PmergeMe sort;
    try 
    {
        sort = PmergeMe(argv);
    }
    catch (std::exception & err) 
    {
        std::cerr <<  err.what() << std::endl;
    }
    sort.do_sorts();
    return 0;
}
