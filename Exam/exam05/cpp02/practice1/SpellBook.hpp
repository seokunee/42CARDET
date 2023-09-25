#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ATarget.hpp"
#include "ASpell.hpp"
#include <map>

class SpellBook
{
private:
	SpellBook(const SpellBook &src);
	SpellBook &operator=(const SpellBook &src);

	std::map<std::string, ASpell *> _arr;

public:
	SpellBook();
	virtual ~SpellBook();

	void learnSpell(ASpell *aspell);
	void forgetSpell(std::string const &spell);
	ASpell *createSpell(std::string const &spell);
};

#endif