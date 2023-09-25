#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::~Fwoosh()
{
}

virtual ASpell *Fwoosh::clone() const
{
	return new Fwoosh();
}
