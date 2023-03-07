/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/09 15:51:53 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <vector>

class Zombie {
	private:
		std::string name_;
	public:
		typedef Zombie		t;
		void	announce(void);
		void	setName(std::string name);
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
