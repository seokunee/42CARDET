/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:17:38 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/22 16:09:31 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	private:

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		~FragTrap();

		FragTrap &operator=(const FragTrap &src);
		void highFivesGuys(void);
};

#endif

// 클랩트랩을 만드는 것은 아마도 여러분의 신경을 건드리기 시작할 것입니다.
// 이제 ClapTrap에서 상속되는 FragTrap 클래스를 구현합니다. 와 매우 유사하다
// 스캐빈트랩. 그러나, 그것의 건설과 파괴 메시지는 반드시 달라야 한다. 적절한
// 테스트에서 시공/파괴 체인이 표시되어야 합니다. FragTrap이 다음과 같은 경우
// 만들어진, 프로그램은 ClapTrap을 만드는 것으로 시작한다. 파괴는 역순이다.
// 속성에 대해서는 동일하지만 이번에는 값이 다릅니다:
// • 생성자에게 매개 변수로 전달되는 이름
// • 적중 지점(100), ClapTrap의 상태를 나타냅니다
// • 에너지 포인트(100)
// • 공격 데미지(30)
// FragTrap에는 특별한 용량도 있습니다:
// void 하이파이브 가이(void);
// 이 멤버 함수는 표준 출력에 양의 하이파이브 요청을 표시합니다.
// 다시 한 번, 프로그램에 테스트를 추가합니다.
