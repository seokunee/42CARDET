/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:28:42 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/21 14:43:54 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _max_size(0){};

Span::Span(unsigned int N) : _max_size(N){};

Span::~Span(){};

Span::Span(const Span &src)
{
	*this = src;
};

Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return *this;
	_span.clear();
	_span = src._span;
	_max_size = src._max_size;
	return *this;
};

void Span::addNumber(int num)
{
	if (_span.size() > _max_size)
		throw SpanIsFull();
	_span.push_back(num);
};

void Span::addNumber(std::vector<int> nums)
{
	if (_span.size() + nums.size() > _max_size)
		throw SpanIsFull();
	_span.insert(_span.end(), nums.begin(), nums.end());
}

int Span::shortestSpan()
{
	if (_span.size() < 2)
		throw NumbersNotEnough();
	int len;
	std::vector<int> sortedSpans = _span;
	std::sort(sortedSpans.begin(), sortedSpans.end());
	int shorestLen = std::abs(sortedSpans[1] - sortedSpans[0]);
	for (unsigned int i = 2; i < _span.size(); i++)
	{
		len = std::abs(sortedSpans[i] - sortedSpans[i - 1]);
		if (len < shorestLen)
			shorestLen = len;
	}
	return shorestLen;
};

int Span::longestSpan()
{
	if (_span.size() < 2)
		throw NumbersNotEnough();
	std::vector<int> sortedSpans = _span;
	std::sort(sortedSpans.begin(), sortedSpans.end());
	return (sortedSpans[sortedSpans.size() - 1] - sortedSpans[0]);
};

const char *Span::SpanIsFull::what() const throw()
{
	return "Span is full";
};

const char *Span::NumbersNotEnough::what() const throw()
{
	return "There are not enough numbers to calculate.";
};

std::vector<int> Span::getSpan()
{
	return _span;
}