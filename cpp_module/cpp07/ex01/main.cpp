/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/09 20:29:08 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::string array[3] = {
		"hello",
		"seokchoi",
		"yaya"};
	int i[5] = {0, 1, 2, 3, 4};
	double d[5] = {0.0, 1.1, 2.2, 3.3, 4.4};
	char c[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

	if (sizeof(array) > 0)
		::iter(array, sizeof(array) / sizeof(array[0]), ::print);
	if (sizeof(i) > 0)
		::iter(i, sizeof(i) / sizeof(i[0]), ::print);
	if (sizeof(d) > 0)
		::iter(d, sizeof(d) / sizeof(d[0]), ::print);
	if (sizeof(c) > 0)
		::iter(c, sizeof(c) / sizeof(c[0]), ::print);
	return 0;
}