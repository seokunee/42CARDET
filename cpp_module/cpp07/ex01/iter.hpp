/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:22:54 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/09 20:28:58 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(const T *array, const size_t len, void (*func)(const T &))
{
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
};

template <typename T>
void print(T &src)
{
	std::cout << src << std::endl;
}

#endif
