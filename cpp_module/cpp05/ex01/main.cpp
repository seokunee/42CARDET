/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/05/16 15:20:58 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat seok("seok", 3);
			Form atom("atom", 15, 20);
			std::cout << seok << "signFrom => ";
			seok.signForm(atom);
		}
		catch (std::exception &error)
		{
			std::cout << "ERROR!!" << std::endl;
			std::cout << error.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat choi("choi", 18);
			Form atom("atom", 15, 20);
			std::cout << choi;
			choi.signForm(atom);
		}
		catch (std::exception &error)
		{
			std::cout << "ERROR!!" << std::endl;
			std::cout << error.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	// system("leaks form");
	return 0;
}
