/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/08 15:08:02 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	{
		Base *ran = generate();

		identify(ran);

		delete ran;
	}
	std::cout << "--------------" << std::endl;
	{
		Base *a = new A();
		Base *b = new B();
		Base *c = new C();

		identify(*a);
		identify(*b);
		identify(*c);

		delete a;
		delete b;
		delete c;
	}
	std::cout << "--------------" << std::endl;
	{
		Base *a = new A();
		Base *b = new B();
		Base *c = new C();

		identify(a);
		identify(b);
		identify(c);

		delete a;
		delete b;
		delete c;
	}
	return 0;
}
