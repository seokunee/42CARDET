#include "Warlock.hpp"

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	// std::map<std::string, ASpell *>::iterator it;
	// for (it = _arr.begin(); it != _arr.end(); it++)
	// {
	// 	delete it->second;
	// }
	// _arr.clear();
}

Warlock::Warlock(std::string name, std::string title)
{
	_name = name;
	_title = title;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

const std::string &Warlock::getName() const
{
	return _name;
}

const std::string &Warlock::getTitle() const
{
	return _title;
}

void Warlock::setTitle(const std::string &title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *aspell)
{
	_book.learnSpell(aspell);
	// if (aspell)
	// 	_arr[aspell->getName()] = aspell->clone();
	// if (aspell)
	// _arr.insert(std::pair<std::string, ASpell *>(aspell->getName(), aspell->clone()));
}

void Warlock::forgetSpell(std::string spell_name)
{
	_book.forgetSpell(spell_name);
	// std::map<std::string, ASpell *>::iterator it = _arr.find(spell_name);
	// if (it != _arr.end())
	// 	delete it->second;
	// _arr.erase(spell_name);
}

void Warlock::launchSpell(std::string spell_name, const ATarget &atarget)
{
	ASpell *tmp = _book.createSpell(spell_name);
	if (tmp)
		tmp->launch(atarget);

	// _book->createS
	// std::map<std::string, ASpell *>::iterator it = _arr.find(spell_name);
	// if (it != _arr.end())
	// it->second->launch(atarget);
}
