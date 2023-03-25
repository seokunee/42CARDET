/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:25:12 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/25 21:27:06 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const AAnimal &src);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &src);
		virtual void makeSound() const  = 0;
		std::string getType() const;
};

#endif
