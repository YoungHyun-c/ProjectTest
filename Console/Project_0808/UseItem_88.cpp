#include "UseItem_88.h"


void UseItem_88::SetUseItem(const std::string& _Name, int _Hp, int _Mp, int _Gold)
{
	Name = _Name;
	Hp = _Hp;
	Mp = _Mp;
	Gold = _Gold;
}


void UseItem_88::UseItemInfoPrint()
{
	std::cout << Name <<"��(��) ���� Hp : " << Hp << " MP : " << Mp << " ��ŭ ������ �޽��ϴ�. Gold :"<< Gold <<" ���� : x"<< Count << std::endl;
}


void UseItem_88::Start()
{
	if (Items.empty())
	{
		Items.reserve(4);
	}

	Items.push_back(new UseItem_88(99));
	Items.push_back(new UseItem_88(99));
	Items.push_back(new UseItem_88(99));
	Items.push_back(new UseItem_88(99));
}
