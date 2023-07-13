/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:55:46 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/14 00:03:14 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>
#include <stack>
#include <queue>

template <typename T>
typename T::iterator easyfind(T &con, int val)
{
	typename T::iterator it = std::find(con.begin(), con.end(), val);
	if (it == con.end())
		throw std::invalid_argument("There is not in this container");
	return (it);
};

#endif