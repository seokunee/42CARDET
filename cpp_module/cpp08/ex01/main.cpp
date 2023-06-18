/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:25:45 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/19 02:33:31 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void subjectTest()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		Span tmp = Span(5);
		tmp.addNumber(6);
		std::cout << tmp.shortestSpan() << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}
	try
	{
		Span tmp = Span(5);
		tmp.addNumber(6);
		std::cout << tmp.longestSpan() << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

void bigNumbersTest()
{
	Span sp(10000);

	std::srand(std::time(nullptr));
	for (int i = 0; i < 10000; i++)
	{
		sp.addNumber(std::rand() % 20000);
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void oneTimeBigNumAddTest()
{
	Span sp(100);

	// vector로 한번에 sp에 데이터 넣기
	try
	{
		std::vector<int> tmp;
		std::srand(std::time(nullptr));
		for (int i = 0; i < 75; i++)
		{
			tmp.push_back(std::rand() % 1000000);
		}
		sp.addNumber(tmp);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	// std::vector<int> span = sp.getSpan();
	// std::cout << "span : ";
	// for (std::vector<int>::iterator it = span.begin(); it != span.end(); it++)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	try
	{
		std::vector<int> tmp;
		std::srand(std::time(nullptr));
		for (int i = 0; i < 75; i++)
		{
			tmp.push_back(std::rand() % 100);
		}
		sp.addNumber(tmp);
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main()
{
	subjectTest();
	std::cout << std::endl;
	std::cout << std::endl;
	bigNumbersTest();
	std::cout << std::endl;
	std::cout << std::endl;
	oneTimeBigNumAddTest();
	return 0;
}