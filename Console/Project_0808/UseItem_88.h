#pragma once
#include <iostream>
#include <string>
#include <vector>

class UseItem_88
{
public:
	UseItem_88(const std::string& _Name, const int& _Hp, const int& _Mp, int _MaxCount)
		: Name(_Name), Hp(_Hp) , Mp(_Mp), MaxCount(_MaxCount)
	{
		Count = _MaxCount;
	}

	void UseItemInfoPrint();

	const int& GetCount()
	{
		return Count;
	}

	void AddCount(int _Num)
	{
		Count += _Num;
		if (MaxCount <= Count)
		{
			Count = MaxCount;
			return;
		}
	}

	void SubCount(int _Num)
	{
		Count -= _Num;
		if (Count <= 0)
		{
			Count = 0;
			return;
		}
	}

protected:
	void Start();

private:
	int MaxCount = 0;
	std::string Name;
	int Hp = 0;
	int Mp = 0;
	int Count = 1;
};

