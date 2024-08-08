#include <iostream>
#include <vector>


class AnyClass
{
public:
	void SetArr(int _Start, int _Size);

	void PrintArr() const
	{
		std::cout << "AnyClass에 담긴 Arr : " << std::endl;
		for (const auto& i : Arr)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

private:
	std::vector<int> Arr;

};

void AnyClass::SetArr(int _Start, int _Size)
{
	Arr.reserve(_Size + 1);
	std::cout << "당신이 지정한 초기값 : " << _Start << std::endl;
	std::cout << "초기값에 더한 수 : " << _Size << std::endl;
	for (int i = _Start; i <= _Size + _Start; i++)
	{
		Arr.push_back(i);
	}
}

int main()
{
	AnyClass Any;

	Any.SetArr(5, 10);

	Any.PrintArr();

	return 0;
}