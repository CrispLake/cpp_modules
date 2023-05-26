/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:39 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/26 19:07:42 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>
#include <ostream>
#include <sstream>

Fixed::Fixed() : nb(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) : nb(value << fraction_len) {
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) : nb(value * float(1 << fraction_len) + (value >= 0 ? 0.5 : -0.5)) {
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &x) {
	std::cout << "Copy constructor called\n";
	nb = x.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &x) {
	std::cout << "Copy assignment constructor called\n";
	if (this == &x)
		return *this;
	nb = x.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return (nb);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	nb = raw;
}

float	Fixed::toFloat( void ) const {
	return (float(nb) / float(1 << fraction_len));
}

int	Fixed::toInt( void ) const {
	return (nb >> fraction_len);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& x) {
	os << x.toFloat();
	return (os);
}
