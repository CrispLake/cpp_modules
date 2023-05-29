/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:44:56 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/29 18:13:21 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(const float xf, const float yf);
		Point(const Fixed xf, const Fixed yf);
		Point(const Point& point);
		Point& operator=(const Point& point);
		~Point();
		Fixed	getX() const;
		Fixed	getY() const;
};

#endif
