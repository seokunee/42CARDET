#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy()
{
}

virtual ATarget *Dummy::clone() const
{
	return new Dummy();
}
