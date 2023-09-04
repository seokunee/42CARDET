#include "ASpell.hpp"

ASpell::ASpell()
{
}

ASpell::~ASpell()
{
}

ASpell &ASpell::operator=(const ASpell &src)
{
	_name = src._name;
	_effects = src._effects;
	return *this;
}

ASpell::ASpell(const ASpell &src)
{
	_name = src._name;
	_effects = src._effects;
}

std::string &ASpell::getName()
{
	return _name;
}

std::string &ASpell::getEffects()
{
	return _effects;
}

ASpell::ASpell(const std::string &name, const std::string &effects)
{
	_name = name;
	_effects = effects;
}

void ASpell::launch(const ATarget &atarget)
{
	atarget.getHitBySpell(*this);
}