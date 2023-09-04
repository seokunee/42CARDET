#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

class ATarget;

class ASpell
{
private:
	std::string _name;
	std::string _effects;

public:
	ASpell();
	virtual ~ASpell();
	ASpell &operator=(const ASpell &src);
	ASpell(const ASpell &src);

	std::string &getName();
	std::string &getEffects();
	virtual ASpell *clone() const = 0;

	ASpell(const std::string &name, const std::string &effects);
	void launch(const ATarget &atarget);
};

#include "ATarget.hpp"

#endif