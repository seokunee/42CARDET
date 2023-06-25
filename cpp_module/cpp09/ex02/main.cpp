/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:56:11 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/25 21:06:09 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
		return 0;
	PmergeMe pmergeMe(ac, av);

	pmergeMe.sort();
	return 0;
}

// #include <iostream>
// #include <vector>

// void merge(std::vector<int> &arr, int left, int mid, int right)
// {
// 	int n1 = mid - left + 1;
// 	int n2 = right - mid;

// 	std::vector<int> leftArr(n1), rightArr(n2);

// 	for (int i = 0; i < n1; ++i)
// 		leftArr[i] = arr[left + i];
// 	for (int j = 0; j < n2; ++j)
// 		rightArr[j] = arr[mid + 1 + j];

// 	int i = 0, j = 0, k = left;
// 	while (i < n1 && j < n2)
// 	{
// 		if (leftArr[i] <= rightArr[j])
// 		{
// 			arr[k] = leftArr[i];
// 			++i;
// 		}
// 		else
// 		{
// 			arr[k] = rightArr[j];
// 			++j;
// 		}
// 		++k;
// 	}

// 	while (i < n1)
// 	{
// 		arr[k] = leftArr[i];
// 		++i;
// 		++k;
// 	}

// 	while (j < n2)
// 	{
// 		arr[k] = rightArr[j];
// 		++j;
// 		++k;
// 	}
// }

// void fordJohnsonSort(std::vector<int> &arr, int left, int right)
// {
// 	if (left < right)
// 	{
// 		int mid = left + (right - left) / 2;

// 		fordJohnsonSort(arr, left, mid);
// 		fordJohnsonSort(arr, mid + 1, right);

// 		merge(arr, left, mid, right);
// 	}
// }

// int main()
// {
// 	std::vector<int> arr;
// 	arr.push_back(8);
// 	arr.push_back(4);
// 	arr.push_back(2);
// 	arr.push_back(9);
// 	arr.push_back(5);
// 	arr.push_back(1);
// 	arr.push_back(6);
// 	arr.push_back(3);
// 	arr.push_back(7);
// 	int n = arr.size();

// 	std::cout << "Unsorted sequence: ";
// 	for (int i = 0; i < n; ++i)
// 		std::cout << arr[i] << " ";
// 	std::cout << std::endl;

// 	fordJohnsonSort(arr, 0, n - 1);

// 	std::cout << "Sorted sequence: ";
// 	for (int i = 0; i < n; ++i)
// 		std::cout << arr[i] << " ";
// 	std::cout << std::endl;

// 	return 0;
// }