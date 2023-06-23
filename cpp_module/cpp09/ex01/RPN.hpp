/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:36 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/24 00:55:59 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
private:
	std::stack<int> _stack;
	void checkElement(std::string &str);

public:
	RPN();
	~RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);

	void run(std::string polishMath);
};

#endif
