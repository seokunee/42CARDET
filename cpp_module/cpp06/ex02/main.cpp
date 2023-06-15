/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/16 02:55:21 by seokchoi         ###   ########.fr       */
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
		A a;
		B b;
		C c;

		identify(a);
		identify(b);
		identify(c);
	}
	std::cout << "--------------" << std::endl;
	{
		A *a = new A();
		B *b = new B();
		C *c = new C();

		identify(a);
		identify(b);
		identify(c);

		delete a;
		delete b;
		delete c;
	}
	return 0;
}