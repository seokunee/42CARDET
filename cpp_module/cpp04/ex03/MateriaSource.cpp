/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:46:12 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/27 14:08:36 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_sources[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_sources[i] != NULL)
			delete _sources[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		_sources[i] = src._sources[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (_sources[i] == NULL)
		{
			_sources[i] = materia;
			return;
		}
	}
	delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_sources[i] != NULL && _sources[i]->getType() == type)
		{
			return _sources[i]->clone();
		}
	}
	return NULL;
}
