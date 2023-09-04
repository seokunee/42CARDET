#include "ATarget.hpp"

ATarget::ATarget()
{
}

ATarget::~ATarget()
{
}

ATarget &ATarget::operator=(const ATarget &src)
{
	_type = src._type;
	return *this;
}

ATarget::ATarget(const ATarget &src)
{
	_type = src._type;
}

std::string &ATarget::getType()
{
	return _type;
}

ATarget::ATarget(const std::string &type)
{
	_type = type;
}

void ATarget::getHitBySpell(const ASpell &aspell)
{
	std::cout << _type << " has been " << aspell.getEffects() << std::endl;
}
