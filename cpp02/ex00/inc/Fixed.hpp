/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:07:58 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/22 14:00:50 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int	nb;
		static const int	fraction_len = 8;
	public:
		Fixed();
		Fixed(const Fixed& x);
		Fixed& operator=(const Fixed& x);
		~Fixed();
		int	getRawBits() const ;
		void	setRawBits(int const raw);
};

#endif
