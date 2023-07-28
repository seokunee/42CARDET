/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:56:45 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/28 19:30:21 by seokchoi         ###   ########.fr       */
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

void PmergeMe::printList(std::list<int> &list, std::string when)
{
	std::cout << when << ":" << std::setw(10 - when.length());
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printListUnderFive(std::list<int> &list, std::string when)
{
	bool stop = false;
	int count = 0;
	std::cout << when << ":" << std::setw(10 - when.length());
	if (list.size() > 5)
		stop = true;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		count++;
		if (stop && count == 5)
		{
			std::cout << "[...]";
			break;
		}
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

void PmergeMe::listMerge(std::list<INT_LIST> &list, int left, int mid, int right)
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
		if (*(*it_l).begin() < *(*it_r).begin())
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

void PmergeMe::listFordJohnsonMergeSort(std::list<INT_LIST> &list, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		listFordJohnsonMergeSort(list, left, mid);
		listFordJohnsonMergeSort(list, mid + 1, right);

		listMerge(list, left, mid, right);
	}
}

int getSecondValueOfListInt(std::list<int>::iterator it)
{
	std::advance(it, 1);
	return *it;
}

std::list<int>::iterator PmergeMe::listBinarySearch(std::list<int>::iterator first, std::list<int>::iterator last, int value)
{
	if (first == last)
		return last;

	std::list<int>::iterator mid = first;
	std::advance(mid, std::distance(first, last) / 2);

	if (*mid == value)
		return mid;
	else if (*mid < value)
	{
		std::advance(mid, 1);
		return listBinarySearch(mid, last, value);
	}
	else
		return listBinarySearch(first, mid, value);
}

void PmergeMe::listFordJohnsonInsertSort(std::list<int> &main, std::list<INT_LIST> &pending, size_t total)
{
	size_t j0 = 1;
	size_t j1 = 1;
	size_t jn = 3;
	std::list<int>::iterator i;
	std::list<INT_LIST>::iterator it = pending.begin();
		std::list<INT_LIST>::iterator cmp;

	std::list<int>::iterator mi;
	size_t pendingLen = pending.size();
	std::list<int>::iterator j;
	if ((*it).size() == 2)
	{
		j = (*it).begin();
		std::advance(j, 1);
		main.insert(main.begin(), *j);
		total--;
	}
	while (total > 0)
	{
		jn = j1 + 2 * j0;
		if (jn > pendingLen)
			jn = pendingLen;
		it = pending.begin();
		std::advance(it, jn - 1);
		cmp = pending.begin();
		std::advance(cmp, j1 - 1);
		while (it != cmp)
		{
			if ((*it).size() != 2)
			{
				--it;
				continue;
			}
			j = (*it).begin();
			mi = listBinarySearch((main).begin(), (main).end(), *j);
			std::advance(j, 1);
			mi = listBinarySearch(main.begin(), mi, *j);
			// mi = listBinarySearch(main.begin(), (main).end(), *j);

			main.insert(mi, *j);
			total--;
			--it;
		}
		j0 = j1;
		j1 = jn;
	}
}

size_t PmergeMe::setListMainChainAndPendingElements(std::list<INT_LIST> &list, std::list<int> &mainChain)
{
	size_t count = 0;
	for (std::list<INT_LIST>::iterator it = list.begin(); it != list.end(); ++it)
	{
		std::list<int>::iterator i = (*it).begin();
		mainChain.push_back(*i);
		if ((*it).size() == 2)
			count++;
	}
	return count;
}

void PmergeMe::list_sort()
{
	size_t first, second;
	std::list<int> tmp;
	std::list<int>::iterator it = _list.begin();
	std::list<INT_LIST> list_tmp;
	if (_list.size() == 1)
		return;
	if (_list.size() == 2)
	{
		first = *it;
		std::advance(it, 1);
		second = *it;
		if (first > second)
		{
			*_list.begin() = second;
			*it = first;
		}
		return;
	}
	for (size_t i = 0; i < _list.size(); i++)
	{
		if (i + 2 <= _list.size())
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
	listFordJohnsonMergeSort(list_tmp, 0, list_tmp.size() - 1);
	_list.clear();
	size_t pendingSize = setListMainChainAndPendingElements(list_tmp, _list);
	listFordJohnsonInsertSort(_list, list_tmp, pendingSize);
}

// --- ---  ---  ---  ---  ---  ---  ---  ---  ---  ---  ---  ---

void PmergeMe::printDeque(std::deque<int> &deque, std::string when)
{
	std::cout << when << ":" << std::setw(10 - when.length());
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDequeUnderFive(std::deque<int> &deque, std::string when)
{
	bool stop = false;
	int count = 0;
	std::cout << when << ":" << std::setw(10 - when.length());
	if (deque.size() > 5)
		stop = true;
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
	{
		count++;
		if (stop && count == 5)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printdequedeque(std::deque<INT_DEQUE> &deque)
{
	std::cout << "array = [";
	for (std::deque<INT_DEQUE>::iterator i = deque.begin(); i != deque.end(); ++i)
	{
		std::cout << "[";
		for (INT_DEQUE::iterator j = (*i).begin(); j != (*i).end(); ++j)
		{
			std::cout << *j << ",";
		}
		std::cout << "],";
	}
	std::cout << "]" << std::endl;
}

void PmergeMe::dequeMerge(std::deque<INT_DEQUE> &deque, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<INT_DEQUE> leftArr, rightArr;
	std::deque<INT_DEQUE>::iterator it = deque.begin();

	std::advance(it, left);
	for (int i = 0; i < n1; ++i)
	{
		leftArr.push_back(*it);
		++it;
	}
	it = deque.begin();
	std::advance(it, mid + 1);
	for (int j = 0; j < n2; ++j)
	{
		rightArr.push_back(*it);
		++it;
	}

	int i = 0, j = 0;
	std::deque<INT_DEQUE>::iterator it_l, it_r;
	it_l = leftArr.begin();
	it_r = rightArr.begin();
	it = deque.begin();
	std::advance(it, left);
	while (i < n1 && j < n2)
	{
		if (*(*it_l).begin() < *(*it_r).begin())
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

void PmergeMe::dequeFordJohnsonMergeSort(std::deque<INT_DEQUE> &deque, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		dequeFordJohnsonMergeSort(deque, left, mid);
		dequeFordJohnsonMergeSort(deque, mid + 1, right);

		dequeMerge(deque, left, mid, right);
	}
}

std::deque<int>::iterator PmergeMe::dequeBinarySearch(std::deque<int>::iterator first, std::deque<int>::iterator last, int value)
{
	if (first == last)
		return last;

	std::deque<int>::iterator mid = first;
	std::advance(mid, std::distance(first, last) / 2);

	if (*mid == value)
		return mid;
	else if (*mid < value)
	{
		std::advance(mid, 1);
		return dequeBinarySearch(mid, last, value);
	}
	else
		return dequeBinarySearch(first, mid, value);
}

void PmergeMe::dequeFordJohnsonInsertSort(std::deque<int> &main, std::deque<INT_DEQUE> &pending, size_t total)
{
	size_t j0 = 1;
	size_t j1 = 1;
	size_t jn = 3;
	std::deque<int>::iterator i;
	std::deque<INT_DEQUE>::iterator it = pending.begin();
	std::deque<INT_DEQUE>::iterator cmp;
	std::deque<int>::iterator mi;
	size_t pendingLen = pending.size();
	std::deque<int>::iterator j;
	if ((*it).size() == 2)
	{
		j = (*it).begin();
		std::advance(j, 1);
		main.insert(main.begin(), *j);
		total--;
	}
	while (total > 0)
	{
		jn = j1 + 2 * j0;
		if (jn > pendingLen)
			jn = pendingLen;
		it = pending.begin();
		std::advance(it, jn - 1);
		cmp = pending.begin();
		std::advance(cmp, j1 - 1);
		while (it != cmp)
		{
			if ((*it).size() != 2)
			{
				--it;
				continue;
			}
			j = (*it).begin();
			mi = dequeBinarySearch((main).begin(), (main).end(), *j);
			std::advance(j, 1);
			mi = dequeBinarySearch(main.begin(), mi, *j);

			main.insert(mi, *j);
			total--;
			--it;
		}
		j0 = j1;
		j1 = jn;
	}
}

size_t PmergeMe::setDequeMainChainAndPendingElements(std::deque<INT_DEQUE> &deque, std::deque<int> &mainChain)
{
	size_t count = 0;
	for (std::deque<INT_DEQUE>::iterator it = deque.begin(); it != deque.end(); ++it)
	{
		std::deque<int>::iterator i = (*it).begin();
		mainChain.push_back(*i);
		if ((*it).size() == 2)
			count++;
	}
	return count;
}

void PmergeMe::deque_sort()
{
	size_t first, second;
	std::deque<int> tmp;
	std::deque<int>::iterator it = _deque.begin();
	std::deque<INT_DEQUE> deque_tmp;
	if (_deque.size() == 1)
		return;
	if (_deque.size() == 2)
	{
		first = *it;
		std::advance(it, 1);
		second = *it;
		if (first > second)
		{
			*_deque.begin() = second;
			*it = first;
		}
		return;
	}
	for (size_t i = 0; i < _deque.size(); i++)
	{
		if (i + 2 <= _deque.size())
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
		deque_tmp.push_back(tmp);
		tmp.clear();
	}
	dequeFordJohnsonMergeSort(deque_tmp, 0, deque_tmp.size() - 1);
	_deque.clear();
	size_t pendingSize = setDequeMainChainAndPendingElements(deque_tmp, _deque);
	dequeFordJohnsonInsertSort(_deque, deque_tmp, pendingSize);
}

void PmergeMe::start()
{
	// printList(_list, "Before");
	printListUnderFive(_list, "Before");
	clock_t start = clock();
	list_sort();
	clock_t end = clock();
	// printList(_list, "After");
	printListUnderFive(_list, "After");
	std::cout << "list is sorted? : " << std::is_sorted(_list.begin(), _list.end()) << std::endl;
	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << _list.size() << "  elements with std::list : " << elapsedTime << " ms" << std::endl;

	// printDequeUnderFive(_deque, "Before");
	// printDeque(_deque, "Before");
	start = clock();
	deque_sort();
	end = clock();
	// printDequeUnderFive(_deque, "After");
	// printDeque(_deque, "After");
	std::cout << "deque is sorted? : " << std::is_sorted(_deque.begin(), _deque.end()) << std::endl;
	elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << _deque.size() << "  elements with std::deque : " << elapsedTime << " ms" << std::endl;
}
