/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:30:06 by seokchoi          #+#    #+#             */
/*   Updated: 2022/12/30 19:24:57 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	order = 0;
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::addInfo_(){
	std::string line;

	std::cout << "@ Enter First name : ";
	std::getline(std::cin, line);
	store_[order].setFristName(line);

	std::cout << "@ Enter Last name : ";
	std::getline(std::cin, line);
	store_[order].setLastName(line);

	std::cout << "@ Enter Nickname : ";
	std::getline(std::cin, line);
	store_[order].setNickname(line);

	std::cout << "@ Enter Phone number : ";
	std::getline(std::cin, line);
	store_[order].setPhoneNumber(line);

	std::cout << "@ Enter Darkest secret : ";
	std::getline(std::cin, line);
	store_[order].setDarkestSecret(line);

	order = (order + 1) % 8;
	std::cout  << std::endl << "ADD COMPLETE! :)" << std::endl;
}

void	PhoneBook::searchInfo_(){
	std::string line;

	printContactTable_();
	while (1){
		std::cout << "@ Enter Index : ";
		std::getline(std::cin, line);
		if (line.compare("") != 0)
			break;
	}
	if (std::stoi(line) >= 0 && std::stoi(line) <= 7)
		printContact_(std::stoi(line));
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

	std:: cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std:: cout << "         " << i << "|";
		if (store_[i].getFristNaame().length() > 10)
			std::cout << store_[i].getFristName().substr(0, 9) << "." << "|";
		else
			std::cout << space.substr(0, 10 - store_[i].getFristName().length()) << store_[i].getFristName() << "|";
		if (store_[i].getLastName().length() > 10)
			std::cout << store_[i].getLastName().substr(0, 9) << "." << "|";
		else
			std::cout << space.substr(0, 10 - store_[i].getLastName().length()) << store_[i].getLastName() << "|";
		if (store_[i].getNickname().length() > 10)
			std::cout << store_[i].getNicknme().substr(0, 9) << ".";
		else
			std::cout << space.substr(0, 10 - store_[i].getNickname().length()) << store_[i].getNickname();
		std::cout << std::endl;
	}
}

void	PhoneBook::getCommand_(){
	std::string cmd;

	while (1){
		std::cout << std::endl;
		std::cout << std::endl;
		welcome_();
		std::cout << std::endl;
		std::cout << "TYPE COMMAND : ";
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0)
			addInfo_();
		else if (cmd.compare("SEARCH") == 0)
			searchInfo_();
		else if (cmd.compare("EXIT") == 0)
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

/*
	처리해줘야할 부분
	1. 이름에 영어만 들어갈 수 있도록?
	2. 전번은 숫자만
	3. 인덱스 숫자만 그리고 0~7까지만
*/