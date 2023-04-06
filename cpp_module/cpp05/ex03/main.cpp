/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/06 15:24:25 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat seokchoi("seokchoi", 3);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (!rrf)
			return 1;
		rrf->beSigned(seokchoi);
		rrf->execute(seokchoi);
		delete rrf;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat seokchoi("seokchoi", 3);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "John");
		if (!rrf)
			return 1;
		rrf->beSigned(seokchoi);
		rrf->execute(seokchoi);
		delete rrf;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat seokchoi("seokchoi", 3);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Roy");
		if (!rrf)
			return 1;
		rrf->beSigned(seokchoi);
		rrf->execute(seokchoi);
		delete rrf;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	// system("leaks intern");
	{
		Bureaucrat seokchoi("seokchoi", 3);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("abocado", "Sally");
		if (!rrf)
			return 1;
		rrf->beSigned(seokchoi);
		rrf->execute(seokchoi);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
