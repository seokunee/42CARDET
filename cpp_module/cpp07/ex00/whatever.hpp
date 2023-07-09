/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:22:54 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/09 20:42:12 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &x, T &y)
{
	T tmp;
	tmp = y;
	y = x;
	x = tmp;
}

template <typename T>
T &min(T &x, T &y)
{
	if (x <= y)
		return (x);
	return (y);
}

template <typename T>
T &max(T &x, T &y)
{
	if (x >= y)
		return (x);
	return (y);
}

#endif
