/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:52:07 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/18 17:23:40 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vector_int;
	for (int i = 0; i < 5; i++)
		vector_int.push_back(i);
	std::vector<char> vector_char;
	for (char i = 'a'; i < 'a' + 5; i++)
		vector_char.push_back(i);
	std::vector<unsigned int> vector_ui;
	for (unsigned int i = 0; i < 60; i += 10)
		vector_ui.push_back(i);
	std::deque<int> deque_int;
	for (char i = 0; i < 5; i++)
		deque_int.push_back(i);
	std::stack<int> stack_char;
	for (int i = 0; i < 5; i++)
		stack_char.push(i);
	std::queue<int> queue_int;
	for (int i = 0; i < 5; i++)
		queue_int.push(i);
	std::list<int> list_int;
	for (int i = 0; i < 5; i++)
		list_int.push_back(i);

	std::cout << "vector int" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vector_int, 0);
		std::cout << *it << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << "vector char" << std::endl;
	try
	{
		std::vector<char>::iterator it = easyfind(vector_char, 'b');
		std::cout << *it << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << "vector unsigned int" << std::endl;
	try
	{
		std::vector<unsigned int>::iterator it = easyfind(vector_ui, 50);
		std::cout << *it << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << "deque int" << std::endl;
	try
	{
		std::deque<int>::iterator it = easyfind(deque_int, 1);
		std::cout << *it << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << "deque int" << std::endl;
	try
	{
		std::deque<int>::iterator it = easyfind(deque_int, 5);
		std::cout << *it << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << "queue int" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind(list_int, 2);
		std::cout << *it << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << "stack int" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind(list_int, 3);
		std::cout << *it << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	std::cout << "list int" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind(list_int, 4);
		std::cout << *it << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	return 0;
}
