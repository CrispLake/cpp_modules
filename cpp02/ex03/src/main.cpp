/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:57 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/31 17:29:09 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	print_inside_outside(Point const a, Point const b, Point const c, Point const point) {
	std::cout << "a: " << a.getX() << ", " << a.getY() << "\n";
	std::cout << "b: " << b.getX() << ", " << b.getY() << "\n";
	std::cout << "c: " << c.getX() << ", " << c.getY() << "\n";
	std::cout << "point: " << point.getX() << ", " << point.getY() << "\n";
	std::cout << "point is " << (bsp(a, b, c, point) ? "inside" : "outside") << " the triangle\n";
}

int main() {
	print_inside_outside(Point(3, 1), Point(7, 3), Point(3, 4), Point(5, 3));
	print_inside_outside(Point(3, 1), Point(7, 3), Point(3, 4), Point(3, 3));
	print_inside_outside(Point(3, 1), Point(7, 3), Point(3, 4), Point(2, 8));
	print_inside_outside(Point(3, 1), Point(7, 3), Point(3, 4), Point(3, 1));
	std::cout << "\n";
	print_inside_outside(Point(0.99f, 7.59f), Point(1.75f, 6.59f), Point(4, 10), Point(2, 8));
	print_inside_outside(Point(0.99f, 7.59f), Point(1.75f, 6.59f), Point(4, 10), Point(2.75f, 9));
	print_inside_outside(Point(0.99f, 7.59f), Point(1.75f, 6.59f), Point(4, 10), Point(4, 10));
	print_inside_outside(Point(0.99f, 7.59f), Point(1.75f, 6.59f), Point(4, 10), Point(3, 4));
	return (0);
}
