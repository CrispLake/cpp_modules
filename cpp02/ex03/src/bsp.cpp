/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:44:35 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/29 18:49:33 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	triangleArea(Point const a, Point const b, Point const c) {
	Point	ab(b.getX() - a.getX(), b.getY() - a.getY());
	Point	ac(c.getX() - a.getX(), c.getY() - a.getY());
	Fixed t(ab.getX() * ac.getY() - ab.getY() * ac.getX());
	return (t / 2 < 0 ? t * -1 : t * 1);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	area(triangleArea(a, b, c));
	Fixed	sum(0);
	sum = sum + triangleArea(a, b, point);
	sum = sum + triangleArea(a, c, point);
	sum = sum + triangleArea(c, b, point);
	if (sum != area)
		return (false);
	return (true);
}
