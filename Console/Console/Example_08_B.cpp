#include <iostream>
#include <vector>

using namespace std;

#pragma region ����ü
/*
����ü : Struct
-> �ϳ� �̻��� ������ �׷�ȭ �ؼ� ���ο� �ڷ������� �����ϴ� ��.

<����ü ����>
struct ����ü �̸� (����ü ����);
 -> ����ü �������δ� ������ �Լ��� ������ ����.
 -> ����ü�� ������ ������ ��� ����, ���Ե� �Լ��� ����Լ������.


 �ڷ��� ������
 �ڷ����� ��Ī�� �����ϰ�, ���� �ڷ��� �̸� ��� ���
 <typedef �ڷ��� ��Ī>
*/
// ���� ��Ÿ��
typedef int MyInt_t;		// �ڷ����� �����Ǵ� _t�� �����°��� ����
typedef unsigned long long uint64_t;	// Ư���� �ڷ����� ����ȭ ����.

// C++11 ���Ե� ��Ÿ��
using Integer = int;

using StringList = vector<string>;

struct Student
{
	string Name;
	int math;
	int english;
	int science;

	float Average()
	{
		return(math + english + science) / 3.0f;
	}
};
struct Point
{
	int x;
	int y;

	void Print();
};
// �����ڰ� �ִ� ����ü
// <����ü ������>
// ��ȯ�� ���� ����ü�� �̸��� �Լ��� �����Ͽ� ���.
struct Monster
{
	string Name;
	int Hp;
	int Mp;

	Monster()
	{
		Name = "����";
		Hp = 10;
		Mp = 20;
	}
	Monster(std::string _Name, int _Hp, int _Mp)
	{
		Name = _Name;
		Hp = _Hp;
		Mp = _Mp;
	}
};

#pragma endregion

struct MyFamily
{
	std::string Name;
	std::string RelationShip;
	std::string Job;
	int Age;

	void Print();
};
void MyFamily::Print()
{
	cout << "�̸� : " << Name << endl;
	cout << "���� : " << Age << endl;
	cout << "���� : " << RelationShip << endl;
	cout << "���� : " << Job << endl;
	cout << endl;
}

struct Example
{
	char a;
	int b;
	char c;
};

int main()
{
	// ����ü�� ����.
	Point P;
	P.x = 10;
	P.y = 20;

	cout << "����ü p.x�� �� : " << P.x << endl;
	cout << "����ü p.y�� �� : " << P.y << endl;
	P.Print();

	Point p1 = { 50, 120 }; // ������ ���ÿ� �ʱ�ȭ.

	Monster monster;
	Monster dragon = Monster("�巡��", 250, 100);
	Monster slime = Monster("������", 100, 3);

	cout << monster.Name << endl;
	cout << monster.Hp << endl;
	cout << monster.Mp << endl;

	cout << "=============================" << endl;

	cout << dragon.Name << endl;
	cout << dragon.Hp << endl;
	cout << dragon.Mp << endl;

	cout << "=============================" << endl;

	cout << slime.Name << endl;
	cout << slime.Hp << endl;
	cout << slime.Mp << endl;

	MyFamily Father = { "ȫ����", "��", "�����", 62 };
	MyFamily Mother = { "�̹̼�", "��", "����� ����", 59 };
	MyFamily Brother = { "ȫ����", "��", "�̼����� ���п� ���л�", 32 };
	MyFamily Me = { "ȫ����", "��", "������", 28 };

	Father.Print();
	Mother.Print();
	Brother.Print();
	Me.Print();

	Integer H = 30;

	return 0;
}
void Point::Print()
{
	cout << "����Ʈ ����ü ��� �Լ���";
}

// ���� �غ���.
// ����ü�� Ȱ���ؼ� ���� ���踦 ����غ�����.

// ����ü �޸� �е�.


/*
ī����� �����
Ʈ����ī��� 52��
���� �� ���� ������ ���� ī�尡 ���Դٸ�(���)
�Ʒ��� ���� �������� ī��� ��ǻ�Ͱ� ���ٰ� ������.
��7	��8	��9 

��8 �̱�� ���� -> ���� �ȿ� ������ ���ڰ� ������, �̱�� ��. ���þ� * 3��
���� ���ڰ� �����ϸ� ���� ��. -> ���þ׸�ŭ ����
���� �����ȿ� ������ �ʾҴٸ� ���þ� * 2 ����

����) �ѹ� ����� ī��� ������ �˴ϴ�. (������� �ʴ°� ��)
�Ǽ� -> 17�� 52�� / 3 17�� ������ �ڵ����� ��������. (3���� ī�带 ���ϸ��� �Һ��ϹǷ�)
�����ݸ����� �ִٸ�,
�ּ� ���ñݾ�, �ִ� ���ñݾ�. �ּ� ���ñݾ׺��� �����ݾ��� �������� �Ļ�, ����.

��7�� ���Դٸ� �ι��ٽ� ��7�� ������� �ʴ´�.

�� 1A 2 3 4 5 6 7 8 9 10 11J 12Q 13K


*/