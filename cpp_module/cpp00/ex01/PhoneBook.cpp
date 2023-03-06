/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:30:06 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/03 03:55:11 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(){
	order = 0;
}

PhoneBook::~PhoneBook(){}

std::string	PhoneBook::readline_(){
	std::string line;

	std::getline(std::cin, line);
	if (std::cin.fail())
	{
		std::cout << "Invalid Input" << std::endl;
		exit(1);
	}
	if (line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ") != std::string::npos \
	|| line.length() == 0)
		throw 0;
	return line;
}

void	PhoneBook::addInfo_(){
	std::string line;
	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string ds;

	try{
		std::cout << "@ Enter First name     : ";
		fn = readline_();
		std::cout << "@ Enter Last name      : ";
		ln = readline_();
		std::cout << "@ Enter Nickname       : ";
		nn = readline_();
		std::cout << "@ Enter Phone number   : ";
		pn = readline_();
		std::cout << "@ Enter Darkest secret : ";
		ds = readline_();
	}
	catch (int e){
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	store_[order].setFristName(fn);
	store_[order].setLastName(ln);
	store_[order].setNickname(nn);
	store_[order].setPhoneNumber(pn);
	store_[order].setDarkestSecret(ds);
	order = (order + 1) % 8;
	std::cout  << std::endl << "ADD COMPLETE! :)" << std::endl;
}

void	PhoneBook::searchInfo_(){
	std::string line;
	int			index;

	printContactTable_();
	while (1){
		std::cout << "@ Enter Index : ";
		std::getline(std::cin, line);
		if (std::cin.fail())
		{
			std::cout << "Invalid Input" << std::endl;
			exit(1);
		}
		if (line != "")
			break;
	}
	if (line.length() == 1 && line[0] >= '0' && line[0] <= '7')
	{
		index = line[0] - '0';
		if (store_[index].getFristName() != "")
			printContact_(index);
		else
			std::cout << "Empty index" << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
}

void	PhoneBook::printContact_(int ind){
	std::string line;

	std::cout << "First name     : " << store_[ind].getFristName() << std::endl;

	std::cout << "Last name      : " << store_[ind].getLastName() << std::endl;;

	std::cout << "Nickname       : " << store_[ind].getNickname() << std::endl;;

	std::cout << "Phone number   : " << store_[ind].getPhoneNumber() << std::endl;;

	std::cout << "Darkest secret : " << store_[ind].getDarkestSecret() << std::endl;;
}

void	PhoneBook::printContactTable_(){
	std::string	space = "          ";

	std:: cout << "|" << std::setw(10) << "index";
	std:: cout << "|" << std::setw(10) << "first name";
	std:: cout << "|" << std::setw(10) << "last name";
	std:: cout << "|" << std::setw(10) << "nickname" << "|" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std:: cout << "|" << std::setw(10) << i << "|";
		if (store_[i].getFristName().length() > 10)
			std::cout << store_[i].getFristName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << store_[i].getFristName() << "|";
		if (store_[i].getLastName().length() > 10)
			std::cout << store_[i].getLastName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << store_[i].getLastName() << "|";
		if (store_[i].getNickname().length() > 10)
			std::cout << store_[i].getNickname().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << store_[i].getNickname();
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::getCommand_(){
	std::string cmd;
	welcome_();
	while (1){
		std::cout << std::endl;
		std::cout << "TYPE COMMAND : ";
		std::getline(std::cin, cmd);
		if (std::cin.fail())
		{
			std::cout << "Invalid Input" << std::endl;
			exit(1);
		}
		if (cmd == "ADD")
			addInfo_();
		else if (cmd == "SEARCH")
			searchInfo_();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid Command" << std::endl;
	}
}

void	PhoneBook::welcome_(){
	std::cout << "**************************************" << std::endl;
	std::cout << "*                                    *" << std::endl;
	std::cout << "*    WELCOME SEOKCHOI'S PHONE_BOOK   *" << std::endl;
	std::cout << "*                                    *" << std::endl;
	std::cout << "*    COMMAND                         *" << std::endl;
	std::cout << "*    ADD    : add phone info         *" << std::endl;
	std::cout << "*    SEARCH : search phone info      *" << std::endl;
	std::cout << "*    EXIT   : exit phone book        *" << std::endl;
	std::cout << "*                                    *" << std::endl;
	std::cout << "**************************************" << std::endl;
}

void	PhoneBook::start(){
	getCommand_();
}
