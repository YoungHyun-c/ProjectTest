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
	std::cout << Name <<"을(를) 사용시 Hp : " << Hp << " MP : " << Mp << " 만큼 영향을 받습니다. Gold :"<< Gold <<" 수량 : x"<< Count << std::endl;
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
