/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:43:28 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/10 21:38:15 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

void ScalarConverter::convert(std::string literal)
{
	int i;
	double d;
	float f;
	char *endptr;

	if (!literal.empty() && literal.back() == 'f')
		literal.pop_back();

	std::strtod(literal.c_str(), &endptr);

	if (*endptr != '\0' || std::isnan(std::atof(literal.c_str())) || std::isinf(std::atof(literal.c_str())))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible " << std::endl;
		std::cout << "float: nanf " << std::endl;
		std::cout << "double: nan " << std::endl;
		return;
	}
	else
	{
		i = std::atoi(literal.c_str()); // c_str change string -> char *
		d = std::atof(literal.c_str());
		f = static_cast<float>(std::atof(literal.c_str()));

		// char
		if (std::isprint(i))
			std::cout << "char: " << static_cast<char>(i) << std::endl;
		else
			std::cout << "char: Non displayable " << std::endl;

		// int
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "int: impossible " << std::endl;
		else
			std::cout << "int: " << i << std::endl;

		// float, double
		if (i == f)
		{
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
	}
}

// 오버플로우 처리?
//

// /convert 0
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
