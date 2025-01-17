/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:51:45 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/27 16:22:14 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <limits>

BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	(void)src;
	return *this;
}

bool BitcoinExchange::checkFloatPoint(float f)
{
	std::ostringstream oss;
	oss << f;
	std::string str = oss.str();
	size_t idx = str.find('.');
	if (idx == std::string::npos)
		return false;
	return true;
}

FloatCheckType BitcoinExchange::checkIntValue(std::string &value, int &i_value)
{
	std::stringstream ss(value);
	ss >> i_value;

	if (ss.fail() || !ss.eof())
		return BADINPUT;
	else if (i_value < 0)
		return MINUS;
	return PLUS;
}

FloatCheckType BitcoinExchange::checkValue(std::string &value, float &f_value)
{
	std::stringstream ss(value);
	ss >> f_value;

	if (ss.fail() || !ss.eof())
		return BADINPUT;
	else if (f_value > 1000)
		return TOOBIG;
	else if (f_value < 0)
		return MINUS;
	return PLUS;
}

std::string BitcoinExchange::trim(const std::string &str)
{
	std::size_t first = str.find_first_not_of(' ');
	if (first == std::string::npos)
	{
		return "";
	}
	std::size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

void BitcoinExchange::checkDataCsvKey(std::string &key, int &prev_year, int &prev_mon, int &prev_date)
{
	if (!checkDate(key))
		throw std::runtime_error("Error : Invalid csv file.");
	std::stringstream ss(key);
	std::string year, mon, date;
	int int_year, int_mon, int_date;
	std::string temp;

	if (std::getline(ss, temp, '-'))
		year = temp;
	if (std::getline(ss, temp, '-'))
		mon = temp;
	if (std::getline(ss, temp, '-'))
		date = temp;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Error : Invalid csv file.");
	if (checkIntValue(year, int_year) != 0)
		throw std::runtime_error("Error : Invalid csv file.");
	if (checkIntValue(mon, int_mon) != 0)
		throw std::runtime_error("Error : Invalid csv file.");
	if (checkIntValue(date, int_date) != 0)
		throw std::runtime_error("Error : Invalid csv file.");
	// std::cout << prev_year << ", " << int_year << " | " << prev_date << ", " << int_date << " | " << prev_mon << " , " << int_mon << std::endl;
	if (int_year >= prev_year)
	{
		if (int_year == prev_year)
		{
			if (int_mon >= prev_mon)
			{
				if (int_mon == prev_mon)
				{
					if (int_date <= prev_date)
						throw std::runtime_error("Error : Invalid csv file.");
				}
			}
			else
				throw std::runtime_error("Error : Invalid csv file.");
		}
	}
	else
		throw std::runtime_error("Error : Invalid csv file.");
	prev_year = int_year;
	prev_mon = int_mon;
	prev_date = int_date;
}

void BitcoinExchange::csvSplit(std::map<std::string, float> &dataBase, std::string &line, int &prev_year, int &prev_mon, int &prev_date)
{
	std::stringstream ss(line);
	std::string temp;
	std::string key;
	float value = -1;

	if (std::getline(ss, temp, ','))
		key = temp;
	if (std::getline(ss, temp, ','))
		checkValue(temp, value);
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Error : Invalid csv file.");
	if (value < 0)
		throw std::runtime_error("Error : Invalid csv file.");
	checkDataCsvKey(key, prev_year, prev_mon, prev_date);
	dataBase[key] = value;
}

void BitcoinExchange::readFile(std::map<std::string, float> &dataBase)
{
	std::ifstream file("data.csv");
	int prev_year = -1;
	int prev_mon = -1;
	int prev_date = -1;

	if (file.is_open())
	{
		std::string line;
		if (std::getline(file, line))
		{
			if (line != "date,exchange_rate")
				throw std::runtime_error("Error : Invalid csv file.");
		}
		while (std::getline(file, line))
			csvSplit(dataBase, line, prev_year, prev_mon, prev_date);
		file.close();
	}
	else
		throw std::runtime_error("Error: could not open file.");
}

bool BitcoinExchange::inputSplit(std::string &date, std::string &value, std::string &line, char delimiter)
{
	std::stringstream ss(line);
	std::string temp;

	if (std::getline(ss, temp, delimiter))
		date = trim(temp);
	if (std::getline(ss, temp, delimiter))
		value = trim(temp);
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

bool BitcoinExchange::checkDate(std::string date)
{
	int year, month, day;
	std::string str_year, str_month, str_day;

	std::stringstream ss(date);
	if (std::getline(ss, str_year, '-'))
	{
		if (checkIntValue(str_year, year) != 0)
			return false;
	}
	if (std::getline(ss, str_month, '-'))
	{
		if (checkIntValue(str_month, month) != 0)
			return false;
		if (month < 1 || month > 12)
			return false;
	}
	if (std::getline(ss, str_day, '-'))
	{
		if (checkIntValue(str_day, day) != 0)
			return false;
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
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

void BitcoinExchange::checkInputFile(std::map<std::string, float> &dataBase, char *inputFileName)
{
	std::ifstream file(inputFileName);
	std::string line;
	std::string date;
	std::string value;
	bool first = true;
	float f_value;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	while (std::getline(file, line))
	{
		date.clear();
		value.clear();
		if (line.empty())
			continue;
		if (!inputSplit(date, value, line, '|'))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (date == "date" && value == "value" && first == true)
		{
			first = false;
			continue;
		}
		first = false;
		if (!checkDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		FloatCheckType v_result = checkValue(value, f_value);
		if (v_result == BADINPUT)
			std::cout << "Error: bad input => " << value << std::endl;
		else if (v_result == TOOBIG)
			std::cout << "Error: too large a number." << std::endl;
		else if (v_result == MINUS)
			std::cout << "Error: not a positive number." << std::endl;
		else if (dataBase.find(date) != dataBase.end())
			std::cout << date << " => " << f_value << " = " << dataBase[date] * f_value << std::endl;
		else
		{
			std::map<std::string, float>::iterator it = dataBase.lower_bound(date);
			if (it == dataBase.begin())
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			--it;
			float result = (*it).second * f_value;
			if (result > static_cast<float>(std::numeric_limits<int>::max()))
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << date << " => " << static_cast<double>(f_value) << " = " << result << std::endl;
		}
	}
}

void BitcoinExchange::run(char *inputFileName)
{
	std::map<std::string, float> dataBase;

	readFile(dataBase);
	checkInputFile(dataBase, inputFileName);
}
