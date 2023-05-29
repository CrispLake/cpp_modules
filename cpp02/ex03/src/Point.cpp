/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:45:02 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/29 18:28:57 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(const float xf, const float yf) : x(xf), y(yf) {
}

Point::Point(const Fixed xf, const Fixed yf) : x(xf), y(yf) {
}

Point::Point(const Point& point) : x(point.x), y(point.y) {
}

Point&	Point::operator=(const Point& point) {
	if (this != &point)
	{
	}
	return (*this);
}

Point::~Point() {
}

Fixed	Point::getX() const {
	return(x);
}

Fixed	Point::getY() const {
	return(y);
}
