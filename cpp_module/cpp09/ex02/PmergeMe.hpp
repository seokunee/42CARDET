/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:56:55 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/28 19:20:23 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#define INT_LIST std::list<int>
#define INT_DEQUE std::deque<int>

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

	// list
	void printList(std::list<int> &list, std::string when);
	void printListUnderFive(std::list<int> &list, std::string when);
	void printlistlist(std::list<INT_LIST> &list);
	void listMerge(std::list<INT_LIST> &list, int left, int mid, int right);
	void listFordJohnsonMergeSort(std::list<INT_LIST> &list, int left, int right);
	void listFordJohnsonInsertSort(std::list<INT_LIST> &list);
	size_t setListMainChainAndPendingElements(std::list<INT_LIST> &list, std::list<int> &mainChain);
	void listFordJohnsonInsertSort(std::list<int> &main, std::list<INT_LIST> &pending, size_t total);
	std::list<int>::iterator listBinarySearch(std::list<int>::iterator first, std::list<int>::iterator last, int value);

	// deque
	void printDeque(std::deque<int> &deque, std::string when);
	void printDequeUnderFive(std::deque<int> &deque, std::string when);
	void printdequedeque(std::deque<INT_DEQUE> &deque);
	void dequeMerge(std::deque<INT_DEQUE> &deque, int left, int mid, int right);
	void dequeFordJohnsonMergeSort(std::deque<INT_DEQUE> &deque, int left, int right);
	void dequeFordJohnsonInsertSort(std::deque<INT_DEQUE> &deque);
	void dequeFordJohnsonInsertSort(std::deque<int> &main, std::deque<INT_DEQUE> &pending, size_t total);
	size_t setDequeMainChainAndPendingElements(std::deque<INT_DEQUE> &deque, std::deque<int> &mainChain);
	std::deque<int>::iterator dequeBinarySearch(std::deque<int>::iterator first, std::deque<int>::iterator last, int value);

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
