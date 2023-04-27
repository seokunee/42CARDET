/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:44:20 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/25 22:34:20 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_sources[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	~MateriaSource();
	MateriaSource &operator=(const MateriaSource &src);
	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);
};

#endif