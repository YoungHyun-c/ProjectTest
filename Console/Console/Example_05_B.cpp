#include <iostream>

using namespace std;


#pragma region 변 / 상수
/*
const;
constexpr;

▶ 상수란?
- 변수와 달리 저장된 데이터를 변경 할 수 없는 공간에 붙여진 이름을 의미
 ㄴ 상수는 한번 데이터가 저장되고 나면 변경하는 것이 "일반적"으로 불가능

 ▷ C / C++ 언어 상수의 종류
 - 리터럴 상수
  ㄴ 이름이 없는 상수
  ㄴ 리터럴 상수는 이름이 없는 상수를 의미하며 임시 값이라고 지정한다. ( ex) 1, 0, 1492 등등 임시로 지정한 값)

 - 심볼릭 상수
  ㄴ 이름이 존재하는 상수
  ㄴ 심볼릭 상수는 const 키워드를 통해서 선언이 가능하며 리터럴 상수와 달리 이름을 통해서 저장되어 있는
  데이터를 읽어 들이는 것이 가능하다.

 ▶ constexpr
 
  - C+11 상수화 키워드
  ㄴ 객체 / 함수앞에 붙일 수가 있고 해당 객체나 함수의 반환값을 "컴파일 타임"에 알 수 있다.
  ㄴ C++ 17 부터 람다식에도 적용 가능.

  ※ 컴파일 타임 확정이기 때문에 템플릿과 궁합이 좋다.

 ▶readonly
 - C#에서 지원하는 상수화 키워드
 - const vs readonly C# 기준
 const
  ㄴ 초기화 이후 값을 변경할 수 없다.
  ㄴ 선언하는 시점에만 초기화 가능.
  ㄴ 컴파일 타임 상수
 
 readonly
 ㄴ 초기화 이후 값을 변경할 수 없다.
 ㄴ 단, 선언하는 시점과 생성자라는 늪에서 초기화가 1번 가능하다.
 ㄴ 런타임 상수.

 - 컴파일 타임 상수는 변수가 실제 값으로 대체되고, 런타임 상수는 변수 참조 형식이기 때문에
 성능과 속도를 고려하면 const가 유리하다.

 - 다만 인스턴스마다 다른 값을 할당하고 싶거나 사용자 정의 자료형이면 readonly를 사용하는게
 유지보수에 더 좋다.

 ★★★★★
 define vs const
 ㄴ 매크로를 배우고 나서.....




 ★★★★★
 런타임	  컴파일타임 에 결정된다.
 const vs constexpr
 불안전상수와 안전상수



 ★★★★★
※ 신입이 약한 파트
 ㄴ 문자 / 열 + 상수



*/
#pragma endregion

int main()
{
	cout << "== 리터럴 상수 ==" << endl;
	cout << "정수형: " << 10 << "," << 10L << "," << 10LL << endl;
	cout << "실수형: " << 3.14f << ", " << 3.14 << endl;
	cout << "문자형: " << 'A' << endl;
	
	printf("\n");

	// 변/상수는 생성과 동시에 값을 대입하는 것이 가능하다.
	// ㄴ 이것을 바로 초기화라고 했었다.

	// A
	int numberA = 10;
	// B
	int numberB;
	numberB = 10;

	cout << "== 심볼릭 상수 ==" << endl;
	const int nValueA = 0;
	const float fValueB = 3.14f;
	const double dbValueA = 3.14;

	// 이후 할당 불가능 nValueA = 100; 

	cout << "출력 값 :" << nValueA << ", " << fValueB << ", " << dbValueA << endl;
	printf("%d, %f, %lf\n", nValueA, fValueB, dbValueA);

	// 상수는 다양하게 사용이 되니 꼭 숙지할것
	// 1.
	const int CnumberA = 100;
	int const cNumberB = 200;

	// 2. 포인터 변수의 상수화.
	int Test = 3;
	int Test2 = 4;
	const int* cNumberC;


	// 3. 변수명이 가르키는 주소의 값을 변경할 수 없다.
	// ㄴ 주소의 상수화.
	int pNum;
	int* const CNumberD = &pNum;

	// 4. 주소와 포인터 변수의 상수화.
	const int* const cNumberE = &pNum;


	return 0;
}

/*
과제1. 복습 과제
- 지금까지 배운 내용을 복습을 한다.
- 어떻게 복습을 했는지 구체화 시켜온다.
ㄴ 뭔가를 만들어 오라는 얘기.

과제2. 가위바위보
- 스위치문을 사용해서 만든다.

- 치트 기능과 배팅 기능을 추가한다.
ㄴ 초기 소지금 : 10,000원
ㄴ 최소 배팅은 1,000원 부터

- 5판을 하거나, 내가 가진 돈을 전부 잃으면 게임을 종료한다.
- 이기면 판돈에 x3배를 얻고 지면 판돈에 x7배를 잃는다.

- 비길 경우 판돈에 x5배를 얻는다.

- 함수를 사용해볼것을 추천
 ㄴ 내용에 관게없이 함수의 갯수는 7개 이상.

 한줄 조사. 배열
 
 - 노트에 적어온다.
 - 비유할것 생각해 온다.

*/


// constexpr

//#include <iostream>
//constexpr int Factorial(int Num)
//{
//	int Total = -1;
//	for (int i = 0; i <= Num; i++)
//	{
//		Total *= i;
//	}
//	return Total;
//}
//
//template<int _num>
//struct A
//{
//	int operator()() { return N; }
//};
//
//int main()
//{
//	constexpr int Num = 10;
//	A < Factorial(Num) > a;
//
//	std::cout << a() << std::endl;
//}