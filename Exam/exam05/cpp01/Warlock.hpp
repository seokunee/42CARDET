#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>

class ASpell;
class ATarget;

class Warlock
{
private:
	std::string _name;
	std::string _title;
	Warlock();
	Warlock(const Warlock &src);
	Warlock &operator=(const Warlock &src);

	std::map<std::string, ATarget *> arr;

public:
	virtual ~Warlock();
	Warlock(const std::string &name, const std::string &title);
	std::string const &getName() const;
	std::string const &getTitle() const;

	void setTitle(std::string const &title);
	void introduce() const;

	void learnSpell(ASpell *aspell);
	void forgetSpell(std::string name);
	void launchSpell(std::string name, const ATarget &atarget);
};

#include "ASpell.hpp"
#include "ATarget.hpp"

#endif