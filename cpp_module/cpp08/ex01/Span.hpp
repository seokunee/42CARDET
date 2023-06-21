/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:28:44 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/21 16:28:48 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
private:
	std::vector<int> _span;
	Span();

public:
	class SpanIsFull : public std::exception
	{
		const char *what() const throw();
	};

	class NumbersNotEnough : public std::exception
	{
		const char *what() const throw();
	};
	Span(unsigned int N);
	~Span();
	Span(const Span &src);
	Span &operator=(const Span &src);

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	void addNumberByRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	std::vector<int> getSpan();
};

#endif