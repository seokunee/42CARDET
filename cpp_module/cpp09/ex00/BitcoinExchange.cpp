/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:51:45 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/23 02:44:19 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <limits>

BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::~BitcoinExchange(){};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	(void)src;
	return *this;
};

bool checkFloatPoint(float f)
{
	std::ostringstream oss;
	oss << f;
	std::string str = oss.str();
	size_t idx = str.find('.');
	if (idx == std::string::npos)
		return false;
	return true;
}

FloatCheckType checkValue(std::string &value, float &f_value)
{
	char *endptr;
	f_value = std::strtof(value.c_str(), &endptr);
	if (*endptr != '\0')
		return BADINPUT;
	else if (f_value == HUGE_VAL)
		return TOOBIG;
	else if (f_value < 0 || f_value == -HUGE_VAL)
		return MINUS;
	return PLUS;
}

void csvSplit(std::map<std::string, float> &dataBase, std::string &line, char delimiter)
{
	std::stringstream ss(line);
	std::string temp;
	std::string key;
	float value = -1;

	if (std::getline(ss, temp, delimiter))
		key = temp;
	if (std::getline(ss, temp, delimiter))
		checkValue(temp, value);
	dataBase[key] = value;
}

void readFile(std::map<std::string, float> &dataBase)
{
	std::ifstream file("data.csv");

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			csvSplit(dataBase, line, ',');
			// if (dataBase
			// 	.push_back();
		}
		file.close();
	}
	else
		throw std::runtime_error("Error: could not open file.");
}

std::string trim(const std::string &str)
{
	std::size_t first = str.find_first_not_of(' ');
	if (first == std::string::npos)
	{
		return "";
	}
	std::size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

void inputSplit(std::string &date, std::string &value, std::string &line, char delimiter)
{
	std::stringstream ss(line);
	std::string temp;

	if (std::getline(ss, temp, delimiter))
		date = trim(temp);
	if (std::getline(ss, temp, delimiter))
		value = trim(temp);
}

void dateSplit(std::string &year, std::string &month, std::string &day, std::string &line, char delimiter)
{
	std::stringstream ss(line);
	std::string temp;

	if (std::getline(ss, temp, delimiter))
		year = temp;
	if (std::getline(ss, temp, delimiter))
		month = temp;
	if (std::getline(ss, temp, delimiter))
		day = temp;
	if (ss.tellg() != 0)
		day.clear();
}

bool checkDate(std::string date)
{
	float year, month, day;
	std::string str_year, str_month, str_day;

	std::stringstream ss(date);
	if (std::getline(ss, str_year, '-'))
	{
		checkValue(str_year, year);
		if (year < 2009 || year > 2022)
			return false;
	}
	if (std::getline(ss, str_month, '-'))
	{
		checkValue(str_month, month);
		if (month < 1 || month > 12)
			return false;
	}
	if (std::getline(ss, str_day, '-'))
	{
		checkValue(str_day, day);
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day > 30)
				return false;
		}
		else if (month == 2)
		{
			int i_year = static_cast<int>(year);
			if (i_year % 4 == 0 && (i_year % 100 != 0 || i_year % 400 == 0))
			{
				if (day < 1 || day > 29)
					return false;
			}
			else
			{
				if (day < 1 || day > 28)
					return false;
			}
		}
		else
		{
			if (day < 1 || day > 31)
				return false;
		}
	}
	if (str_year.empty() || str_month.empty() || str_day.empty())
		return false;
	return true;
}

void checkInputFile(std::map<std::string, float> &dataBase, char *inputFileName)
{
	std::ifstream file(inputFileName);
	std::string line;
	std::string date;
	std::string value;
	float f_value;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	while (std::getline(file, line))
	{
		inputSplit(date, value, line, '|');
		if (date == "date")
			continue;
		if (!checkDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		FloatCheckType v_result = checkValue(value, f_value);
		if (v_result == BADINPUT)
			std::cout << "Error: bad input => " << date << std::endl;
		else if (f_value > 1000 || v_result == TOOBIG)
			std::cout << "Error: too large a number." << std::endl;
		else if (v_result == MINUS)
			std::cout << "Error: not a positive number." << std::endl;
		else if (dataBase.find(date) != dataBase.end())
		{
			std::cout << date << " => " << f_value << " = " << dataBase[date] * f_value << std::endl;
		}
		else
		{
			std::map<std::string, float>::iterator it = dataBase.lower_bound(date);
			float result = (*it).second * f_value;
			if (result > static_cast<float>(std::numeric_limits<int>::max()))
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << date << " => " << f_value << " = " << result << std::endl;
		}
	}
}

void BitcoinExchange::run(char *inputFileName)
{
	std::map<std::string, float> dataBase;

	readFile(dataBase);
	checkInputFile(dataBase, inputFileName);
}