/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:52:13 by alistair          #+#    #+#             */
/*   Updated: 2023/05/08 12:59:18 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc <= 3) 
    {
        std::cerr << "Error: you need to provide at least two numbers" << std::endl;
        return (1);
    }
    try
    {
        RPN    obj(argv);
    }
    catch (std::exception & err) 
    {
        std::cerr <<  err.what() << std::endl;
    }
    return 0;
} 