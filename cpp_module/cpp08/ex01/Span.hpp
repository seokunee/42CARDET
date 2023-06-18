/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:28:44 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/19 01:15:34 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
private:
	Span();
	std::vector<int> _span;
	unsigned int _max_size;

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
	void addNumber(std::vector<int> nums);
	int shortestSpan();
	int longestSpan();
	std::vector<int> getSpan();
};

#endif