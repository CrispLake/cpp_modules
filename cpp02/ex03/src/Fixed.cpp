/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:39 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/29 18:14:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <sstream>

Fixed::Fixed() : nb(0) {
}

Fixed::Fixed(const int value) : nb(value << fraction_len) {
}

Fixed::Fixed(const float value) : nb(value * float(1 << fraction_len) + (value >= 0 ? 0.5 : -0.5)) {
}

Fixed::Fixed(const Fixed &x) {
	nb = x.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed &x) {
	if (this == &x)
		return *this;
	nb = x.getRawBits();
	return *this;
}

Fixed::~Fixed() {
}

int	Fixed::getRawBits() const {
	return (nb);
}

void	Fixed::setRawBits(int const raw) {
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

bool	Fixed::operator>(const Fixed &x) const {
	return (nb > x.nb);
}

bool	Fixed::operator>=(const Fixed &x) const {
	return (nb >= x.nb);
}

bool	Fixed::operator<(const Fixed &x) const {
	return (nb < x.nb);
}

bool	Fixed::operator<=(const Fixed &x) const {
	return (nb <= x.nb);
}

bool	Fixed::operator==(const Fixed &x) const {
	return (nb == x.nb);
}

bool	Fixed::operator!=(const Fixed &x) const {
	return (nb != x.nb);
}

Fixed	Fixed::operator+(const Fixed &x) const {
	Fixed temp(*this);
	temp.nb += x.nb;
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &x) const {
	Fixed temp(*this);
	temp.nb -= x.nb;
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &x) const {
	Fixed temp(*this);
	temp.nb = (temp.nb * x.nb) >> fraction_len;
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &x) const {
	Fixed temp(*this);
	temp.nb = (temp.nb << fraction_len) / x.nb;
	return (temp);
}

Fixed&	Fixed::operator++() {
	nb++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	nb++;
	return (temp);
}

Fixed&	Fixed::operator--() {
	nb--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	nb--;
	return (temp);
}

const Fixed&	Fixed::min(Fixed& x, Fixed& y) {
	return (x.nb <= y.nb ? x : y);
}

const Fixed&	Fixed::min(const Fixed& x, const Fixed& y) {
	return (x.nb <= y.nb ? x : y);
}

const Fixed&	Fixed::max(Fixed& x, Fixed& y) {
	return (x.nb >= y.nb ? x : y);
}

const Fixed&	Fixed::max(const Fixed& x, const Fixed& y) {
	return (x.nb >= y.nb ? x : y);
}
