/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/09 00:38:42 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void	throw_error(std::string meg)
{
	std::cout << meg << std::endl;
	std::exit(1);
}

int	main(int ac, char **av)
{
	std::string line = "";
	Sed	changer;
	if (ac != 4)
		throw_error("Not valid argments");
	changer.toDoLikeSed(av[1], av[2], av[3]);
	// system("leaks replace");
	return (0);
}
