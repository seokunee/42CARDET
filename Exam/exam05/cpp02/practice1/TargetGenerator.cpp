#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget *atarget)
{
	if (atarget)
		_arr[atarget->getType()] = atarget;
}

void TargetGenerator::forgetTargetType(std::string const &type)
{
	if (_arr.find(type) != _arr.end())
		delete _arr[type];
	_arr.erase(type);
}

ATarget *TargetGenerator::createTarget(std::string const &target)
{
	if (_arr.find(target) != _arr.end())
		return _arr[target];
	return NULL;
}
