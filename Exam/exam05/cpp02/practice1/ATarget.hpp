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
	ATarget(const std::string &type);
	ATarget(const ATarget &src);
	ATarget &operator=(const ATarget &src);

	const std::string &getType() const;

	virtual ATarget *clone() const = 0;

	void getHitBySpell(const ASpell &aspell) const;
};

#include "ASpell.hpp"

#endif
