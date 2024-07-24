#include <iostream>
#include <string>
#include <algorithm>
#include <random>

// 과제1. 함수 오버로딩을 활용한 캐릭터 스킬 만들기
int Random(int _Num = 0);

int SKillRange(std::string _SkillName, std::string _Skills[]);

void Skill(std::string _SkillName, int _Damage, int _Index);

void Skill(std::string _SkillName, int _Damage, int _Critical, int _Range);

// 과제2. 각 자릿수의 합을 구하는 로직
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

#define 파이어볼 0
#define 워터볼 1
#define 콜드볼 2
#define 전기볼 3
#define 아니아니야 4


int main()
{
	// 과제1.
	while (true)
	{
		std::string SkillNum;
		int Dam;
		int PlayerSkill = true;
		std::string Skills[] = { "파이어볼", "워터볼" , "콜드볼", "전기볼", "아니아니야", "종료"};
		int Len = sizeof(Skills)/ sizeof(std::string);
		int Index = 0;
		for (int i = 0; i < Len; i++)
		{
			std::cout << i + 1 << "." << Skills[i] << std::endl;
		}
		while (true)
		{
			std::cout << "스킬을 골라주세요 ex)파이어볼 : ";
			std::cin >> SkillNum;
			auto it = std::find(std::begin(Skills), std::end(Skills), SkillNum);
			Index = std::distance(std::begin(Skills), it);
			if (it != std::end(Skills))
			{
				break;
			}
			if (SkillNum == "종료")
			{
				break;
			}
			std::cout << "스킬을 다시 골라주세요..." << std::endl;
		}
		std::cout << "데미지를 입력해주세요 : ";
		std::cin >> Dam;
		Skill(SkillNum, Dam, Index);
	}


	// 과제2.
	//int Player;
	//std::cout << "값을 입력해주세요 : ";
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


int SKillRange(std::string _SkillName, int _Index)
{
	int Range = 0;

	switch (_Index)
	{
	case 파이어볼:
		Range = 50;
		break;
	case 워터볼:
		Range = 60;
		break;
	case 콜드볼:
		Range = 70;
		break;
	case 전기볼:
		Range = 80;
		break;
	case 아니아니야:
		Range = 100;
		break;
	default:
		break;
	}

	return Range;
}

void Skill(std::string _SkillName, int _Damage, int _Index)
{
	int Critical = Random();
	int Range = SKillRange(_SkillName, _Index);

	Skill(_SkillName, _Damage, Critical, Range);
}

void Skill(std::string _SkillName, int _Damage, int _Critical, int _Range)
{
	int Damage = Random();
	std::cout << "스킬이름 : " << _SkillName << std::endl;
	std::cout << "데 미 지 : " << _Damage << " + " << Damage << std::endl;
	std::cout << "크리티컬 확률 : " << _Critical << "%" << std::endl;
	std::cout << "피격범위 : " << _Range << std::endl;
	std::cout << std::endl;
}