/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:01:20 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/18 17:51:48 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(Fixed x, Fixed y);
		Point(Point &src);
		~Point();

		Point	&operator=(const Point &src);
		Fixed  getX() const;
		Fixed  getY() const;
};

#endif