#include "Warlock.hpp"
// #include <utility>
Warlock::Warlock(const std::string &name, const std::string &title)
{
	_name = name;
	_title = title;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName() const
{
	return _name;
}

std::string const &Warlock::getTitle() const
{
	return _title;
}

void Warlock::setTitle(std::string const &title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *aspell)
{
	if (aspell)
		arr.insert(std::pair<std::string, ATarget *>(aspell->getName(), aspell->clone()));
}

void Warlock::forgetSpell(std::string name)
{
	std::map<std::string, ATarget *>::iterator *it = arr.find(name);
	if (it != arr.end())
		delete it->second;
	arr.erase(name);
}

void Warlock::launchSpell(std::string name, const ATarget &atarget)
{
	ASpell *spell = arr[name];
	if (spell)
		spell->launch(atarget);
}
