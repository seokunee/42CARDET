/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:03:28 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/21 15:57:11 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point a(0, 0);
    Point b(20, 0);
    Point c(10, 30);
    Point in(5, 1);
    Point out(30, 50);
    Point on(10, 0);

    std::cout << "check in point :" <<bsp(a, b, c, in) << std::endl;
    std::cout << "check out point :" <<bsp(a, b, c, out) << std::endl;
    std::cout << "check on point :" <<bsp(a, b, c, on) << std::endl;

	return 0;
}
