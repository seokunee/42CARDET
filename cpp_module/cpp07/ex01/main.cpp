/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/16 20:47:52 by seokchoi         ###   ########.fr       */
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

	::iter(array, 3, print<std::string>);
	::iter(i, 5, print<int>);
	::iter(d, 5, print<double>);
	::iter(c, 6, print<char>);
	return 0;
}