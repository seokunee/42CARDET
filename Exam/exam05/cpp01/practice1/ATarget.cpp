#include "ATarget.hpp"

ATarget::ATarget()
{
}

ATarget::~ATarget()
{
}

ATarget::ATarget(const std::string &type)
{
	_type = type;
}

ATarget::ATarget(const ATarget &src)
{
	*this = src;
}

ATarget &ATarget::operator=(const ATarget &src)
{
	_type = src._type;
	return *this;
}

const std::string &ATarget::getType() const
{
	return _type;
}

void ATarget::getHitBySpell(const ASpell &aspell)
{
	std::cout << _type << " has been " << aspell.getEffects() << "!" << std::endl;
}
