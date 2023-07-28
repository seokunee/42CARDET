/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:56:55 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/28 16:23:04 by seokchoi         ###   ########.fr       */
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
	PmergeMe();

	template <typename T>
	void printContainer(T &con, std::string when)
	{
		std::cout << when << ":" << std::setw(10 - when.length());
		for (typename T::iterator it = con.begin(); it != con.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	template <typename T>
	void printContainerUnderFive(T &con, std::string when)
	{
		bool stop = false;
		int count = 0;
		std::cout << when << ":" << std::setw(10 - when.length());
		if (con.size() > 5)
			stop = true;
		for (typename T::iterator it = con.begin(); it != con.end(); ++it)
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

	template <typename T>
	void printconcon(const T &con)
	{
		std::cout << "array = [";
		for (typename T::const_iterator i = con.begin(); i != con.end(); ++i)
		{
			std::cout << "[";
			for (typename T::value_type::const_iterator j = (*i).begin(); j != (*i).end(); ++j)
			{
				std::cout << *j << ",";
			}
			std::cout << "],";
		}
		std::cout << "]" << std::endl;
	}

	template <typename T>
	void conMerge(T &con, int left, int mid, int right)
	{
		int n1 = mid - left + 1;
		int n2 = right - mid;

		T leftArr, rightArr;
		typename T::iterator it = con.begin();

		std::advance(it, left);
		for (int i = 0; i < n1; ++i)
		{
			leftArr.push_back(*it);
			++it;
		}
		it = con.begin();
		std::advance(it, mid + 1);
		for (int j = 0; j < n2; ++j)
		{
			rightArr.push_back(*it);
			++it;
		}

		int i = 0, j = 0;
		typename T::iterator it_l, it_r;
		it_l = leftArr.begin();
		it_r = rightArr.begin();
		it = con.begin();
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

	template <typename T>
	void conFordJohnsonMergeSort(T &con, int left, int right)
	{
		if (left < right)
		{
			int mid = left + (right - left) / 2;
			conFordJohnsonMergeSort(con, left, mid);
			conFordJohnsonMergeSort(con, mid + 1, right);

			conMerge(con, left, mid, right);
		}
	}

	template <typename T>
	int getSecondValueOfConInt(typename T::iterator it)
	{
		std::advance(it, 1);
		return *it;
	}

	template <typename T>
	T conBinarySearch(T first, T last, int value)
	{
		if (first == last)
			return last;

		T mid = first;
		std::advance(mid, std::distance(first, last) / 2);

		if (*mid == value)
			return mid;
		else if (*mid < value)
		{
			std::advance(mid, 1);
			return conBinarySearch(mid, last, value);
		}
		else
			return conBinarySearch(first, mid, value);
	}

	template <typename T>
	void conFordJohnsonInsertSort(typename T::value_type &main, T &pending, size_t total)
	{
		size_t j0 = 1;
		size_t j1 = 1;
		size_t jn = 3;
		typename T::iterator it = pending.begin();
		typename T::value_type::iterator mi;
		size_t pendingLen = pending.size();
		typename T::value_type::iterator j;
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
			typename T::iterator cmp = pending.begin();
			std::advance(cmp, j1 - 1);
			while (it != cmp)
			{
				if ((*it).size() != 2)
				{
					--it;
					continue;
				}
				j = (*it).begin();
				mi = conBinarySearch(main.begin(), main.end(), *j);
				std::advance(j, 1);
				mi = conBinarySearch(main.begin(), mi, *j);
				main.insert(mi, *j);
				total--;
				--it;
			}
			j0 = j1;
			j1 = jn;
		}
	}

	template <typename T>
	size_t setConMainChainAndPendingElements(T &con, typename T::value_type &mainChain)
	{
		size_t count = 0;
		for (typename T::iterator it = con.begin(); it != con.end(); ++it)
		{
			typename T::value_type::iterator i = (*it).begin();
			mainChain.push_back(*i);
			if ((*it).size() == 2)
				count++;
		}
		return count;
	}

	template <typename T>
	void con_sort(T &con_type, typename T::value_type &con_value)
	{
		(void)con_type;
		size_t first, second;
		typename T::value_type tmp;
		typename T::value_type::iterator it = con_value.begin();
		T con_tmp;

		if (con_value.size() == 1)
			return;
		if (con_value.size() == 2)
		{
			first = *it;
			std::advance(it, 1);
			second = *it;
			if (first > second)
			{
				*con_value.begin() = second;
				*it = first;
			}
			return;
		}
		for (size_t i = 0; i < con_value.size(); i++)
		{
			if (i + 2 <= con_value.size())
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
			con_tmp.push_back(tmp);
			tmp.clear();
		}
		conFordJohnsonMergeSort(con_tmp, 0, con_tmp.size() - 1);
		con_value.clear();
		size_t pendingSize = setConMainChainAndPendingElements(con_tmp, con_value);
		conFordJohnsonInsertSort(con_value, con_tmp, pendingSize);
	}

public:
	PmergeMe(int ac, char **av);
	~PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	void start();
};

#endif
