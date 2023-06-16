/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:22:54 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/16 14:57:03 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *array, size_t len, Func &function)
{
	for (size_t i = 0; i < len; i++)
	{
		function(array[i]);
	}
};

template <typename T>
void print(T &src)
{
	std::cout << src << std::endl;
}

#endif
