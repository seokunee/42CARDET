/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:28:53 by seokchoi          #+#    #+#             */
/*   Updated: 2022/12/30 17:33:30 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){};
Contact::~Contact(){};

void	Contact::setFristName (std::string first_name){
	this->first_name_ = first_name;
}

void	Contact::setLastName (std::string last_name){
	this->last_name_ = last_name;
}

void	Contact::setNickname (std::string nickname){
	this->nickname_ = nickname;
}

void	Contact::setPhoneNumber (std::string phone_number){
	this->phone_number_ = phone_number;
}

void	Contact::setDarkestSecret (std::string darkest_secret){
	this->darkest_secret_ = darkest_secret;
}

std::string	Contact::getFristName (){
	return (this->first_name_);
}

std::string	Contact::getLastName (){
	return (this->last_name_);
}

std::string	Contact::getNickname (){
	return (this->nickname_);
}

std::string	Contact::getPhoneNumber (){
	return (this->phone_number_);
}

std::string	Contact::getDarkestSecret (){
	return (this->darkest_secret_);
}
