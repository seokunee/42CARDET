/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:40 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/25 18:40:09 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *i = new Cat();
	const Animal *j = new Dog();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	std::cout << "----------Wrong test------------" << std::endl;
	const WrongAnimal *wani = new WrongAnimal();
	const WrongAnimal *wcat = new WrongCat();
	std::cout << wani->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;
	wani->makeSound();
	wcat->makeSound();
	delete (wani);
	delete (wcat);
	std::cout << "----------static test------------" << std::endl;
	// const Animal ani;
	const Cat ccat = Cat();
	const Animal acat = Cat();
	// std::cout << ani.getType() << " " << std::endl;
	std::cout << ccat.getType() << " " << std::endl;
	std::cout << acat.getType() << " " << std::endl;

	// ani.makeSound();
	ccat.makeSound();
	acat.makeSound();

	// wcat will say "WrongAnimal sound~" because WrongAnimal' makeSound is not virtual function

	// system("leaks animal");
	return (0);
}
