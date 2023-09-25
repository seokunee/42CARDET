#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
private:
	std::string _name;
	std::string _title;

public:
	Warlock();
	~Warlock();
	Warlock(const Warlock &src);
	Warlock &operator=(const Warlock &src);

	const std::string &getName();
	const std::string &getName();
};

#endif