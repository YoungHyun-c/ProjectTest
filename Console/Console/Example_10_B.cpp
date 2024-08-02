#include <iostream>

/*
================================
constructor (������)
-> ��ü�� ������ �� �ڵ����� ȣ��Ǵ� Ư���� ����Լ�.
-> ��ü�� �ʱ�ȭ�� ����ϰ� Ŭ������ ������ �̸��� ������, ��ȯ��X
-> �����ڴ� �⺻������, �Ű������� �ִ� ������, ���������...
================================

������ ��� �ʱ�ȭ ����Ʈ
-> �̳༮�� ����ϸ�, ����� ��������� �ʱ�ȭ �� �� �ִ�.
-> ������ �Ű����� �ڿ� ���Եǰ� :(�ݷ�)���� ������ ����
�ʱ�ȭ �� �� ������ ��ǥ�� �����Ͽ� ����
-> ��������� �����ǰ� ���߿� ���� �����ϴ°ͺ��� ȿ�����̴�.
��� �� ���� ��������� �ʱ�ȭ
�� const �������, ���� ����� �ݵ�� �̳༮�� ���� �ʱ�ȭ �ؾ���.
������ �����ȿ����� �Ұ�.
*/


class Exam
{
public:
	const int num;
	int& Score;
	//Error
	//Exam()
	//{
	//	num = 1;
	//	Score = 2;
	//}

	Exam(int _num, int _score) :num(_num), Score(_score)
	{

	}
};

class Monster
{
public :
	std::string Name;
	int Atk;
	int Def;

	// ������ ��� �ʱ�ȭ ����Ʈ
	Monster(const std::string& _Name, int _Atk, int _Def)
		: Name(_Name), Atk(_Atk), Def(_Def)
	{
		// ���⼭ �� �ʿ䰡 ���� ���ٴ� ��.
	}


};



class Player
{
public:
	std::string name;
	int mAtk;
	int mDef;
	//const int a; -> ����
	//int& b; -> ����

	Player()
	{
		name = "����";
		mAtk = 10;
		mDef = 20;
	}
	// �Ű������� �ִ� ������.
	Player(const std::string& _PlayerName, int _PlayerAtk, int _PlayerDef)
	{
		name = _PlayerName;
		mAtk = _PlayerAtk;
		mDef = _PlayerDef;
	}

	void printInfo() const; // ����Լ��� ��ü ���¸� �������� �ʰڴٴ� �ǹ�.
};


int main()
{
	Player* player = new Player();
	player->printInfo();


	Player* player1 = new Player("ī����", 10, 50);
	player1->printInfo();

	delete player;
	player = nullptr;

	delete player1;
	player1 = nullptr;


	return 0;
}

void Player::printInfo() const
{
	std::cout << name << std::endl;
	std::cout << mAtk << std::endl;
	std::cout << mDef << std::endl;
}