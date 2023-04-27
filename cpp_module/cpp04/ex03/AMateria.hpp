/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:51:49 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/25 22:34:31 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
protected:
  std::string _type;

public:
  AMateria(std::string const &type);
  AMateria(AMateria const &obj);
  virtual ~AMateria();
  AMateria &operator=(const AMateria &src);
  std::string const &getType() const;
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif
