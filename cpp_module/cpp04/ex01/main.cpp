/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:40 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/23 20:26:53 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	system("leaks animal");
	return (0);
}


// 각 클래스의 생성자 및 소멸자는 특정 메시지를 표시해야 합니다.
// 브레인 클래스를 구현합니다. 여기에는 아이디어라고 하는 100 std:: 문자열의 배열이 포함되어 있습니다.
// 이렇게 하면 Dog and Cat은 개인 Brain* 속성을 갖게 됩니다.
// 건설이 완료되면 개와 고양이는 새로운 뇌()를 사용하여 뇌를 생성합니다;
// 파괴되면 개와 고양이가 뇌를 삭제합니다.
// 기본 기능에서 동물 개체의 배열을 만들고 채웁니다. 절반은 할 것입니다
// 개 객체이고 나머지 절반은 고양이 객체입니다. 프로그램이 끝날 때
// 실행, 이 배열을 루프하고 모든 동물을 삭제합니다. 개를 직접 삭제해야 합니다
// 그리고 동물로서의 고양이들. 적절한 소멸자는 예상되는 순서대로 호출되어야 합니다.
// 메모리 누수 여부를 확인하는 것을 잊지 마십시오.
// 개나 고양이의 복제품은 얕아서는 안 됩니다. 따라서, 당신은 당신의 복사본을 테스트해야 합니다
// 딥 카피입니다!
