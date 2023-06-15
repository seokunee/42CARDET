/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/16 00:38:26 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Argument Fault!" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return 0;
}

/*
a
abc
/
1
1.0
1.0f
42.0
42.0f
42.0f0f
42.0000f
nan
inf
-inf
+inf
inff
-inff
+inff
*/