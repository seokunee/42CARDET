/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/09 02:29:54 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	throw_error(std::string msg)
{
	std::cout << msg << std::endl;
	std::exit(1);
}

int	main(int ac, char **av){
	Harl harl;

	if (ac != 2)
		throw_error("Invalid argument");
	harl.complain(av[1]);
	return 0;
}