/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:57 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/29 18:51:23 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	Point	a(4, 5.5f);
	Point	b(4, 2);
	Point	c(1, 5);
	Point	point(4, 5);
	std::cout << "a: " << a.getX() << ", " << a.getY() << "\n";
	std::cout << "b: " << b.getX() << ", " << b.getY() << "\n";
	std::cout << "c: " << c.getX() << ", " << c.getY() << "\n";
	std::cout << "point: " << point.getX() << ", " << point.getY() << "\n";
	std::cout << "point is " << (bsp(a, b, c, point) ? "inside" : "outside") << " the triangle\n";
	return (0);
}
