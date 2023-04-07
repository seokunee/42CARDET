/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:01:22 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 16:37:25 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0){}
:
Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)){}

Point::Point(Point &src)  _x(src.getX()), _y(src.getY()){}

Point::~Point(){}

Point &Point::operator=(const Point &src){
	return (*this);
}

Fixed  Point::getX() const{
	return (_x);
};

Fixed  Point::getY() const{
	return (_y);
};
