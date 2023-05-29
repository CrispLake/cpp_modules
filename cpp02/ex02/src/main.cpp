/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:57 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/29 14:02:36 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n\n";
	Fixed x(3.6f);
	Fixed y(7);
	const Fixed xC(3.6f);
	const Fixed yC(7);
	std::cout << x << " > " << y << " = " << (x > y ? "true" : "false") << '\n';
	std::cout << x << " >= " << y << " = " << (x >= y ? "true" : "false") << '\n';
	std::cout << x << " < " << y << " = " << (x < y ? "true" : "false") << '\n';
	std::cout << x << " <= " << y << " = " << (x <= y ? "true" : "false") << '\n';
	std::cout << x << " == " << y << " = " << (x == y ? "true" : "false") << '\n';
	std::cout << x << " != " << y << " = " << (x != y ? "true" : "false") << '\n';
	std::cout << x << " + " << y << " = " << (x + y) << '\n';
	std::cout << x << " - " << y << " = " << (x - y) << '\n';
	std::cout << x << " * " << y << " = " << (x * y) << '\n';
	std::cout << x << " / " << y << " = " << (x / y) << '\n';
	std::cout << "min: " << Fixed::min(x, xC) << "\n";
	std::cout << "min: " << Fixed::min(xC, yC) << "\n";
	std::cout << "max: " << Fixed::max(x, y) << "\n";
	std::cout << "max: " << Fixed::max(xC, yC) << "\n";
	std::cout << "\n\n";
	std::cout << x << " > " << x << " = " << (x > x ? "true" : "false") << '\n';
	std::cout << x << " >= " << x << " = " << (x >= x ? "true" : "false") << '\n';
	std::cout << x << " < " << x << " = " << (x < x ? "true" : "false") << '\n';
	std::cout << x << " <= " << x << " = " << (x <= x ? "true" : "false") << '\n';
	std::cout << x << " == " << x << " = " << (x == x ? "true" : "false") << '\n';
	std::cout << x << " != " << x << " = " << (x != x ? "true" : "false") << '\n';
	return 0;
}
