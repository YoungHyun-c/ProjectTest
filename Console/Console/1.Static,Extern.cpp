#include <iostream>

/*
static,

extern 외부변수
다른 파일에 정의된 전역변수를 현재 파일에도 사용할 수 있게 해준다.
단점 :
1. 결정적으로 전역변수를 많이 쓰게 된다.
2. 남발하게 되면, 유지보수가 힘들어진다.


*/

// staticVariale.cpp 안에 있는 전역변수를 참조
extern int num1;

void Count();
static int sNum;

//============================================
// 클래스 내의 static?
// 클래스 내부에서 static으로 선언된 변수는 해당 클래스의
// 모든 인스턴스에서 공유가됨. 클래스의 인스턴스끼리 공통으로 사용되는 변수.
// 그렇다는건 클래스의 인스턴스가 없이도 가능함.

// 선언 방법
// 클래스 내부에서 static을 사용하여 선언.
// 이 선언은 컴파일러한테, 해당 클래스에 정적 멤버변수가 있음을 알려줌.

// 외부에서 초기화해야함.
// 범위지정연산자 ::을 사용해서 초기화를 해야함.

//============================================

class Character
{
private:
	static int count;

	int num = 0;
public:
	Character()
	{
		count++;
	}
	// 함수 앞에 static을 붙이면, 클래스의 인스턴스 없이 부를 수 있다.
	// 공통적인 작업을 할때 만들어 쓰면 된다.
	static void PrintCount()
	{
		std::cout << count << std::endl;
		// 일반 멤버 변수를 호출할 수 없다.
		// std::cout << num << std::endl; // -> Error static(정적) 멤버함수에서는 static 멤버변수나, 멤버함수만 호출 가능하다.
	}


};
int Character::count = 0; // 범위지정연산자를 통해서 초기화를 한다.

int main()
{
	Count();
	Count();
	Count();

	Character::PrintCount();
	Character::Character();
	Character::PrintCount();

	return 0;
}

void Count()
{
	static int x = 0; // 정적
	int y = 0; //지역
	x = x + 1;
	y = y + 1;

	std::cout << "X값 : " << x << "Y값 : " << y << std::endl;
}