/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:25:25 by seokchoi          #+#    #+#             */
/*   Updated: 2023/05/23 15:48:21 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed() {}

Sed::~Sed() {}

void Sed::_read(std::string &line)
{
	_readFile.open(_file);
	if (_readFile.is_open() == true)
	{
		while (std::getline(_readFile, _buf))
		{
			line.append(_buf);
			line += '\n';
		}
		if (!_readFile.eof())
		{
			_readFile.close();
			throw_error("There was an error reading " + _file + " file.");
		}
	}
	else
		throw_error("Not valid file");
	_readFile.close();
}

void Sed::_write(std::string &line)
{
	_writeFile.open(_new_file);
	if (_writeFile.is_open() == true)
	{
		_writeFile << line;
	}
	else
	{
		throw_error("Can not open " + _new_file);
	}
	_writeFile.close();
}

void Sed::_changeWord(std::string &line)
{
	size_t idx;

	while (line.find(_s1) != std::string::npos)
	{
		idx = line.find(_s1);
		line.erase(idx, _s1.length());
		line.insert(idx, _s2);
	}
}

void Sed::toDoLikeSed(std::string file, std::string s1, std::string s2)
{
	_file = file;
	_s1 = s1;
	_s2 = s2;
	std::string line = "";
	_new_file = file + ".replace";
	if (_file == "" || _s1 == "")
		throw_error("file or s1 is empty");
	_read(line);
	if (s1 != s2) // 이것을 보는 사람이 있거든 s2에 s1이 포함되는지 확인하시오. ex. s1 = 123, s2=123123 -> 이 경우 무한 루프가 일어난다.
		_changeWord(line);
	_write(line);
}
