/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:40 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/25 22:06:30 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const Animal *i = new Cat();
		const Animal *j = new Dog();
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		std::cout << std::endl;

		delete i;
		delete j;
	}
	// system("leaks animal");
	return (0);
}
