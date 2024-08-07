/*
Template
아직 정해지지 않은 데이텨형에 대해서, 함수나 클래스를 정의 할 수 있다.
-> 매우 좋은 녀석이다.
-> 타입에 구애 받지 않는다.
-> 일반적으로 변수, 함수와 특정 데이터를 사용하는 실체들의 대부분을 선언하기 원함.
-> 하지만 데이터 형이 달라지더라도, 동일한 코드를 갖는 경우가 많다.
-> 정렬 등 기타 등등. 뭔가 같은 데이터 구조의 동작을 구현한다면, 취급하는 데이터형이 달라지더라도,
	코드는 거의 동일함.
-> 단순무식하게. 동일한 동작을 계속해서 구현할 수 있긴 하지만..
   ㄴ문제는 같은 동작을 계속해서 구현한다면 결국에 같은 실수를 반복할 수 있다.
   ㄴ또한 복잡하지만 더 나은 알고리즘이 있더라도, 많은 실수를 하게 될수도 있기 때문에 결국엔 피할수도 있다.

그래서 템플릿이라는 도구를 사용하면 문제를 해결할 수 있다.
1. 아직 정해지지 않은 다양한 데이터형에 대해서 함수나 클래스를 정의할 수 있다.
2. 템플릿을 사용하면 묵시적, 명시적 데이터형을 인자로 알린다.
3. 템플릿으로 작성한 함수를 호출하는 때에 자료형에 맞는 함수를 생성함.

<함수 템플릿>
-> 함수에 필요한 자료형을 선언하고, 함수 호출시 자료형을 지정해서 사용.
-> 템플릿으로 작성한 함수를 호출하는 때에 자료형에 맞는 함수를 생성함.

 <클래스 템플릿>
 -> 다양한 데이터 타입을 지원하는 클래스를 정의할 수 있게 해줌.
 -> 템플릿 매개변수를 통해 클래스의 멤버변수와 멤버함수의 타입을 일반화 할 수 있다.
 -> 클래스에 필요한 자료형을 선언하고, 클래스 자료형을 지정함.
 -> 템플릿으로 작성한 클래스를 호출하는 때에 자료형에 맞는 클래스를 생성함.

함수템플릿.
-> 함수에 필요한 자료형을 선언하고, 함수의 호출시 자료형을 지정해서 사용.
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

template<typename TypeDef> // 아래에 있는 요 녀석을 템플릿화 하겠다.
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
//int const& max(int const& a, int const& b) // -> int 로 사용될때
//{
//	return a < b ? b : a;
//}

template <typename T>
void Output(const T data)
{
	std::cout << "데이터 : " << data << std::endl;
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

////// 템플릿 특수화 문법.
template <typename Test>
void FuncTest(Test _Value)
{
	std::cout << _Value << " : 출력" << std::endl;
}
template <>
void FuncTest(char _Value)
{
	std::cout << _Value << " 이게 출력 되네" << std::endl;
}

int main()
{
	int a =1 , b = 2;
	std::cout << max(a, b);

	Output(1);
	Output(2.5);
	Output("아");
	Output('아');
	// Output1(1, 1.5); // -> Error typename이 하나인 경우, 데이터형이 동일하지 않으면 오류를 낸다.
	Output2(1, 1.7); // -> typename을 두개로 만드니 됨.


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
