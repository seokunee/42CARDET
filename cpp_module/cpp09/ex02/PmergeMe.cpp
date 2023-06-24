/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:56:45 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/24 22:17:08 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

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
		_array.push_back(value);
	}
}

void printArray(std::vector<int> &array)
{
	std::cout << "array = ";
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sort(int ac, char **av)
{
	try
	{
		setArray(ac, av);
		// printArray(_array);
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
}
