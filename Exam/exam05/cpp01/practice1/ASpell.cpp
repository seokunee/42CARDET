#include "ASpell.hpp"

ASpell::ASpell()
{
}

ASpell::~ASpell()
{
}

ASpell::ASpell(const std::string &name, const std::string &effects)
{
	_name = name;
	_effects = effects;
}

ASpell::ASpell(const ASpell &src)
{
	*this = src;
}

ASpell &ASpell::operator=(const ASpell &src)
{
	_name = src._name;
	_effects = src._effects;
	return *this;
}

const std::string &ASpell::getName() const
{
	return _name;
}

const std::string &ASpell::getEffects() const
{
	return _effects;
}
