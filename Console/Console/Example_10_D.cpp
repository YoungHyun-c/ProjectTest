#include <iostream>

// 멤버변수는 private
// 생성자, 소멸자, 멤버함수는 public
// 접근자(getter), 생성자(setter)
// 클래스에 접근하고, 수정하기 위한 녀석이다.
// 데이터의 캡슐화를 유지하면서, 멤버변수의 값을 외부에서 값을 읽거나 수정할 때 사용한다.
class Person
{
private:
	std::string Name;
	int age = 0;

public:
	// getter
	std::string GetName() const
	{
		return Name;
	}
	// setter
	void SetName(const std::string& Name)
		// Person::
	{
		// this는 내 자신을 가리키는 pointer
		// Person::Name = Name;
		this->Name = Name;
	}
};

int main()
{
	Person p;
	p.SetName("d");
	std::cout << p.GetName() << std::endl;


	return 0;
}
// 클래스는 설계도.
// 객체를 찍어내기 위한 녀석.
// 구조체와 클래스의 차이는 기본 접근제어지시자가 다르다.
// 접근제어 지시자는 private, public, protected(상속)
// 프라이빗은 오로지 클래스 내부에서만 접근 가능(멤버변수를)
// public은 클래스 내, 외부에서 접근이 가능.(외부에 공개할 멤버함수, 생성자, 소멸자)
// protected는 상속관계에서 활용되며, 클래스 내부와 상속관계에서 접근을 허용한다.
// 생성자는 기본적으로 무조건적으로 호출되며, 없는 경우 컴파일러가 알아서 생성한다.
// 생성자는 일반적으로 멤버들을 초기화 할 때 사용하며, 멤버 이니셜라이즈 리스트를 사용하는게
// 효율적이다. (상수와 참조변수들은 반드시 이녀석을 이용해야함.)
// 소멸자는 생성자와, 마찬가지로 자동으로 호출되며(객체가 소멸 될때)
// 이곳에 메모리해제를 할 때 사용.
// 생성자->소멸자 순으로 호출.
// 생성자는 오버로딩이 가능하고, 소멸자는 불가능.
// 접근자, 설정자는 데이터 캡슐화를 보존하며, 외부에서 변경이 가능하다. /(멤버변수)

// const를 쓰는 버릇을 기르자. 제발

/*
주말맞이 과제.
1. 택1
슬라이드, 빙고, 월남뽕(카드게임)
셋중 한개를 클래스화 시킬 것.
동적할당도 활용하시고...

2. 대전게임
플레이어와 몬스터 각각의 클래스가 있다.
기본적으로 둘다. 공격력, 방어력, 체력을 갖고있다.
각각의 멤버변수는 무조건 private
멤버함수는 당연히 public
종료조건 둘중하나 죽으면 끝.

*/
