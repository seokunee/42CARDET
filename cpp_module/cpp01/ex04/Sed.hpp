/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:03:06 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/08 23:39:46 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <fstream>
#include <iostream>

class Sed{
	private:
		std::string _file;
		std::string _s1;
		std::string _s2;
		std::string _new_file;
		std::string _buf;
		std::ifstream _readFile;
		std::ofstream _writeFile;
		void _read(std::string &line);
		void _write(std::string &line);
		void _changeWord(std::string &line);

	public:
		void toDoLikeSed(std::string file, std::string s1, std::string s2);
		Sed();
		~Sed();
};

void	throw_error(std::string meg);

#endif