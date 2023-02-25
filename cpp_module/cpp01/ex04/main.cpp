/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/14 01:41:51 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::string line = "";

	if (ac != 4)
	{
		std::cout << "Not valid argments" << std::endl;
		return (1);
	}
	std::string file = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string new_file = file + ".replace";
	std::string buf;

	std::ifstream readFile;

	readFile.open(file);
	if (readFile.is_open() == true){
		while (std::getline(readFile, buf, '0')){
			line.append(buf);
		}
	} else {
		std::cout << "Not valid file" << std::endl;
		return (1);
	}
	
	size_t idx;
	while (line.find(s1) != std::string::npos){
		idx = line.find(s1);
		line.erase(idx, s1.length());
		line.insert(idx, s2);
	}

	std::ofstream writeFile;
	writeFile.open(new_file);
	if (writeFile.is_open() == true){
		writeFile << line;
	} else {
		std::cout << "Can not open " << new_file << std::endl;
		readFile.close();
		return (1);
	}
	readFile.close();
	writeFile.close();
	system("leaks replace");
	return (0);
}