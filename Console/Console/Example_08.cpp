#include <iostream>

using namespace std;

/*
사용자 정의 자료형
 ㄴ 구조체, 공용체, 열거형, 클래스가 있다.


*/

#pragma region C_Enum
/*
	1. 열거형
	 -> 관련된 상수들을 하나의 그룹으로 묶는다.
	 -> 코드의 가독성을 높이고 의미있는 이름을 부여할 수 있다.
*/
// 기본선언 방법
enum Color
{
	Red = 0x00000000,
	Green,
	White
};
// 같은 이름을 부여하여 모호해진다. 오류!
//enum RGB
//{
//	Red,
//	Green,
//	White
//};
// 명시적인 값을 할당.
enum Direction
{
	Left,
	Right = 2,
	Up,
	Down
};
#pragma endregion


#pragma region enumClass 자신만의 영역이 있다
enum class MyColor
{
	Red,
	Green,
	White,
};
/*
자신만의 스코프를 가지고 있다.
즉 같은 이름의 열거형 상수가 다른 열거형과 충돌하지 않는다.
타입의 안전성을 보장한다. -> 암시적 형변환이 안된다.
*/
#pragma endregion

enum class SkillType
{
	Fire,
	Ice,
	Lighting,
};

void UseSkill(SkillType _Skill);

int main()
{
	/*Color color = Red;

	if (color == Red)
	{
		cout << "빨강" << endl;
	}
	else if(color == Green)
	{
		cout << "녹색" << endl;
	}*/


	Direction Key = Left;

	switch (Key)
	{
	case Left:
		cout << "왼쪽으로 이동" << endl;
		break;
	case Right:
		cout << "오른쪽으로 이동" << endl;
		break;
	case Up:
		cout << "위쪽으로 이동" << endl;
		break;
	case Down:
		cout << "아래쪽으로 이동" << endl;
		break;
	default:
		break;
	}

	// int Rcolor = Red; 어떤 Red 인지 몰라 오류.


	// 범위 지정을 명확히 해줘야 한다.
	MyColor Color = MyColor::Red; // :: 범위 지정 (나 여기 안에 있어)
	// int C = MyColor::Red; // 타입의 안전성으로 인해 암시적 형변환이 불가능하다. 오류!
	// 즉 명시적으로 형변환을 해줘야 한다.
	int A = static_cast<int>(MyColor::Red);


	return 0;
}


void UseSkill(SkillType _Skill)
{
	switch (_Skill)
	{
	case SkillType::Fire:
		break;
	case SkillType::Ice:
		break;
	case SkillType::Lighting:
		break;
	default:
		break;
	}
}
// 요약
/*
enum은 열거형 상수가 전역스코프에 해당함.
암묵적인 형변환을 허용->타입에 대한 안전성이 낮다.

enumclass는 열거형 자체의 스코프에 해당함.
암묵적인 형변환을 허용하지 않는다. -> 타입에 대한 안전성을 보장한다.

*/