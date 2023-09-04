#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>

class ASpell
{
private:
	std::string _name;
	std::string _effects;

public:
	ASpell();
	virtual ~ASpell();
	ASpell(const std::string &name, const std::string &effects);
	ASpell(const ASpell &src);
	ASpell &operator=(const ASpell &src);

	const std::string &getName() const;
	const std::string &getEffects() const;

	virtual ASpell *clone() const = 0;
};

#endif
