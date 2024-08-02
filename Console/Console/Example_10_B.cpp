#include <iostream>

/*
================================
constructor (생성자)
-> 객체가 생성될 때 자동으로 호출되는 특별한 멤버함수.
-> 객체의 초기화를 담당하고 클래스와 동일한 이름을 가지며, 반환형X
-> 생성자는 기본생성자, 매개변수가 있는 생성자, 복사생성자...
================================

생성자 멤버 초기화 리스트
-> 이녀석을 사용하면, 상수와 참조멤버를 초기화 할 수 있다.
-> 생성자 매개변수 뒤에 삽입되고 :(콜론)으로 시작한 다음
초기화 할 각 변수를 쉼표로 구분하여 나열
-> 멤버변수가 생성되고 나중에 값을 변경하는것보다 효율적이다.
상수 및 참조 멤버변수는 초기화
ㄴ const 멤버변수, 참조 멤버는 반드시 이녀석을 통해 초기화 해야함.
생성자 본문안에서는 불가.
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

	// 생성자 멤버 초기화 리스트
	Monster(const std::string& _Name, int _Atk, int _Def)
		: Name(_Name), Atk(_Atk), Def(_Def)
	{
		// 여기서 할 필요가 전혀 없다는 뜻.
	}


};



class Player
{
public:
	std::string name;
	int mAtk;
	int mDef;
	//const int a; -> 오류
	//int& b; -> 오류

	Player()
	{
		name = "윈터";
		mAtk = 10;
		mDef = 20;
	}
	// 매개변수가 있는 생성자.
	Player(const std::string& _PlayerName, int _PlayerAtk, int _PlayerDef)
	{
		name = _PlayerName;
		mAtk = _PlayerAtk;
		mDef = _PlayerDef;
	}

	void printInfo() const; // 멤버함수가 객체 상태를 변경하지 않겠다는 의미.
};


int main()
{
	Player* player = new Player();
	player->printInfo();


	Player* player1 = new Player("카리나", 10, 50);
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