/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:43:28 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/15 15:09:54 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
	std::srand(time(NULL));			// 시드 값 초기화
	int rand_num = std::rand() % 3; // 0~2 사이의 값 받기

	switch (rand_num)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	default:
		return (new A);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A's Pointer!" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B's Pointer!" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C's Pointer!" << std::endl;
	}
	else
	{
		std::cout << "The type is none of a, b, or c!" << std::endl;
	}
}

static void identifyForRef(Base &p, std::string type)
{
	try
	{
		if (type == "A")
			(void)dynamic_cast<A &>(p);
		if (type == "B")
			(void)dynamic_cast<B &>(p);
		if (type == "C")
			(void)dynamic_cast<C &>(p);
		std::cout << type << "'s Reference!" << std::endl;
	}
	catch (std::exception &err)
	{
	}
}

void identify(Base &p)
{
	identifyForRef(p, "A");
	identifyForRef(p, "B");
	identifyForRef(p, "C");
}