/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:49:31 by seokchoi          #+#    #+#             */
/*   Updated: 2022/12/26 01:29:11 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int		i;
	int		j;
	char	c;

	if (ac == 1)
	{
		std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
			{
				c = toupper(av[i][j]);
				std:: cout << c;
			}
			else
				std:: cout << av[i][j];
			j++;
		}
		i++;
	}
	std:: cout << std::endl;
    return 0;
}