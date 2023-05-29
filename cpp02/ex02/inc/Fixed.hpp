/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:07:58 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/29 14:22:02 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
std::ostream&	operator<<(std::ostream& os, const class Fixed& x);

class Fixed {
	private:
		int	nb;
		static const int	fraction_len = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& x);
		Fixed& operator=(const Fixed& x);
		~Fixed();
		int	getRawBits() const ;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int	toInt( void ) const;
		bool	operator>(const Fixed& x) const;
		bool	operator>=(const Fixed& x) const;
		bool	operator<(const Fixed& x) const;
		bool	operator<=(const Fixed& x) const;
		bool	operator==(const Fixed& x) const;
		bool	operator!=(const Fixed& x) const;
		Fixed	operator+(const Fixed& x) const;
		Fixed	operator-(const Fixed& x) const;
		Fixed	operator*(const Fixed& x) const;
		Fixed	operator/(const Fixed& x) const;
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		const static Fixed&	min(Fixed& x, Fixed& y);
		const static Fixed&	min(const Fixed& x, const Fixed& y);
		const static Fixed&	max(Fixed& x, Fixed& y);
		const static Fixed&	max(const Fixed& x, const Fixed& y);
};

#endif
