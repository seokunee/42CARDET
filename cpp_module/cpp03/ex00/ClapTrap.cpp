/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:55:59 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/18 20:12:58 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"),_hit(10), _power(10), _attackDamage(0){}

ClapTrap::~ClapTrap(){}

ClapTrap::ClapTrap(ClapTrap const &src) : _hit(10), _power(10), _attackDamage(0){}

ClapTrap &ClapTrap::operator=(const ClapTrap &src){

}

void ClapTrap::attack(const std::string& target){

}

void ClapTrap::takeDamage(unsigned int amount){

}

void ClapTrap::beRepaired(unsigned int amount){

}
