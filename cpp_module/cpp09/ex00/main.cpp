/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:03:26 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/27 18:29:14 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Invalid argument." << std::endl;
		return 1;
	}
	BitcoinExchange bitcoinExchange;
	try
	{
		bitcoinExchange.run(av[1]);
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
	return 0;
}
