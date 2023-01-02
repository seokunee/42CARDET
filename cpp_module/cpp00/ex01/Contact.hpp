/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:23:35 by seokchoi          #+#    #+#             */
/*   Updated: 2022/12/30 15:31:18 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>	
#include <string>

class Contact {
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;
	public:
		Contact();
		~Contact();

		void	setFristName(std::string first_name);
		void	setLastName(std::string last_name);
		void	setNickname(std::string nickname);
		void	setPhoneNumber(std::string phone_number);
		void	setDarkestSecret(std::string darkest_secret);

		std::string	getFristName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
};

#endif