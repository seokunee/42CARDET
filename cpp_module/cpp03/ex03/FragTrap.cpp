/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:13:40 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 21:00:16 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "FragTrap";
	_hit = 100;
	_power = 100;
	_attackDamage = 30;
	std::cout << "FragTrap : creat " << _name << ", default constructor are called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit = 100;
	_power = 100;
	_attackDamage = 30;
	std::cout << "FragTrap : creat " << _name << ", name constructor are called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap : delete " << _name << ", destructor are called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	*this = src;
	std::cout << "FragTrap : copy " << _name << " copy constructor are called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this == &src)
		return (*this);
	_name = src._name;
	_hit = src._hit;
	_power = src._power;
	_attackDamage = src._attackDamage;
	return (*this);
};

void FragTrap::highFivesGuys(void)
{
	if (_hit == 0)
		std::cout << _name << " is already dead so don't attack!" << std::endl;
	else if (_power == 0)
		std::cout << _name << "'s power is zero" << std::endl;
	else
	{
		_power = _power - 1;
		std::cout << "FragTrap " << _name << " Give me a high five!" << std::endl;
	}
}
