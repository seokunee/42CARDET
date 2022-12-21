/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:22:39 by seokchoi          #+#    #+#             */
/*   Updated: 2022/12/20 03:31:09 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_in_s2(char c, char *s2)
{
	int i = 0;
	while (s2[i])
	{
		if (s2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_prev_s1(char c, int ind, char *s1)
{
	int i = 0;
	
	if (ind == 0)
		return (1);
	while (s1[i] && i < ind)
	{
		if (s1[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	int	i = 0;
	int j = 0;
	char *s1 = av[1];
	char *s2 = av[2];
	while (s1[i])
	{
		if (check_prev_s1(s1[i], i, s1) && check_in_s2(s1[i], s2))
			write(1, &s1[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}