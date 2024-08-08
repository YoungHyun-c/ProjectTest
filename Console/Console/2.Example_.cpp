#include <iostream>
#include <vector>
#include <memory>

template <typename DataType>
void ShowPrintValue(const std::vector<DataType>& _vec)
{
	for (const DataType& i : _vec)
	{
		std::cout << i << std::endl;
	}
}

class Weapon
{
public:
	Weapon(const std::string& _Name, int _Damage) : Name(_Name), Damage(_Damage)
	{
	}
	~Weapon()
	{
		int a = 0;
	}

	void Print() const
	{
		std::cout << "이름 : " << Name << ", 공격력 : " << Damage << std::endl;
	}
private:
	std::string Name;
	int Damage;

};


int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);


	std::cout << "vec의 capacity : " << vec.capacity() << std::endl;
	vec.clear();
	std::cout << "vec의 capacity(클리어후) : " << vec.capacity() << std::endl;
	// 클리어 후에도, 메모리용량이 그대로인데, 메모리를 없애려면 빈 벡터를 만들어서 swap하면 된다.

	std::vector<int>().swap(vec);
	std::cout << "vec의 capacity(swap이후) : " << vec.capacity() << std::endl;

	std::vector<int> MyVec = { 1, 2, 3 ,4 ,5, 6 };

	ShowPrintValue(MyVec);


	// Weapon 객체를 저장할 벡터를 생성
	std::vector<Weapon> Weap;
	Weap.push_back(Weapon("장검", 50));
	Weap.push_back(Weapon("활", 10));
	Weap.push_back(Weapon("단검", 100));
	Weap.push_back(Weapon("집행검", 600));

	for (const auto& W : Weap)
	{
		W.Print();
	}

	std::vector<Weapon*> pWeap;
	pWeap.push_back(new Weapon("장검", 50));
	pWeap.push_back(new Weapon("활", 10));
	pWeap.push_back(new Weapon("단검", 100));
	pWeap.push_back(new Weapon("집행검", 600));
	

	for (auto& i : pWeap)
	{
		delete i;
	}

	// 스마트포인터. delete를 안해도 돼서 굉장히 편리한 녀석.
	// memory 헤더 선언.
	// shared_ptr, make_share, shared, weak_ptr
	// auto_ptr, unique_ptr
	
	std::shared_ptr<Weapon> spWeap = std::shared_ptr<Weapon>();

	std::vector<std::unique_ptr<Weapon>> Weapon2;
	std::vector<std::unique_ptr<Weapon>> Vec;
	std::unique_ptr<Weapon> VecW(new Weapon("대검", 100));
	Vec.push_back(std::move(VecW));
	Vec[0]->Print();
	
	return 0;
}

/*
 1. 아무거나 클래스 만들어서 벡터에 저장하고 출력하기.
 2. 상점시스템.
 -> Shop 클래스, item 클래스. Shop->item클래스를 알고있다.
 -> 캐릭터 클래스-> 인벤토리 시스템. 인벤토리 클래스를 갖고있음.
 -> 캐릭터가 shop에 들어가면, 목록이 쭉 나오고,
 구매가능하게, 구매하면, 캐릭터의 인벤토리로.
 인벤토리에서는 캐릭터가 장착할 수 있게 기능이 있어야된다. -> 해제도 가능하게.
 -> 스테이터스 나오게.
 인벤토리에서 상점에 되팔기 기능도 있어야 된다.
 수량 제한.


*/