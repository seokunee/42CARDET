#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>

class ASpell
{
private:
	std::string _name;
	std::string _effects;

public:
	ASpell();
	virtual ~ASpell();
}

#endif