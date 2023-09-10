#ifndef FWOOSH_HPP
#define FWOOSH_HPP
#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
private:
public:
	Fwoosh();
	virtual ~Fwoosh();

	ASpell *clone() const;
};

#endif
