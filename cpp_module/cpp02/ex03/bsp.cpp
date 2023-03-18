/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:45:03 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/18 19:45:48 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

Fixed getArea(Point const& a, Point const& b, Point const& c) {
  Fixed area = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY());
  if (area < 0)
    area = area * -1;
  return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed area = getArea(a, b, c);
  Fixed area1 = getArea(a, b, point);
  Fixed area2 = getArea(a, c, point);
  Fixed area3 = getArea(b, c, point);
  if ((area != area1 + area2 + area3) || area1 == 0 || area2 == 0 || area3 == 0)
    return false;
  return true;
}
