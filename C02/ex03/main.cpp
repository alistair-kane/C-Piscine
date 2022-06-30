/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:55:37 by alkane            #+#    #+#             */
/*   Updated: 2022/07/01 00:50:21 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Visualize triangles: https://www.geogebra.org/m/VWN3g9rE

static void	test_point(Point const a, Point const b, Point const c, Point const point)
{
	if (bsp(a, b, c, point) == true)
		std::cout << "Point: " << point << " inside triangle" << std::endl;
	else
		std::cout << "Point: " << point << " not inside triangle" << std::endl;
}

int	main(void)
{
	Point const a(0,0);
	Point const b(2,6);
	Point const c(8,2);

	Point const point1(2,2);
	test_point(a, b, c, point1);
	Point const point2(2,5);
	test_point(a, b, c, point2);
	Point const point3(4,4);
	test_point(a, b, c, point3);
	Point const point4(0,0);
	test_point(a, b, c, point4);
	return(0);
}