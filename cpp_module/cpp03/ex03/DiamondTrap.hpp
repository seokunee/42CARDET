/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:17:15 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/22 02:28:30 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &src);
		void attack(const std::string& target);
		void whoAmI();
		void checkStatus();
};

#endif

// 이 연습에서, 여러분은 괴물을 만들 것입니다: 반은 FragTrap, 반은 ClapTrap입니다
// 스캐빈트랩. DiamondTrap이라는 이름이 될 것이고, 두 FragTrap으로부터 상속받을 것이다
// 그리고 Scav Trap. 이건 너무 위험해요!
// DiamondTrap 클래스에는 이름 개인 속성이 있습니다. 이 속성에 제공
// 정확히 동일한 변수의 이름(여기서 로봇 이름에 대해 말하지 않음)
// ClapTrap 베이스 클래스에 있습니다.
// 좀 더 명확하게 말하자면, 여기 두 가지 예가 있다.
// ClapTrap의 변수가 name인 경우 DiamondTrap의 변수에 이름을 지정합니다.
// ClapTrap의 변수가 _name이면 DiamondTrap 중 하나에 _name이라는 이름을 붙입니다.
// 속성 및 멤버 함수는 상위 클래스 중 하나에서 선택됩니다:
// • 생성자에게 매개 변수로 전달되는 이름
// • ClapTrap::name(생성자 매개 변수 + "_clap_name" 접미사)
// • 적중 지점(FragTrap)
// • 에너지 포인트(ScavTrap)
// • 공격 데미지(FragTrap)
// • 공격()(Scavtrap)
// 두 부모 클래스의 특별한 기능 외에도, DiamondTrap은 다음과 같은 기능을 가질 것이다
// 자체 특별 용량:
// 누구를 무효로 하다I();
// 이 멤버 함수는 이름과 ClapTrap 이름을 모두 표시합니다.
// 물론 DiamondTrap의 ClapTrap 하위 개체는 한 번만 생성되고
// 한 번. 네, 속임수가 있어요.
// 다시 한 번, 프로그램에 테스트를 추가합니다.
