/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/16 15:04:10 by seokchoi         ###   ########.fr       */
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
		::iter(array, static_cast<size_t>(sizeof(array) / sizeof(array[0])), ::print<std::string>);
	if (sizeof(i) > 0)
		::iter(i, static_cast<size_t>(sizeof(i) / sizeof(i[0])), ::print<int>);
	if (sizeof(d) > 0)
		::iter(d, static_cast<size_t>(sizeof(d) / sizeof(d[0])), ::print<double>);
	if (sizeof(c) > 0)
		::iter(c, static_cast<size_t>(sizeof(c) / sizeof(c[0])), ::print<char>);
	return 0;
}