#include "UseItem_88.h"

void UseItem_88::Start()
{
	Item.reserve(4);

	for (int i = 0; i < 4; i++)
	{
		Item.push_back(UseItem_88(99));
	}

	Item[0].SetUseItem("���", 100, 0, 300);
	Item[1].SetUseItem("���", 100, 0, 300);
	Item[2].SetUseItem("���", 100, 0, 300);
	Item[3].SetUseItem("���", 100, 0, 300);
}


void UseItem_88::UseItemInfoPrint()
{
	std::cout << Name <<"��(��) ���� Hp : " << Hp << " MP : " << Mp << "��ŭ ������ �޽��ϴ�. ���� : x"<< Count << std::endl;
}
