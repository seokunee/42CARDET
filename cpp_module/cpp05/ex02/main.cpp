/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/13 20:21:45 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat seok("seok", 3);
		// Bureaucrat 			seok("seok", 50);
		PresidentialPardonForm atom("atom");
		seok.signForm(atom);
		seok.executeForm(atom);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat choi("choi", 3);
		// Bureaucrat 			choi("choi", 50);
		RobotomyRequestForm atom("atom");
		choi.signForm(atom);
		choi.executeForm(atom);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat hun("hun", 3);
		// Bureaucrat 			hun("hun", 140);
		ShrubberyCreationForm atom("atom");
		hun.signForm(atom);
		hun.executeForm(atom);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	// system("leaks form");
	return 0;
}
