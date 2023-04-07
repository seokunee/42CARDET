/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:56:08 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 18:05:39 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap seokchoi("seokchoi");
  	ClapTrap eunjiko("eunjiko");
  	ClapTrap jeseo("jeseo");

	// seokchoi  = seokchoi;
  	std::cout << std::endl;
  	std::cout << "-----Test#1 energyPoints-----" << std::endl;
  	for (int i = 0; i < 10; i++) {
  	  seokchoi.attack("eunjiko");
  	}
  	seokchoi.attack("eunjiko");
  	seokchoi.beRepaired(10);
  	std::cout << std::endl;

  	std::cout << "-----Test#2 hitPoints-----" << std::endl;
  	eunjiko.takeDamage(10);
  	eunjiko.attack("seokchoi");
  	eunjiko.beRepaired(10);
  	std::cout << std::endl;

  	std::cout << "-----Test#3 beRepaired()-----" << std::endl;
  	jeseo.beRepaired(10);
  	for (int i = 0; i < 20; i++) {
  	  jeseo.takeDamage(1);
  	}
  	std::cout << std::endl;
	return (0);
}
