/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:34 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/27 19:00:20 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(const RPN &src)
{
	(void)src;
	return *this;
}

void RPN::calculator(std::string &str)
{
	std::string::iterator it;
	int first, second, result;
	char oper;
	bool checkExistNum = false;
	for (it = str.begin(); it != str.end(); ++it)
	{
		if (*it >= '0' && *it <= '9')
			checkExistNum = true;
	}
	if (!checkExistNum)
		throw std::runtime_error("Error");
	for (it = str.begin(); it != str.end(); ++it)
	{
		if ((*it >= '0' && *it <= '9') || *it == ' ')
		{
			if ((*it >= '0' && *it <= '9'))
			{
				_stack.push(*it - '0');
				if (*(++it) != ' ' && it != str.end())
				{
					throw std::runtime_error("Error");
				}
			}
			while (*it != ' ' && it != str.end())
				it++;
		}
		else if (*it == '*' || *it == '/' || *it == '+' || *it == '-')
		{
			oper = *it;
			++it;
			if (it != str.end() && *it != ' ')
				throw std::runtime_error("Error");
			if (_stack.empty())
				throw std::runtime_error("Error");
			first = _stack.top();
			_stack.pop();
			if (_stack.empty())
				throw std::runtime_error("Error");
			second = _stack.top();
			_stack.pop();
			if (oper == '*')
				result = second * first;
			else if (oper == '/')
			{
				if (first == 0)
				{
					throw std::runtime_error("Error");
				}
				result = second / first;
			}
			else if (oper == '+')
				result = second + first;
			else if (oper == '-')
				result = second - first;
			_stack.push(result);
			while (*it != ' ' && it != str.end())
				it++;
		}
		else
			throw std::runtime_error("Error");
		if (it == str.end())
			break;
	}
	std::cout << _stack.top() << std::endl;
}

void RPN::run(std::string polishMath)
{
	try
	{
		if (polishMath.empty())
			throw std::runtime_error("Error");
		calculator(polishMath);
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
		std::exit(1);
	}
}
