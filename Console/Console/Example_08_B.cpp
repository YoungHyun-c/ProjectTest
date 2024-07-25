#include <iostream>
#include <vector>

using namespace std;

#pragma region 구조체
/*
구조체 : Struct
-> 하나 이상의 변수를 그룹화 해서 새로운 자료형으로 정의하는 것.

<구조체 선언>
struct 구조체 이름 (구조체 내용);
 -> 구조체 내용으로는 변수와 함수가 포함이 가능.
 -> 구조체에 포함한 변수를 멤버 변수, 포함된 함수를 멤버함수라고함.


 자료형 재정의
 자료형의 별칭을 생성하고, 실제 자료형 이름 대신 사용
 <typedef 자료형 별칭>
*/
// 고전 스타일
typedef int MyInt_t;		// 자료형의 재정의는 _t로 끝내는것을 권장
typedef unsigned long long uint64_t;	// 특정한 자료형의 간소화 버전.

// C++11 도입된 스타일
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
// 생성자가 있는 구조체
// <구조체 생성자>
// 반환형 없이 구조체의 이름의 함수를 구현하여 사용.
struct Monster
{
	string Name;
	int Hp;
	int Mp;

	Monster()
	{
		Name = "몬스터";
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
	cout << "이름 : " << Name << endl;
	cout << "나이 : " << Age << endl;
	cout << "관계 : " << RelationShip << endl;
	cout << "직업 : " << Job << endl;
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
	// 구조체의 변수.
	Point P;
	P.x = 10;
	P.y = 20;

	cout << "구조체 p.x의 값 : " << P.x << endl;
	cout << "구조체 p.y의 값 : " << P.y << endl;
	P.Print();

	Point p1 = { 50, 120 }; // 생성과 동시에 초기화.

	Monster monster;
	Monster dragon = Monster("드래곤", 250, 100);
	Monster slime = Monster("슬라임", 100, 3);

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

	MyFamily Father = { "홍사장", "부", "사장님", 62 };
	MyFamily Mother = { "이미숙", "모", "어린이집 교사", 59 };
	MyFamily Brother = { "홍성현", "형", "미술전공 대학원 유학생", 32 };
	MyFamily Me = { "홍영현", "나", "개발자", 28 };

	Father.Print();
	Mother.Print();
	Brother.Print();
	Me.Print();

	Integer H = 30;

	return 0;
}
void Point::Print()
{
	cout << "포인트 구조체 멤버 함수임";
}

// 지금 해볼것.
// 구조체를 활용해서 가족 관계를 출력해보세용.

// 구조체 메모리 패딩.


/*
카드게임 만들기
트럼프카드는 52장
예를 들어서 만약 다음과 같은 카드가 나왔다면(출력)
아래와 같이 보여지는 카드는 컴퓨터가 낸다고 가정함.
♧7	♤8	♡9 

♤8 이기는 조건 -> 범위 안에 들어오는 숫자가 들어오면, 이기는 것. 배팅액 * 3배
만약 숫자가 동일하면 지는 것. -> 배팅액만큼 소진
만약 범위안에 들어오지 않았다면 배팅액 * 2 차감

조건) 한번 사용한 카드는 버려야 됩니다. (사용하지 않는것 뿐)
판수 -> 17판 52장 / 3 17판 돌리면 자동으로 끝나야함. (3장의 카드를 한턴마다 소비하므로)
소지금만원이 있다면,
최소 배팅금액, 최대 배팅금액. 최소 배팅금액보다 소지금액이 적어지면 파산, 종료.

♧7가 나왔다면 두번다시 ♧7는 사용하지 않는다.

♧ 1A 2 3 4 5 6 7 8 9 10 11J 12Q 13K


*/