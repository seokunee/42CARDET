#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

#include <map>
class Warlock
{
private:
	std::string _name;
	std::string _title;
	Warlock();
	Warlock &operator=(const Warlock &src);
	Warlock(const Warlock &src);

	SpellBook _book;

public:
	virtual ~Warlock();
	Warlock(std::string name, std::string title);

	const std::string &getName() const;
	const std::string &getTitle() const;

	void setTitle(const std::string &title);

	void introduce() const;

	void learnSpell(ASpell *aspell);
	void forgetSpell(std::string spell_name);
	void launchSpell(std::string spell_name, const ATarget &atarget);
};

#endif