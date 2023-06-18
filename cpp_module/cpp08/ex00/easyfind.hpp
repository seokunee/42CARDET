/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:55:46 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/18 17:18:34 by seokchoi         ###   ########.fr       */
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
	if (!std::is_same<typename T::value_type, int>::value)
		throw std::runtime_error("value type is not Int!");
	typename T::iterator it = std::find(con.begin(), con.end(), val);
	if (it == con.end())
		throw std::invalid_argument("There is not in this container");
	return (it);
};

#endif