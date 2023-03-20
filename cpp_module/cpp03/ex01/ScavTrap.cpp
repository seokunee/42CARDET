/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:59:40 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/19 21:13:42 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_name = "ScavTrap";
	std::cout << "ScavTrap : creat " << _name << ", default constructor are called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(){
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

};

void ScavTrap::guardGate(){
	
};