/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/10 18:01:48 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	find_string(){
	
}

int	main(int ac, char **av)
{
	std::string line;

	if (ac != 4)
	{
		std::cout << "Not valid argments" << std::endl;
		return (1);
	}
	std::string file = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string new_file = file.append(".replace");
	std::string buf;

	std::ifstream ifile(file);
	if (ifile.is_open()){
		while (std::getline(std::cin, line)){
			buf.append(line);
		}
	} else {
		std::cout << "Not valid file" << std::endl;
		return (1);
	}

	
	while ()
	std::replace(buf, )

	std::ofstream ofile(file.append(".replace"));
	if (ofile.is_open){
		ofile << buf;
	} else {
		std::cout << "Can not open " << new_file << std::endl;
		return (1);
	}
	return (0);
}