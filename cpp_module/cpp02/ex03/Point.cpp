/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:01:22 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/18 19:33:21 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0){}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y){}

Point::Point(Point &src) : _x(src.getX()), _y(src.getY()){}

Point::~Point(){}

Point &Point::operator=(const Point &src){
	if (this != &src) {
	}
	return (*this);
}

Fixed  Point::getX() const{
	return (_x);
};

Fixed  Point::getY() const{
	return (_y);
};
