#include <iostream>

/*
�θ� - �ڽ�.
Ŭ�������� ��Ӱ��踦 ���� ����, ������ �����
���� Ŭ������ ���� �־� �ٸ� Ŭ������ Ȯ���� �� �ְ� �ϴ� ���� �ֵ� ����
���� Ŭ�������� ���� ����� �Ǵ� ������ ���� �ڵ带 ������ �ִٸ�,
�ش� �ڵ带 ���� Ŭ������ ���� ���� ���� ����ϴ°� ����.

Player,
-> �̸�, ���ݷ�, ���� �� �Ӽ�.
-> �����ϱ�, ��ų, ��������. ��� �ൿ�� �����ִ�.
Monster,
-> �̸�, ���ݷ�, ���� �� �Ӽ�.
-> �����ϱ�, ��ų, ��������. ��� �ൿ�� �����ִ�.

*/

// �θ�, �ڽ�
class Parent {
public:
	int publicValue;

	Parent() : publicValue(1), ProtectedValue(2), PrivateValue(3) {}

	void ShowValues()
	{
		std::cout << "�θ� Ŭ���� public�� : " << publicValue << std::endl;
		std::cout << "�θ� Ŭ���� Protected�� : " << ProtectedValue << std::endl;
		std::cout << "�θ� Ŭ���� private�� : " << PrivateValue << std::endl;
	}

protected:
	int ProtectedValue;

private:
	int PrivateValue;

};

// �ڽ� : �������������� �θ�Ŭ����
class ChildPublic : public Parent
{
public:
	void ShowValues()
	{
		std::cout << "�ڽ�Ŭ���������� public�� : " << publicValue << std::endl;
		std::cout << "�ڽ�Ŭ���������� protected�� : " << ProtectedValue << std::endl;
		// �ƹ��� �ڽĿ��� �����ش� �ѵ�, �翬�� �ȵȴ�.
		// �ڽĿ��� ���� �Ұ�.
		// std::cout << "�ڽ�Ŭ���������� private�� : " << PrivateValue << std::endl;
	}
};

class ChildProtected : protected Parent
{
public:
	void ShowValues()
	{
		std::cout << "�ڽ�Ŭ���������� public�� : " << publicValue << std::endl;
		std::cout << "�ڽ�Ŭ���������� protected�� : " << ProtectedValue << std::endl;
		// �ƹ��� �ڽĿ��� �����ش� �ѵ�, �翬�� �ȵȴ�.
		// �ڽĿ��� ���� �Ұ�.
		// std::cout << "�ڽ�Ŭ���������� private�� : " << PrivateValue << std::endl;
	}
};

class ChildPrivate : private Parent
{
public:
	void ShowValues()
	{
		std::cout << "�ڽ�Ŭ���������� public�� : " << publicValue << std::endl;
		std::cout << "�ڽ�Ŭ���������� protected�� : " << ProtectedValue << std::endl;
		// �ƹ��� �ڽĿ��� �����ش� �ѵ�, �翬�� �ȵȴ�.
		// �ڽĿ��� ���� �Ұ�.
		// std::cout << "�ڽ�Ŭ���������� private�� : " << PrivateValue << std::endl;
	}
};


#pragma region ����� �����ʾ�����
class Warrior1
{
	std::string name;
	int health;
public:
	Warrior1(const std::string& n, const int health) : name(n), health(health) {}

	void Attack()
	{
		std::cout << name << " ��(��) Į�� �ֵθ��ϴ�" << std::endl;
	}
	void TakeDamage(const int damage)
	{
		health -= damage;
		std::cout << name << "��(��)" << damage << "��ŭ ������ ���� ! ü�� : " << health << std::endl;
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
		std::cout << name << " ��(��) ��������!" << std::endl;
	}
	void TakeDamage(const int damage)
	{
		health -= damage;
		std::cout << name << "��(��)" << damage << "��ŭ ������ ���� ! ü�� : " << health << std::endl;
	}
};
#pragma endregion

#pragma region ����� ������
class Character
{
public:
	std::string name;
	int health;

	Character(const std::string& n, const int health) : name(n), health(health) {}

	void TakeDamage(const int damage)
	{
		health -= damage;
		std::cout << name << "��(��)" << damage << "��ŭ ������ ���� ! ü�� : " << health << std::endl;
	}
};

class Warrior : public Character
{
public:
	// Character(n, h) : �ڽ�Ŭ������ Warrir���� �θ�Ŭ������ Character�� �����ڸ� ȣ��.
	// ��� ���迡�� �����ڴ�
	// �θ� -> �ڽ�
	// �ڽ� Ŭ������ ���� �Ǳ� ����, �θ� Ŭ������ ���� �ʱ�ȭ �� ���̴�. ����
	Warrior(const std::string& n, const int h) : Character(n, h) {};
	void Attack()
	{
		std::cout << name << " ��(��) Į�� �ֵθ��ϴ�" << std::endl;
	}
};

// ���� ����� �����ϴ�.
// ���� ����� �˰� ���� ��������, ��ȣ���� �߻��� �� �ִ�.
// �� �θ� ������ Ȯ���� �� �Ǵ� ��찡 �߻�.
class Mage : public Character
{
public:
	// Character(n, h) : �ڽ�Ŭ������ Warrir���� �θ�Ŭ������ Character�� �����ڸ� ȣ��.
	// ��� ���迡�� �����ڴ�
	// �θ� -> �ڽ�
	// �ڽ� Ŭ������ ���� �Ǳ� ����, �θ� Ŭ������ ���� �ʱ�ȭ �� ���̴�. ����
	Mage(const std::string& n, const int h) : Character(n, h) {};
	void CastSkill()
	{
		std::cout << name << " ��(��) ��������!" << std::endl;
	}
};
// ��� ����� is - a ���踦 ��Ÿ����. ���� �����̴�. �ٳ����� �����̴� (���ok)
// has-a ����� ���� (ĸ��ȭ) ĳ���ʹ� ���⸦ �����ִ�. ���� 
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
	// ���Խ�Ű��.
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
	// �ڽĿ� �Ȱ��� �Լ��� ������, �ڽĿ� �ִ� �Լ��� ȣ���ϰ�, �ڽĿ��� �Լ��� ���������� �ʾҴٸ� �θ𲨸� ȣ���Ѵ�.
	c1.ShowValues();
	std::cout << c1.publicValue << std::endl;
	
	// std::cout << c1.protectedValue // -> Error Ŭ���� ���ο��� ����ϴ°��� �ƴ� �ܺο��� ����ϱ� ������.
	ChildProtected c2;
	c2.ShowValues();
	
	/*
	public ��� : 
	�θ� Ŭ������ public ����� �ڽ�Ŭ������ public����
	�θ� Ŭ������ protected ����� �ڽ�Ŭ������ protedted��
	�θ� Ŭ������ private ����� �ڽ�Ŭ���� ���� x

	Protected ��� :
	
	*/

	Warrior* W = new Warrior("����", 100);
	W->Attack(); // �ڽ��� ��� �ִ� ����Լ�.
	W->TakeDamage(10); // �θ� ��� �ִ� ����Լ�.

	return 0;
}