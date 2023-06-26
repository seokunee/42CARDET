/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:56:45 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/26 19:54:08 by seokchoi         ###   ########.fr       */
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
void printList(std::list<int> &list, std::string when)
{
	std::cout << when << ":" << std::setw(10 - when.length());
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printlistlist(std::list<INT_LIST> &list)
{
	std::cout << "array = [";
	for (std::list<INT_LIST>::iterator i = list.begin(); i != list.end(); ++i)
	{
		std::cout << "[";
		for (INT_LIST::iterator j = (*i).begin(); j != (*i).end(); ++j)
		{
			std::cout << *j << ",";
		}
		std::cout << "],";
	}
	std::cout << "]" << std::endl;
}

void PmergeMe::merge(std::list<INT_LIST> &list, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::list<INT_LIST> leftArr, rightArr;
	std::list<INT_LIST>::iterator it = list.begin();

	std::advance(it, left);
	for (int i = 0; i < n1; ++i)
	{
		leftArr.push_back(*it);
		++it;
	}
	it = list.begin();
	std::advance(it, mid + 1);
	for (int j = 0; j < n2; ++j)
	{
		rightArr.push_back(*it);
		++it;
	}

	int i = 0, j = 0;
	std::list<INT_LIST>::iterator it_l, it_r;
	it_l = leftArr.begin();
	it_r = rightArr.begin();
	it = list.begin();
	std::advance(it, left);
	while (i < n1 && j < n2)
	{
		if (*(*it_l).begin() > *(*it_r).begin())
		{
			*it = *it_l;
			++i;
			++it_l;
		}
		else
		{
			*it = *it_r;
			++j;
			++it_r;
		}
		++it;
	}

	while (i < n1)
	{
		*it = *it_l;
		++i;
		++it_l;
		++it;
	}

	while (j < n2)
	{
		*it = *it_r;
		++j;
		++it_r;
		++it;
	}
}

void PmergeMe::fordJohnsonMergeSort(std::list<INT_LIST> &list, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		fordJohnsonMergeSort(list, left, mid);
		fordJohnsonMergeSort(list, mid + 1, right);

		merge(list, left, mid, right);
	}
}

void PmergeMe::fordJohnsonInsertSort(std::list<INT_LIST> &list)
{
	std::list<INT_LIST>::iterator it = list.begin();

	_list.push_back((*it).back());
	if ((*it).size() == 2)
		_list.push_back((*it).front());

	for (it = list.end(); it != list.begin(); --it)
	{
		if (it == list.end())
			continue;
		if (it == list.begin())
			break;
		if ((*it).size() == 1)
			continue;
		int insertNum = (*it).back();
		std::list<int>::reverse_iterator i;
		for (i = _list.rbegin(); i != _list.rend(); ++i)
		{
			if (*i <= insertNum)
			{
				_list.insert(i.base(), insertNum);
				break;
			}
		}
		if (i == _list.rend())
			_list.push_front(insertNum);
	}
	for (it = list.end(); it != list.begin(); --it)
	{
		if (it == list.end())
			continue;
		if (it == list.begin())
			break;
		int insertNum = (*it).front();
		std::list<int>::reverse_iterator i;
		for (i = _list.rbegin(); i != _list.rend(); ++i)
		{
			if (*i <= insertNum)
			{
				_list.insert(i.base(), insertNum);
				break;
			}
		}
		if (i == _list.rend())
			_list.push_front(insertNum);
	}
}

void PmergeMe::list_sort()
{
	try
	{
		size_t first, second;
		INT_LIST tmp;
		INT_LIST::iterator it = _list.begin();
		std::list<INT_LIST> list_tmp;
		for (size_t i = 0; i < _list.size(); i++) // 두개씩 짝짓고 그 안에 정렬하기
		{
			if (i + 2 < _list.size())
			{
				first = *it++;
				second = *it++;
				if (first < second)
				{
					tmp.push_back(second);
					tmp.push_back(first);
				}
				else
				{
					tmp.push_back(first);
					tmp.push_back(second);
				}
				i++;
			}
			else
				tmp.push_back(*it++);
			list_tmp.push_back(tmp);
			tmp.clear();
		}
		fordJohnsonMergeSort(list_tmp, 0, list_tmp.size() - 1);
		_list.clear();
		// printlistlist(list_tmp);
		fordJohnsonInsertSort(list_tmp);
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
}

void PmergeMe::start()
{
	printList(_list, "Before");

	clock_t start = clock();
	list_sort();
	clock_t end = clock();
	printList(_list, "After");

	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << _list.size() << "  elements with std::[..] : " << elapsedTime << " us" << std::endl;
}

/* Ford-Johnson 알고리즘 순서
 * 1단계 재귀
 * 1. 2개씩 숫자들을 묶는다. (4 2) (5 8) (7 9) (1)
 * 2. 같이 묶인 애들 2개만 sort 해준다. (4 2) (8 5) (9 7) (1)
 * 3. 묶은 애들 중에서 큰 애들을 기준으로 sort를 한번 해준다. => 이때 sort는 어떻게 하지? 버블?
 * (9 7) (8 5) (4 2) (1)
 *
 * 2단계 삽입
 * 1. 오른쪽부터 pend element를 삽입 정렬을 시킨다.
 * 2  이때 Jacobsthal number을 잘 계산해서 해줘야한다.
 * 3.
 *
 *
 * Jacobsthal number
 * 0 1 1 3 5 11 21
 */
