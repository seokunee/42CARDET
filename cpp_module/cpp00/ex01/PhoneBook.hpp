/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 02:08:27 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/01 20:38:04 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>


class PhoneBook {
	private:
		Contact		store_[8];
		int			order;
		std::string	readline_();
		void		addPersonInfo_();
		void		getCommand_();
		void		welcome_();
		void		addInfo_();
		void		printContactTable_();
		void		searchInfo_();
		void		printContact_(int ind);
	public:
		PhoneBook();
		~PhoneBook();
		void	start();
};

#endif