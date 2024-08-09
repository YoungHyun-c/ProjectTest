#include "UseItem_88.h"

void UseItem_88::Start()
{
	Item.reserve(4);

	for (int i = 0; i < 4; i++)
	{
		Item.push_back(UseItem_88(99));
	}

	Item[0].SetUseItem("통닭", 100, 0, 300);
	Item[1].SetUseItem("통닭", 100, 0, 300);
	Item[2].SetUseItem("통닭", 100, 0, 300);
	Item[3].SetUseItem("통닭", 100, 0, 300);
}


void UseItem_88::UseItemInfoPrint()
{
	std::cout << Name <<"을(를) 사용시 Hp : " << Hp << " MP : " << Mp << "만큼 영향을 받습니다. 수량 : x"<< Count << std::endl;
}
