/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/08/03 17:11:54 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
  {
    Weapon club = Weapon("crude spiked club1");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club1");
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spiked club2");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club2");
    jim.attack();
  }
}