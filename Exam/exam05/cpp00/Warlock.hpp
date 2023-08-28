#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
private:
	std::string _name;
	std::string _title;
	Warlock();
	Warlock(const Warlock &src);
	Warlock &operator=(const Warlock &src);

public:
	virtual ~Warlock();
	Warlock(const std::string &name, const std::string &title);
	std::string const &getName() const;
	std::string const &getTitle() const;

	void setTitle(std::string const &title);
	void introduce() const;
};

#endif