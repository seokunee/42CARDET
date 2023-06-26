/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:56:55 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/26 19:37:15 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#define INT_LIST std::list<int>

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	std::list<int> _list;
	std::deque<int> _deque;
	void setArray(int ac, char **av);
	void checkArgument(std::string str);
	void printlistlist(std::list<INT_LIST> &list);
	void merge(std::list<INT_LIST> &list, int left, int mid, int right);
	void fordJohnsonMergeSort(std::list<INT_LIST> &list, int left, int right);
	void fordJohnsonInsertSort(std::list<INT_LIST> &list);

	PmergeMe();

public:
	PmergeMe(int ac, char **av);
	~PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	void start();
	void list_sort();
	void deque_sort();
};

#endif
