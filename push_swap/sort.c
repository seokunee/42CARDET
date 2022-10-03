/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:04:33 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/03 17:43:12 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *arr, int l, int r)
{
	t_sort	info;

	info.left = l;
	info.right = r;
	info.pivot = arr[(l + r) / 2];
	while (info.left <= info.right)
	{
		while (arr[info.left] < info.pivot)
			info.left++;
		while (arr[info.right] > info.pivot)
			info.right--;
		if (info.left <= info.right)
		{
			info.tmp = arr[info.left];
			arr[info.left] = arr[info.right];
			arr[info.right] = info.tmp;
			info.left++;
			info.right--;
		}
	}
	if (l < info.right)
		quick_sort(arr, l, info.right);
	if (info.left < r)
		quick_sort(arr, info.left, r);
}
