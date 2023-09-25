#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
}

void SpellBook::learnSpell(ASpell *aspell)
{
	if (aspell)
		_arr[aspell->getName()] = aspell->clone();
}

void SpellBook::forgetSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator it = _arr.find(spell);
	if (it != _arr.end())
		delete it->second;
	_arr.erase(spell);
}

ASpell *SpellBook::createSpell(std::string const &spell)
{
	if (_arr.find(spell) != _arr.end())
		return _arr[spell];
	return NULL;
}
