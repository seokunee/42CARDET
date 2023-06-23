/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:36 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/23 20:54:46 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
private:
	std::stack<int> _stack;

public:
	RPN();
	~RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);

	void run(std::string polishMath);
};

#endif
