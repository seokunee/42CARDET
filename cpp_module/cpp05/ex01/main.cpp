/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/31 22:03:54 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	Bureaucrat seok("seokchoi", 3);
	{
		try{
			std::cout << seok;
			seok.increment();
			seok.increment();
			std::cout << seok;
			seok.increment();
		}catch (std::exception &error){
			std::cout << "ERROR!!" << std::endl;
			std::cout << error.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	Bureaucrat atom("atom", 148);
	{
		try{
			std::cout << atom;
			atom.decrement();
			atom.decrement();
			std::cout << atom;
			atom.decrement();
		}catch (std::exception &error){
			std::cout << "ERROR!!" << std::endl;
			std::cout << error.what() << std::endl;
		}
	}
	return 0;
}