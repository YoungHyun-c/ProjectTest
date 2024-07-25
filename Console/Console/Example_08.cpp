#include <iostream>

using namespace std;

/*
����� ���� �ڷ���
 �� ����ü, ����ü, ������, Ŭ������ �ִ�.


*/

#pragma region C_Enum
/*
	1. ������
	 -> ���õ� ������� �ϳ��� �׷����� ���´�.
	 -> �ڵ��� �������� ���̰� �ǹ��ִ� �̸��� �ο��� �� �ִ�.
*/
// �⺻���� ���
enum Color
{
	Red = 0x00000000,
	Green,
	White
};
// ���� �̸��� �ο��Ͽ� ��ȣ������. ����!
//enum RGB
//{
//	Red,
//	Green,
//	White
//};
// ������� ���� �Ҵ�.
enum Direction
{
	Left,
	Right = 2,
	Up,
	Down
};
#pragma endregion


#pragma region enumClass �ڽŸ��� ������ �ִ�
enum class MyColor
{
	Red,
	Green,
	White,
};
/*
�ڽŸ��� �������� ������ �ִ�.
�� ���� �̸��� ������ ����� �ٸ� �������� �浹���� �ʴ´�.
Ÿ���� �������� �����Ѵ�. -> �Ͻ��� ����ȯ�� �ȵȴ�.
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
		cout << "����" << endl;
	}
	else if(color == Green)
	{
		cout << "���" << endl;
	}*/


	Direction Key = Left;

	switch (Key)
	{
	case Left:
		cout << "�������� �̵�" << endl;
		break;
	case Right:
		cout << "���������� �̵�" << endl;
		break;
	case Up:
		cout << "�������� �̵�" << endl;
		break;
	case Down:
		cout << "�Ʒ������� �̵�" << endl;
		break;
	default:
		break;
	}

	// int Rcolor = Red; � Red ���� ���� ����.


	// ���� ������ ��Ȯ�� ����� �Ѵ�.
	MyColor Color = MyColor::Red; // :: ���� ���� (�� ���� �ȿ� �־�)
	// int C = MyColor::Red; // Ÿ���� ���������� ���� �Ͻ��� ����ȯ�� �Ұ����ϴ�. ����!
	// �� ��������� ����ȯ�� ����� �Ѵ�.
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
// ���
/*
enum�� ������ ����� ������������ �ش���.
�Ϲ����� ����ȯ�� ���->Ÿ�Կ� ���� �������� ����.

enumclass�� ������ ��ü�� �������� �ش���.
�Ϲ����� ����ȯ�� ������� �ʴ´�. -> Ÿ�Կ� ���� �������� �����Ѵ�.

*/