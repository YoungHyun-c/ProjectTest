#include <iostream>

using namespace std;

// 함수의 오버로딩 가독성이 증가한다. 하나의 이름으로 관리할 수 있어 관리하기 쉽다.
// 남발하면 좋지 않고, 적재적소에 잘 사용해야 한다.
// 함수의 이름은 동일하지만, 매개변수의 갯수가 다르면 서로 다른 함수로 인지한다.
// 타입이 달라도 서로 다른 함수로 인지한다.
// 타입이 다르며, 순서가 달라도 다른 함수로 인지한다.
int Sum(int a, int b)
{
	return a + b;
}
int Sum(int a, int b, int c)
{
	return a + b + c;
}
int Sum(double a, int b, int c)
{
	return a + b + c;
}
int Sum(int a, double b, int c)
{
	return a + b + c;
}
// 리턴타입은 고려 대상이 아니라서 오류.
//int func(int a);
//double func(int b);

// 디폴트 매개변수
// 매개변수의 디폴트 값을 지정해서, 함수호출할때 매개변수를 전달하지 않은 경우 기본값으로 처리하게 된다.
// 모호함이 생기면 뭘 불러야될지 몰라서 오류가 난다.
// ex) 오류
int Test(int a);
int Test(int a, int b = 3);
// 디폴트 매개변수는 맨 오른쪽부터 지정을 해줘야 한다.
// ex) 오류
int Test(int a, int b = 3, int c)
{
	return a + b + c;
}
// inline 함수 ->
// 함수의 호출 과정에서 발생하는 오버헤드를 줄이기 위해서 사용하는.
// 반복적인 호출에서 걸리는 시간을 줄일 수 있다.
// 호출 했을때 삽입해놓는 것.
// -> 코드가 매우 간단하고, 잦은 호출이 있을 것 같은 것은 inline 호출.
int LRTest(int Left, int Right)
{
	return Left > Right ? Left : Right;
}

int main()
{
	int Result = Test(1, 2, 3);

	return 0;
}

/*
과제1. 함수 오버로딩을 활용한 캐릭터 스킬 만들기.
ex) 스킬 이름만 입력받아 사용하는 함수.
스킬 이름이랑 데미지 값을 입력받아 스킬을 사용하는 함수.
스킬이름, 데미지, 크리티컬 확률, 피격범위 출력.


2. 사용자가 입력한 양의 정수의 각 자릿수의 합을 구하는 로직을 구현해라.
ex) 예를 들어서..
18324 -> 1 + 8 + 3 + 2 + 4 = 18;
3849 -> 3 + 8 + 4 + 9 = 24;
*/