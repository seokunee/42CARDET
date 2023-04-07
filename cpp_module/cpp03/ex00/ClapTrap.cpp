/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:55:59 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 17:38:20 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"),_hit(10), _power(10), _attackDamage(0){
	std::cout << "ClapTrap : creat " << _name << ", default constructor are called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _power(10), _attackDamage(0){
	std::cout << "ClapTrap : creat " << _name << ", name constructor are called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap : delete " << _name << ", destructor are called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src){
	*this = src;
	std::cout << "ClapTrap : copy " << _name << " copy constructor are called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src){
	if (this == &src)
		return (*this);
	_name = src._name;
	_hit = src._hit;
	_power = src._power;
	_attackDamage = src._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target){
	if (_hit == 0)
		std::cout << _name << " is already dead so don't attack!" << std::endl;
	else if (_power == 0)
		std::cout << _name << "'s power is zero" << std::endl;
	else
	{
		_power = _power - 1;
		std::cout << "ClapTrap ";
		std::cout << _name;
		std::cout << " attacks ";
		std::cout << target;
		std::cout << ", causing ";
		std::cout << _attackDamage;
		std::cout << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit == 0){
		std::cout << _name << "is already die." << std::endl;
	}
	else if (_hit > amount)
	{
		_hit = _hit - amount;
		std::cout << _name << " took " << amount <<" damage." << std::endl;
	}
	else
	{
		_hit = 0;
		std::cout << _name << "is die." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit == 0)
		std::cout << _name << "'s hit is zero." << std::endl;
	else if (_power == 0)
		std::cout << _name << "'s power is zero." << std::endl;
	else
	{
		_hit = _hit + amount;
		_power = _power - 1;
		std::cout << _name << " is repaired "<< amount << " hit." << std::endl;
	}
}
