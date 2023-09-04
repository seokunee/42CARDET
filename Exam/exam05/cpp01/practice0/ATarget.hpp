#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

class ASpell;

class ATarget
{
private:
	std::string _type;

public:
	ATarget();
	virtual ~ATarget();
	ATarget &operator=(const ATarget &src);
	ATarget(const ATarget &src);
	ATarget(const std::string &type);

	std::string &getType();

	void getHitBySpell(const ASpell &aspell);

	virtual ATarget *clone() const = 0;
};

#include "ASpell.hpp"

#endif