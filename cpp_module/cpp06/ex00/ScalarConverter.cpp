/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:43:28 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/16 00:38:27 by seokchoi         ###   ########.fr       */
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
	if (this == &src)
		return (*this);
	return (*this);
}

bool ScalarConverter::checkDoublePoint(double d)
{
	std::ostringstream oss;
	oss << d;
	std::string str = oss.str();
	size_t idx = str.find('.');
	if (idx == std::string::npos)
		return false;
	return true;
}

bool ScalarConverter::checkFloatPoint(float f)
{
	std::ostringstream oss;
	oss << f;
	std::string str = oss.str();
	size_t idx = str.find('.');
	if (idx == std::string::npos)
		return false;
	return true;
}

/*
 * Convert to char : charater or impossible or non displayable
 * charater : 출력할 수 있는 문자
 * non displayable : 출력할 수 없는 문자
 * impossible : 2개 이상의 문자
 */
void ScalarConverter::changeChar(std::string &literal)
{
	char *endptr;
	double d = std::strtod(literal.c_str(), &endptr);
	if (*endptr != '\0')
		std::cout << "char: impossible" << std::endl;
	else if (d == HUGE_VAL || d == -HUGE_VAL)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(d)) == 0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(d) << std::endl;
}

/*
 * Convert to int : int or impossible
 * int : -2147483648 ~ 2147483647
 * impossible : -inf, inf, nan
 */
void ScalarConverter::changeInt(std::string &literal)
{
	char *endptr;
	double d = std::strtod(literal.c_str(), &endptr);
	if (*endptr != '\0')
		std::cout << "int : impossible" << std::endl;
	else if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
	{
		int i = static_cast<int>(d);
		std::cout << "int :" << i << std::endl;
	}
}

/*
 * Convert to float : float or nanf or inff or -inff
 * float : -3.40282e+38 ~ 3.40282e+38
 * nanf : nan
 * inff : inf
 * -inff : -inf
 */
void ScalarConverter::changeFloat(std::string &literal)
{
	if (literal == "+inf" || literal == "-inf" || literal == "inf")
		std::cout << "float : " << literal << "f" << std::endl;
	else
	{
		char *endptr;
		float f = std::strtof(literal.c_str(), &endptr);
		if (*endptr != '\0')
			std::cout << "float : nanf" << std::endl;
		else if (f == HUGE_VAL)
			std::cout << "float : inff" << std::endl;
		else if (f == -HUGE_VAL)
			std::cout << "float : -inff" << std::endl;
		else if (checkFloatPoint(f))
			std::cout << "float : " << f << "f" << std::endl;
		else
			std::cout << "float : " << f << ".0f" << std::endl;
	}
}

/*
 * Convert to double : double or nan or inf or -inf
 * double : -1.79769e+308 ~ 1.79769e+308
 * nan : nan
 * inf : inf
 * -inf : -inf
 */
void ScalarConverter::changeDouble(std::string &literal)
{
	if (literal == "+inf" || literal == "-inf" || literal == "inf")
		std::cout << "double : " << literal << std::endl;
	else
	{
		char *endptr;
		double d = std::strtod(literal.c_str(), &endptr);
		if (*endptr != '\0')
			std::cout << "double : nan" << std::endl;
		else if (d == HUGE_VAL)
			std::cout << "double : inf" << std::endl;
		else if (d == -HUGE_VAL)
			std::cout << "double : -inf" << std::endl;
		else if (checkDoublePoint(d))
			std::cout << "double : " << d << std::endl;
		else
			std::cout << "double : " << d << ".0" << std::endl;
	}
}

void ScalarConverter::convert(std::string literal)
{
	if (!literal.empty() && literal.back() == 'f' && literal != "+inf" && literal != "-inf" && literal != "inf")
		literal.pop_back();

	changeChar(literal);
	changeInt(literal);
	changeFloat(literal);
	changeDouble(literal);
}
