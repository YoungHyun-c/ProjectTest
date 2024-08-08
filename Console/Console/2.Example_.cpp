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
		std::cout << "�̸� : " << Name << ", ���ݷ� : " << Damage << std::endl;
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


	std::cout << "vec�� capacity : " << vec.capacity() << std::endl;
	vec.clear();
	std::cout << "vec�� capacity(Ŭ������) : " << vec.capacity() << std::endl;
	// Ŭ���� �Ŀ���, �޸𸮿뷮�� �״���ε�, �޸𸮸� ���ַ��� �� ���͸� ���� swap�ϸ� �ȴ�.

	std::vector<int>().swap(vec);
	std::cout << "vec�� capacity(swap����) : " << vec.capacity() << std::endl;

	std::vector<int> MyVec = { 1, 2, 3 ,4 ,5, 6 };

	ShowPrintValue(MyVec);


	// Weapon ��ü�� ������ ���͸� ����
	std::vector<Weapon> Weap;
	Weap.push_back(Weapon("���", 50));
	Weap.push_back(Weapon("Ȱ", 10));
	Weap.push_back(Weapon("�ܰ�", 100));
	Weap.push_back(Weapon("�����", 600));

	for (const auto& W : Weap)
	{
		W.Print();
	}

	std::vector<Weapon*> pWeap;
	pWeap.push_back(new Weapon("���", 50));
	pWeap.push_back(new Weapon("Ȱ", 10));
	pWeap.push_back(new Weapon("�ܰ�", 100));
	pWeap.push_back(new Weapon("�����", 600));
	

	for (auto& i : pWeap)
	{
		delete i;
	}

	// ����Ʈ������. delete�� ���ص� �ż� ������ ���� �༮.
	// memory ��� ����.
	// shared_ptr, make_share, shared, weak_ptr
	// auto_ptr, unique_ptr
	
	std::shared_ptr<Weapon> spWeap = std::shared_ptr<Weapon>();

	std::vector<std::unique_ptr<Weapon>> Weapon2;
	std::vector<std::unique_ptr<Weapon>> Vec;
	std::unique_ptr<Weapon> VecW(new Weapon("���", 100));
	Vec.push_back(std::move(VecW));
	Vec[0]->Print();
	
	return 0;
}

/*
 1. �ƹ��ų� Ŭ���� ���� ���Ϳ� �����ϰ� ����ϱ�.
 2. �����ý���.
 -> Shop Ŭ����, item Ŭ����. Shop->itemŬ������ �˰��ִ�.
 -> ĳ���� Ŭ����-> �κ��丮 �ý���. �κ��丮 Ŭ������ ��������.
 -> ĳ���Ͱ� shop�� ����, ����� �� ������,
 ���Ű����ϰ�, �����ϸ�, ĳ������ �κ��丮��.
 �κ��丮������ ĳ���Ͱ� ������ �� �ְ� ����� �־�ߵȴ�. -> ������ �����ϰ�.
 -> �������ͽ� ������.
 �κ��丮���� ������ ���ȱ� ��ɵ� �־�� �ȴ�.
 ���� ����.


*/