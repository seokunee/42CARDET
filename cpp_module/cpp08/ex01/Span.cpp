/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:28:42 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/12 20:54:26 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _span(0)
{
	_span.reserve(0);
};

Span::Span(unsigned int N) : _span(0)
{
	_span.reserve(N);
};

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
	return *this;
};

void Span::addNumber(int num)
{
	if (_span.capacity() == _span.size())
		throw SpanIsFull();
	_span.push_back(num);
};

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
	return (std::abs(*std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end())));
};

void Span::addNumberByRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (begin > end)
		throw std::runtime_error("Range of iterator is invalid.");
	if (std::distance(begin, end) > static_cast<int>(_span.capacity() - _span.size()))
		throw SpanIsFull();
	_span.insert(_span.end(), begin, end);
}

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
