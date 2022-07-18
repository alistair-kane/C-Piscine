/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:05:39 by alistair          #+#    #+#             */
/*   Updated: 2022/07/15 14:34:57 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Source: https://blackpawn.com/texts/pointinpoly/

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	cx_ax(c.getX() - a.getX());
	Fixed	cy_ay(c.getY() - a.getY());
	Fixed	bx_ax(b.getX() - a.getX());
	Fixed	by_ay(b.getY() - a.getY());
	Fixed	w1((a.getX() * cy_ay.toFloat() + (point.getY() - a.getY()) * cx_ax.toFloat() - point.getX() * cy_ay.toFloat()) /
		(by_ay.toFloat() * cx_ax.toFloat() - bx_ax.toFloat() * cy_ay.toFloat()));
	Fixed	w2((point.getY() - a.getY() - w1.toFloat() * by_ay.toFloat()) / cy_ay.toFloat());
	return (w1 > 0 && w2 > 0 && (w1 + w2) <= 1);
}