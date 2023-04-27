/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:25:12 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/25 22:05:47 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal &src);
	virtual ~Animal();

	Animal &operator=(const Animal &src);
	virtual void makeSound() const;
	std::string getType() const;
};

#endif
