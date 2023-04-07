/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:59:40 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 19:57:35 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_name = "ScavTrap";
	_hit = 100;
	_power = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap : creat " << _name << ", default constructor are called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	_hit = 100;
	_power = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap : creat " << _name << ", name constructor are called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap : delete " << _name << ", destructor are called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src){
	*this = src;
	std::cout << "ScavTrap : copy " << _name << " copy constructor are called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src){
	if (this == &src)
		return (*this);
	_name = src._name;
	_hit = src._hit;
	_power = src._power;
	_attackDamage = src._attackDamage;
	return (*this);
};

void ScavTrap::attack(const std::string& target){
	if (_hit == 0)
		std::cout << _name << " is already dead so don't attack!" << std::endl;
	else if (_power == 0)
		std::cout << _name << "'s power is zero" << std::endl;
	else
	{
		_power = _power - 1;
		std::cout << "ScavTrap ";
		std::cout << _name;
		std::cout << " attacks ";
		std::cout << target;
		std::cout << ", causing ";
		std::cout << _attackDamage;
		std::cout << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(){
	if (_hit == 0)
		std::cout << _name << " is already dead so don't attack!" << std::endl;
	else if (_power == 0)
		std::cout << _name << "'s power is zero" << std::endl;
	else
	{
		_power = _power - 1;
		std::cout << _name << " is now in Gate keeper mode." << std::endl;
	}
};
