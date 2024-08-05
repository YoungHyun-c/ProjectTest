#include <iostream>

/*
부모 - 자식.
클래스간의 상속관계를 맺을 때는, 공통의 기능을
상위 클래스에 묶어 넣어 다른 클래스로 확장할 수 있게 하는 것이 주된 목적
만약 클래스들이 서로 비슷한 또는 완전히 같은 코드를 가지고 있다면,
해당 코드를 상위 클래스로 묶어 내는 것을 고려하는게 좋다.

Player,
-> 이름, 공격력, 방어력 등 속성.
-> 공격하기, 스킬, 도망간다. 등등 행동을 갖고있다.
Monster,
-> 이름, 공격력, 방어력 등 속성.
-> 공격하기, 스킬, 도망간다. 등등 행동을 갖고있다.

*/

// 부모, 자식
class Parent {
public:
	int publicValue;

	Parent() : publicValue(1), ProtectedValue(2), PrivateValue(3) {}

	void ShowValues()
	{
		std::cout << "부모 클래스 public값 : " << publicValue << std::endl;
		std::cout << "부모 클래스 Protected값 : " << ProtectedValue << std::endl;
		std::cout << "부모 클래스 private값 : " << PrivateValue << std::endl;
	}

protected:
	int ProtectedValue;

private:
	int PrivateValue;

};

// 자식 : 접근제어지시자 부모클래스
class ChildPublic : public Parent
{
public:
	void ShowValues()
	{
		std::cout << "자식클래스에서의 public값 : " << publicValue << std::endl;
		std::cout << "자식클래스에서의 protected값 : " << ProtectedValue << std::endl;
		// 아무리 자식에게 물려준다 한들, 당연히 안된다.
		// 자식에서 접근 불가.
		// std::cout << "자식클래스에서의 private값 : " << PrivateValue << std::endl;
	}
};

class ChildProtected : protected Parent
{
public:
	void ShowValues()
	{
		std::cout << "자식클래스에서의 public값 : " << publicValue << std::endl;
		std::cout << "자식클래스에서의 protected값 : " << ProtectedValue << std::endl;
		// 아무리 자식에게 물려준다 한들, 당연히 안된다.
		// 자식에서 접근 불가.
		// std::cout << "자식클래스에서의 private값 : " << PrivateValue << std::endl;
	}
};

class ChildPrivate : private Parent
{
public:
	void ShowValues()
	{
		std::cout << "자식클래스에서의 public값 : " << publicValue << std::endl;
		std::cout << "자식클래스에서의 protected값 : " << ProtectedValue << std::endl;
		// 아무리 자식에게 물려준다 한들, 당연히 안된다.
		// 자식에서 접근 불가.
		// std::cout << "자식클래스에서의 private값 : " << PrivateValue << std::endl;
	}
};


#pragma region 상속을 쓰지않았을때
class Warrior1
{
	std::string name;
	int health;
public:
	Warrior1(const std::string& n, const int health) : name(n), health(health) {}

	void Attack()
	{
		std::cout << name << " 이(가) 칼을 휘두릅니다" << std::endl;
	}
	void TakeDamage(const int damage)
	{
		health -= damage;
		std::cout << name << "이(가)" << damage << "만큼 데미지 먹음 ! 체력 : " << health << std::endl;
	}
};
class Mage
{
	std::string name;
	int health;
public:
	Mage(const std::string& n, const int health) : name(n), health(health) {}
	void CastSkill()
	{
		std::cout << name << " 이(가) 얼음공격!" << std::endl;
	}
	void TakeDamage(const int damage)
	{
		health -= damage;
		std::cout << name << "이(가)" << damage << "만큼 데미지 먹음 ! 체력 : " << health << std::endl;
	}
};
#pragma endregion

#pragma region 상속을 썼을때
class Character
{
public:
	std::string name;
	int health;

	Character(const std::string& n, const int health) : name(n), health(health) {}

	void TakeDamage(const int damage)
	{
		health -= damage;
		std::cout << name << "이(가)" << damage << "만큼 데미지 먹음 ! 체력 : " << health << std::endl;
	}
};

class Warrior : public Character
{
public:
	// Character(n, h) : 자식클래스인 Warrir에서 부모클래스인 Character의 생성자를 호출.
	// 상속 관계에서 생성자는
	// 부모 -> 자식
	// 자식 클래스가 선언 되기 전에, 부모 클래스가 먼저 초기화 될 것이다. 보장
	Warrior(const std::string& n, const int h) : Character(n, h) {};
	void Attack()
	{
		std::cout << name << " 이(가) 칼을 휘두릅니다" << std::endl;
	}
};

// 다중 상속이 가능하다.
// 다중 상속을 알고 쓰면 괜찮은데, 모호함이 발생할 수 있다.
// 내 부모가 누군지 확인이 안 되는 경우가 발생.
class Mage : public Character
{
public:
	// Character(n, h) : 자식클래스인 Warrir에서 부모클래스인 Character의 생성자를 호출.
	// 상속 관계에서 생성자는
	// 부모 -> 자식
	// 자식 클래스가 선언 되기 전에, 부모 클래스가 먼저 초기화 될 것이다. 보장
	Mage(const std::string& n, const int h) : Character(n, h) {};
	void CastSkill()
	{
		std::cout << name << " 이(가) 얼음공격!" << std::endl;
	}
};
// 상속 관계는 is - a 관계를 나타낸다. 개는 동물이다. 바나나는 과일이다 (상속ok)
// has-a 관계는 포함 (캡슐화) 캐릭터는 무기를 갖고있다. 포함 
//
#pragma endregion

class Weapon {};

class Sw : public Weapon
{
public:
	void use();
};

class CCharacter
{
	// 포함시키기.
	Weapon* Weapon;
	Sw* s;
public:
	void attack()
	{
		s->use();
	}
};


int main()
{
	ChildPublic c1;
	// 자식에 똑같은 함수가 있으면, 자식에 있는 함수를 호출하고, 자식에서 함수를 재정의하지 않았다면 부모꺼를 호출한다.
	c1.ShowValues();
	std::cout << c1.publicValue << std::endl;
	
	// std::cout << c1.protectedValue // -> Error 클래스 내부에서 사용하는것이 아닌 외부에서 사용하기 때문에.
	ChildProtected c2;
	c2.ShowValues();
	
	/*
	public 상속 : 
	부모 클래스의 public 멤버는 자식클래스의 public으로
	부모 클래스의 protected 멤버는 자식클래스의 protedted로
	부모 클래스의 private 멤버는 자식클래스 접근 x

	Protected 상속 :
	
	*/

	Warrior* W = new Warrior("전사", 100);
	W->Attack(); // 자식이 들고 있는 멤버함수.
	W->TakeDamage(10); // 부모가 들고 있는 멤버함수.

	return 0;
}