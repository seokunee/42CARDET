/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:51:57 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/23 19:11:59 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <sstream>

enum FloatCheckType
{
	PLUS,
	MINUS,
	TOOBIG,
	BADINPUT,
};

class BitcoinExchange
{
private:
	bool checkFloatPoint(float f);
	FloatCheckType checkValue(std::string &value, float &f_value);
	void csvSplit(std::map<std::string, float> &dataBase, std::string &line, char delimiter);
	void readFile(std::map<std::string, float> &dataBase);
	std::string trim(const std::string &str);
	bool inputSplit(std::string &date, std::string &value, std::string &line, char delimiter);
	bool checkDate(std::string date);
	void checkInputFile(std::map<std::string, float> &dataBase, char *inputFileName);

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);

	void run(char *inputFileName);
};

#endif
