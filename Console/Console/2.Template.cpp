/*
Template
���� �������� ���� ���������� ���ؼ�, �Լ��� Ŭ������ ���� �� �� �ִ�.
-> �ſ� ���� �༮�̴�.
-> Ÿ�Կ� ���� ���� �ʴ´�.
-> �Ϲ������� ����, �Լ��� Ư�� �����͸� ����ϴ� ��ü���� ��κ��� �����ϱ� ����.
-> ������ ������ ���� �޶�������, ������ �ڵ带 ���� ��찡 ����.
-> ���� �� ��Ÿ ���. ���� ���� ������ ������ ������ �����Ѵٸ�, ����ϴ� ���������� �޶�������,
	�ڵ�� ���� ������.
-> �ܼ������ϰ�. ������ ������ ����ؼ� ������ �� �ֱ� ������..
   �������� ���� ������ ����ؼ� �����Ѵٸ� �ᱹ�� ���� �Ǽ��� �ݺ��� �� �ִ�.
   ������ ���������� �� ���� �˰����� �ִ���, ���� �Ǽ��� �ϰ� �ɼ��� �ֱ� ������ �ᱹ�� ���Ҽ��� �ִ�.

�׷��� ���ø��̶�� ������ ����ϸ� ������ �ذ��� �� �ִ�.
1. ���� �������� ���� �پ��� ���������� ���ؼ� �Լ��� Ŭ������ ������ �� �ִ�.
2. ���ø��� ����ϸ� ������, ����� ���������� ���ڷ� �˸���.
3. ���ø����� �ۼ��� �Լ��� ȣ���ϴ� ���� �ڷ����� �´� �Լ��� ������.

<�Լ� ���ø�>
-> �Լ��� �ʿ��� �ڷ����� �����ϰ�, �Լ� ȣ��� �ڷ����� �����ؼ� ���.
-> ���ø����� �ۼ��� �Լ��� ȣ���ϴ� ���� �ڷ����� �´� �Լ��� ������.

 <Ŭ���� ���ø�>
 -> �پ��� ������ Ÿ���� �����ϴ� Ŭ������ ������ �� �ְ� ����.
 -> ���ø� �Ű������� ���� Ŭ������ ��������� ����Լ��� Ÿ���� �Ϲ�ȭ �� �� �ִ�.
 -> Ŭ������ �ʿ��� �ڷ����� �����ϰ�, Ŭ���� �ڷ����� ������.
 -> ���ø����� �ۼ��� Ŭ������ ȣ���ϴ� ���� �ڷ����� �´� Ŭ������ ������.

�Լ����ø�.
-> �Լ��� �ʿ��� �ڷ����� �����ϰ�, �Լ��� ȣ��� �ڷ����� �����ؼ� ���.
-> 

*/
#include <iostream>

int GetMax(int x, int y)
{
	if (x > y) return x;
	else return y;
}
float GetMax(float x, float y)
{
	if (x > y) return x;
	else return y;
}

template<typename TypeDef> // �Ʒ��� �ִ� �� �༮�� ���ø�ȭ �ϰڴ�.
TypeDef GetMax(const TypeDef _x, const TypeDef _y)
{
	if (_x > _y) return _x;
	else return _y;
}
template<typename T>
T const& max(T const& a,T const& b)
{
	return a < b ? b : a;
}
//int const& max(int const& a, int const& b) // -> int �� ���ɶ�
//{
//	return a < b ? b : a;
//}

template <typename T>
void Output(const T data)
{
	std::cout << "������ : " << data << std::endl;
}
template <typename T>
void Output1(T a, T b)
{
	std::cout << a << " , " << b << std::endl;
}

template <typename T1, typename T2>
void Output2(T1 a, T2 b)
{
	std::cout << a << " , " << b << std::endl;
}

template <typename T>
class Box
{
private:
	T data;
public:
	void SetData(T data) { this->data = data; }
	T GetData() { return data; }

	void Print();
};
template <typename T1, typename T2>
class Box2
{
private:
	T1 FirstData;
	T2 SecondData;
public:
	T1 GetFirstData();
	T2 GetSecondData();

	void SetFirst(T1 Val) { FirstData = Val; }
	void SetSecond(T2 Val) { SecondData = Val; }
};

////// ���ø� Ư��ȭ ����.
template <typename Test>
void FuncTest(Test _Value)
{
	std::cout << _Value << " : ���" << std::endl;
}
template <>
void FuncTest(char _Value)
{
	std::cout << _Value << " �̰� ��� �ǳ�" << std::endl;
}

int main()
{
	int a =1 , b = 2;
	std::cout << max(a, b);

	Output(1);
	Output(2.5);
	Output("��");
	Output('��');
	// Output1(1, 1.5); // -> Error typename�� �ϳ��� ���, ���������� �������� ������ ������ ����.
	Output2(1, 1.7); // -> typename�� �ΰ��� ����� ��.


	Box<int> box;
	box.SetData(100);
	std::cout << box.GetData() << std::endl;

	Box<double> box1;
	std::cout << box1.GetData() << std::endl;

	Box2<int, double> box2;
	box2.SetFirst(10);
	box2.SetSecond(20.5);

	std::cout << box2.GetFirstData() << " , " << box2.GetSecondData() << std::endl;

	FuncTest(10);
	FuncTest('a');

	return 0;
}



template<typename T>
void Box<T>::Print()
{

}



template<typename T1, typename T2>
T1 Box2<T1, T2>::GetFirstData()
{
	return FirstData;
}

template<typename T1, typename T2>
T2 Box2<T1, T2>::GetSecondData()
{
	return SecondData;
}
