/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:56:08 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 20:07:19 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap seokchoi("seokchoi");
	FragTrap gdragon("gdragon");

	seokchoi.highFivesGuys();
	gdragon.highFivesGuys();
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
	gdragon.beRepaired(10);

	return (0);
}
