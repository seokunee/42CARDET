#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

class ASpell;

class ATarget
{
protected:
	std::string _type;

public:
	ATarget();
	virtual ~ATarget();
	ATarget(const ATarget &src);
	ATarget &operator=(const ATarget &src);

	ATarget(std::string type);

	const std::string &getType() const;

	virtual ATarget *clone() const = 0;

	void getHitBySpell(const ASpell &aspell) const;
};

#include "ASpell.hpp"

#endif