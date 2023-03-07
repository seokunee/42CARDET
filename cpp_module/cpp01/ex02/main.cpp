/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/09 20:01:27 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string say = "HI THIS IS BRAIN";
	std::string *stringPTR = &say;
	std::string &stringREF = say;

	std::cout << "say : " << say << std::endl;
	std::cout << "*stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
	std::cout << "&say: " << &say << std::endl;
	std::cout << "&stringPTR: " << &stringPTR << std::endl;
	std::cout << "&stringREF: " << &stringREF << std::endl;

	return 0;
}
