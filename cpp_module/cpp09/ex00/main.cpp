/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:03:26 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/22 23:35:53 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	BitcoinExchange bitcoinExchange;
	try
	{
		bitcoinExchange.run(av[1]);
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
		exit(1);
	}
	return 0;
}
