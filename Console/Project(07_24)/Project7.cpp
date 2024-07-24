#include <iostream>
#include <string>
#include <algorithm>
#include <random>

// ����1. �Լ� �����ε��� Ȱ���� ĳ���� ��ų �����
int Random(int _Num = 0);

int SKillRange(std::string _SkillName, std::string _Skills[]);

void Skill(std::string _SkillName, int _Damage, std::string _Skills[]);

void Skill(std::string _SkillName, int _Damage, int _Critical, int _Range);

// ����2. �� �ڸ����� ���� ���ϴ� ����
int SumNum(int _Num)
{
	int Answer = 0;

	while(_Num)
	{
		Answer += _Num % 10;
		_Num /= 10;
	}
	return Answer;
}

#define ���̾ 1
#define ���ͺ� 2
#define �ݵ庼 3
#define ���⺼ 4
#define �ƴϾƴϾ� 5


int main()
{
	// ����1.
	while (true)
	{
		std::string SkillNum;
		int Dam;
		int PlayerSkill = true;
		std::string Skills[] = { "���̾", "���ͺ�" , "�ݵ庼", "���⺼", "�ƴϾƴϾ�", "����"};
		int Len = sizeof(Skills)/ sizeof(std::string);
		for (int i = 0; i < Len; i++)
		{
			std::cout << i + 1 << "." << Skills[i] << std::endl;
		}
		while (true)
		{
			std::cout << "��ų�� ����ּ��� ex)���̾ : ";
			std::cin >> SkillNum;
			auto it = std::find(std::begin(Skills), std::end(Skills), SkillNum);
			if (it != std::end(Skills))
			{
				break;
			}
			if (SkillNum == "����")
			{
				break;
			}
			std::cout << "��ų�� �ٽ� ����ּ���..." << std::endl;
		}
		std::cout << "�������� �Է����ּ��� : ";
		std::cin >> Dam;
		Skill(SkillNum, Dam, Skills);
	}


	// ����2.
	//int Player;
	//std::cout << "���� �Է����ּ��� : ";
	//std::cin >> Player;
	//std::cout << SumNum(Player);

	return 0;
}

int Random(int _Num)
{
	int Random = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 100);

	return Random = _Num + dist(gen);
}


int SKillRange(std::string _SkillName, std::string  _Skills[])
{
	int Range = 0;
	int Index = 0;

	

	switch (Index)
	{
	case 1:
		Range = 50;
		break;
	case 2:
		Range = 60;
		break;
	case 3:
		Range = 70;
		break;
	case 4:
		Range = 80;
		break;
	case 5:
		Range = 100;
		break;
	default:
		break;
	}


	return Range;
}

void Skill(std::string _SkillName, int _Damage, std::string _Skills[])
{
	int Critical = Random();
	int Range = SKillRange(_SkillName, _Skills);

	Skill(_SkillName, _Damage, Critical, Range);
}

void Skill(std::string _SkillName, int _Damage, int _Critical, int _Range)
{
	int Damage = Random();
	std::cout << "��ų�̸� : " << _SkillName << std::endl;
	std::cout << "�� �� �� : " << _Damage << " + " << Damage << std::endl;
	std::cout << "ũ��Ƽ�� Ȯ�� : " << _Critical << "%" << std::endl;
	std::cout << "�ǰݹ��� : " << _Range << std::endl;
	std::cout << std::endl;
}