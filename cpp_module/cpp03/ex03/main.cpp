/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:56:08 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/22 18:55:20 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap seokchoi("seokchoi");
	DiamondTrap gdragon("gdragon");

	std::cout << "-----Frag-----" << std::endl;
	seokchoi.highFivesGuys();
	gdragon.highFivesGuys();
	std::cout << "-----Scav-----" << std::endl;
	seokchoi.guardGate();
	gdragon.guardGate();
	std::cout << "-----Diamond-----" << std::endl;
	seokchoi.whoAmI();
	gdragon.whoAmI();
	std::cout << "-----Status-----" << std::endl;
	seokchoi.checkStatus();
	gdragon.checkStatus();


	std::cout << "-----attack-----" << std::endl;
	seokchoi.attack("seokchoi");
	gdragon.attack("gdragon");


	return (0);
}
