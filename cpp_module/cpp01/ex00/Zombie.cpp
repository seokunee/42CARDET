#include "Zombie.hpp"

Zombie::Zombie(void){
	name_ = "Extra";
}

Zombie::Zombie(std::string name){
	name_ = name;
}

Zombie::~Zombie(void){
	std::cout << name_ << " zombie is dead" << std::endl;
}

void	Zombie::announce(void) const{
	std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}