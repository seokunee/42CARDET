/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/14 16:30:39 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *data = new Data();
	data->s1 = "hello";
	data->s2 = "seokchoi";

	uintptr_t ptr = Serializer::serialize(data);
	std::cout << ptr << std::endl;

	Data *data_after = Serializer::deserialize(ptr);
	std::cout << data_after->s1 << std::endl;
	std::cout << data_after->s2 << std::endl;

	delete data;

	return 0;
}