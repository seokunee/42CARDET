/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:43:28 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/06 18:18:13 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &src){
	*this = src;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){
	return (*this);
}

void ScalarConverter::convert(std::string literal){

	int i = std::atoi(literal.c_str()); // c_str change string -> char *
	double d;
	std::stringstream ss(literal);
	ss >> d;
}
