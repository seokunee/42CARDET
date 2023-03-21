/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:56:08 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/21 17:14:50 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap seokchoi("seokchoi");
	ScavTrap gdragon("gdragon");

	seokchoi.guardGate();
	gdragon.guardGate();
	std::cout << "-----test1-----" << std::endl;
	seokchoi.attack("gdragon");
	gdragon.takeDamage(20);
	gdragon.beRepaired(10);
	gdragon.takeDamage(20);
	gdragon.takeDamage(20);
	gdragon.takeDamage(20);
	gdragon.takeDamage(20);
	gdragon.takeDamage(20);
	gdragon.takeDamage(20);
	gdragon.takeDamage(20);
	gdragon.beRepaired(10);

	return (0);
}
