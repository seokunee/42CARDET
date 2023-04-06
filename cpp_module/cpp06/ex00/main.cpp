/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/06 18:11:19 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{



	// ./convert 0
	// char: Non displayable
	// int: 0
	// float: 0.0f
	// double: 0.0
	// ./convert nan
	// char: impossible
	// int: impossible
	// float: nanf
	// double: nan
	// ./convert 42.0f
	// char: '*'
	// int: 42
	// float: 42.0f
	// double: 42.0
	return 0;
}
