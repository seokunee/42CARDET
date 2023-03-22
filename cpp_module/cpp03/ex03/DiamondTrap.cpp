/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:17:17 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/22 15:26:32 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
	_name = "DiamondTrap";
	// _hit = 100;
	// _power = 100;
	// _attackDamage = 30;
	std::cout << "DiamondTrap : creat " << _name << ", default constructor are called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name){
	// _hit = 100;
	// _power = 100;
	// _attackDamage = 30;
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

}

void DiamondTrap::attack(const std::string& target){
	
}

void DiamondTrap::whoAmI(){
	
}

void DiamondTrap::checkStatus(){
	
}