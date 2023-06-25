/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:56:55 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/25 21:00:21 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#define INT_LIST std::list<int>

#include <iostream>
#include <vector>
#include <list>
#include <deque>

class PmergeMe
{
private:
	std::list<int> _list;
	std::deque<int> _deque;
	void setArray(int ac, char **av);
	void checkArgument(std::string str);
	PmergeMe();

public:
	PmergeMe(int ac, char **av);
	~PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	void sort();
};

#endif
