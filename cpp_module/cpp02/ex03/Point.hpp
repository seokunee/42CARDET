/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:01:20 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 15:38:04 by seokchoi         ###   ########.fr       */
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
		Point(const float x, const float y);
		Point(Point &src);
		~Point();

		Point	&operator=(const Point &src);
		Fixed  getX() const;
		Fixed  getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
