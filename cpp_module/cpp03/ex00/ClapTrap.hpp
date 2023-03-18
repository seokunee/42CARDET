/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:56:10 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/18 20:17:20 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string _name;
		int _hit;
		int _power;
		int _attackDamage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(ClapTrap const &src);

		ClapTrap &operator=(const ClapTrap &src);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

// Fixed &Fixed::operator=(const Fixed &src){
// 	// std::cout << "Copy assignment operator called" << std::endl;
// 	_fixPoint = src.getRawBits();
// 	return (*this);
// };

#endif
