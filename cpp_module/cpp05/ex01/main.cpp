/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/13 18:20:40 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat seok("seok", 3);
		Form atom("atom", 15, 20);
		std::cout << seok;
		std::cout << atom;
		seok.signForm(atom);
		std::cout << atom;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat choi("choi", 18);
		Form atom("atom", 15, 20);
		std::cout << choi;
		std::cout << atom;
		choi.signForm(atom);
		std::cout << atom;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	// system("leaks form");
	return 0;
}
