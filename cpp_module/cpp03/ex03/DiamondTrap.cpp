/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:17:17 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 20:08:26 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// • Hit points (FragTrap) = 100
// • Energy points (ScavTrap) == 50
// • Attack damage (FragTrap) == 30
// • attack() (Scavtrap)

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
	_name = "DiamondTrap";
	_attackDamage = 30;
	ClapTrap::_name = _name.append("_clap_name");
	std::cout << "DiamondTrap : creat " << _name << ", default constructor are called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name){
	_name = name;
	_attackDamage = 30;
	ClapTrap::_name = name.append("_clap_name");
	std::cout << "DiamondTrap : creat " << _name << ", name constructor are called" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap : delete " << _name << ", destructor are called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src){
	*this = src;
	std::cout << "DiamondTrap : copy " << _name << " copy constructor are called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src){
	if (this == &src)
		return (*this);
	_name = src._name;
	_hit = src._hit;
	_power = src._power;
	_attackDamage = src._attackDamage;
	return (*this);
}

void DiamondTrap::whoAmI(){
	std::cout << "DiamondTrap name is " << _name << "." << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}

void DiamondTrap::checkStatus(){
	std::cout << "name : " << _name << std::endl;
	std::cout << "hit : " << _hit << std::endl;
	std::cout << "power : " << _power << std::endl;
	std::cout << "attackDamage : " << _attackDamage << std::endl;
}
