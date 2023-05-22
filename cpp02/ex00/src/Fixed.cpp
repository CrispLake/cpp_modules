/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:39 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/22 13:59:16 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : nb(0) {
	std::cout << "Default constructor called\n";
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
