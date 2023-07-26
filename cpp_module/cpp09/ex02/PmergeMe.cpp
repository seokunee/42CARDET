/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:56:45 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/26 19:37:41 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	setArray(ac, av);
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	(void)src;
	return *this;
}

void PmergeMe::checkArgument(std::string str)
{
	size_t j = 0;

	while (str[j] == '+' || str[j] == '-')
		j++;
	for (size_t i = j; i < str.length(); i++)
	{
		if (!(std::isdigit(str[i])) && str[i] != '+')
			throw std::runtime_error("Error");
	}
}

void PmergeMe::setArray(int ac, char **av)
{
	int value;
	for (int i = 1; i < ac; i++)
	{
		checkArgument(av[i]);
		value = std::atoi(av[i]);
		if (value < 0)
			throw std::runtime_error("Error");
		_list.push_back(value);
		_deque.push_back(value);
	}
}

void PmergeMe::start()
{
	std::list<INT_LIST> type_list;
	printContainerUnderFive(_list, "Before");
	clock_t start = clock();
	con_sort(type_list, _list);
	clock_t end = clock();
	printContainerUnderFive(_list, "After");
	// printContainer(_list, "After");
	// std::cout << "list is sorted? : " << std::is_sorted(_list.begin(), _list.end()) << std::endl;
	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << _list.size() << "  elements with std::list : " << elapsedTime << " ms" << std::endl;

	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;

	// printContainerUnderFive(_deque, "Before");
	// printDeque(_deque, "Before");
	std::deque<INT_DEQUE> type_deque;
	start = clock();
	con_sort(type_deque, _deque);
	end = clock();
	// printContainerUnderFive(_deque, "After");
	//  printContainer(_deque, "After");
	// std::cout << "deque is sorted? : " << std::is_sorted(_deque.begin(), _deque.end()) << std::endl;
	elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << _deque.size() << "  elements with std::deque : " << elapsedTime << " ms" << std::endl;
}
