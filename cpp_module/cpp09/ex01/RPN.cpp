/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:34 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/23 21:01:00 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

RPN::RPN(){};
RPN::~RPN(){};
RPN::RPN(const RPN &src){};
RPN &RPN::operator=(const RPN &src){};

void RPN::run(std::string polishMath)
{
	std::string::iterator it;
	for (it = polishMath.begin(); it != polishMath.end(); ++it)
	{
		if ((*it >= '0' && *it <= '9') || *it == ' ')
		{
		}
	}
}
