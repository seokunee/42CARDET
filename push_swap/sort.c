/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:04:33 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/29 15:04:50 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *arr, int L, int R)
{
	int left = L;
	int	right = R;
	int pivot = arr[(L + R) / 2];
	int tmp;

	while (left<= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left<= right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	};
	if (L < right)
		quick_sort(arr, L, right);
	if (left < R)
		quick_sort(arr, left, R);
}
