#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <Windows.h>

using namespace std;

#pragma region 연산자 + 반복문
/*
 
▶ 연산자란?

- 프로그램이 동작을 할 때 정해져 있는 역할을 수행하는 키워드를 연산자라고 할 수 있다.
 ㄴ 연산자를 이용하면 다양한 프로그램 로직을 만들어 내는 것이 가능하다.

 ▷ 기본적인 연산자의 종류

 - 산술	 (+, -, *, /, %)
 - 비교	 (==, !=, <, >, <=, >=)
 - 할당	 (=, +=, -=, *=, /=, %=)
 - 비트	 (&, |, ^)
 - 논리	 (&&, ||, !)
 - 형변환 ((Data Type))

 - 비교

 num == num2;		-> num과 num2가 같다.
 num != num2;		-> num과 num2가 같지 않다. (다르다)
 num < num2;		-> num이 num2 보다 작다.
 num > num2;		-> num이 num2보다 크다.
 num <= num2;		-> num이 num2 보다 작거나 같다.
 num >= num2;		-> num이 num2보다 크거나 같다.

 - 할당

 = : 대입 연산자 (우 -> 왼)
 +=, -=, *=, /=, %=

 - 비트
 
 메모리를 효율적 / 빠른 연산을 위해서 사용한다.
 ㄴ AND
 ㄴ OR
 ㄴ XOR
 ㄴ NOT
 ㄴ <<
 ㄴ >>
  - 언제쓰면 효율적이냐? -> bool이 많아지면 사용하는게 좋다. 비트마스크, 비트플래그 bitset

- 논리 (bool)

bool num;

num				num이 만족하면 실행(참)
num && num2		num과 num2의 조건이 둘 다 참이면 실행 (논리 AND)
num || num2		num과 num2의 조건이 둘 중 하나라도 참이면 실행 (논리 OR)
!num			num이 만족하지 않으면 실행 (논리 부정)


- 형변환 연산자

- ((특정 자료형)) 변수명

- C / C++ 언어는 형변환 연산자를 이용하면 간단하게 해당 변수의 자료형을 변경하는 것이 가능.

- 강제 형변환에 대해서

- C 스타일의 명시적 형변환은 가독성이 떨어지고 버그가 생길 여지는 만들고 시작한다.
 ㄴ 그렇기 때문에 프로그래머의 주의가 필요하다. (안전성 ↓)
  ㄴ 안정성을 우선시 할 것이면 캐스팅 연산자를 사용해야 한다.
  형변환의 장점은 코스트 비용이 싸고, 빠르다.

EX : static_cast<Data Type>(Obj)
 ㄴ Obj를 type으로 바꾼다.
 ㄴ 논리적으로 가능한 경우에만 변환. (안전성 ↑) 신입에겐 안전성이 더 중요하다.


 ★★★★★
 C++ 스타일 형변환 연산자

 - static_cast
 ㄴ 

 - dynamic_cast
 ㄴ 클래스

 - const_cast
 ㄴ 상수성을 제거하는 형변환

 - reinterpret_cast
  ㄴ 포인터에 형변환

 
 ===================================================
 ▶ 반복문

 - 프로그램의 특정 부분을 일정 횟 수 이상 반복해서 실행하도록 하기 위한 문법
 ㄴ 반복문을 이용하면 반복적으로 발생되는 구간을 간단하게 / 효율적으로 처리하는 것이 가능하다.

 - C / C++ 언어의 표준 반복문

 1. for
 2. while
 3. do ! while

 펄어비스 온라인 서술형
 - 반복문은 과연 필수 문법일까? 필수는 아니지만 효율이다.




 c++ 언어 버전은 11, 모던 C++

*/

#pragma endregion

void main()
{
	int numberA = 0;

	numberA = 1;
	numberA++;
	numberA = 6;
	numberA++;
	numberA += 5;
	numberA--;
	numberA -= 2;
	numberA *= 3;
	numberA /= 2;

	std::cout << "numberA의 값 : " << numberA << std::endl; // 13

	/*
	
	C / C++ 언어는 연산자를 이용해서 결과를 만들어낼 때 해당 연산자에 사용된 변수의 자료형에 따라
	결과가 달라진다.

	EX)
	정수 + 정수 = 정수
	정수 + 실수 = 실수

	- 소실의 위험이 적은 자료형으로 만들어진다.

	- %는 정수형 데이터에만 사용 가능
	
	*/


	/*
	01. for문
	- 구성
	ㄴ 초기식 : 반복을 위한 변수의 선언 및 초기화
	ㄴ 조건식 : 반복의 조건을 검사하는 목적으로 선언
	ㄴ 증감식 : 반복의 조건을 거짓으로 만드는 증가 및 감소 연산

	EX)
	for (초기식 : 조건식 : 증감식)
	{
		반복이 되는 문장.
	}
	*/

	// C 스타일 (컴파일러 버전)
	int i;
	for (i = 0; i < 10; i++)
	{
		std::cout << "[" << i << "번째]" << "열심히 공부합시다." << std::endl;
	}

	// 짱짱?
	// 3 확인을 하고 내린다.
	std::cout << std::endl;
	// 1 
	std::cout << '\n';
	// 2 \0 이 있는지 확인
	printf("\n \0");


	int numberB = 0;
	for (; numberB < 5; numberB++)
	{
		cout << "이건..:" << numberB << endl;
	}

	cout << '\n';

	/*
	- 위에 경우처럼 for 문은 필요에 따라 초기식 / 조건식 / 증감식 생략이 가능하다.

	- 생략에 따른 유형

	1. 초기화 생략 -> for (; i < 10; i++)
	2. 조건식 생략 -> for (i = 1; i++)
	3. 초기화 증감식 생략 -> for (; i < 10;)
	4. 모두 생략 for (; ; )
	
	*/

	// 전위 후위
	// ㄴ i++ / ++i
	int j = 1;

	for (int i = 0; i < 5; i++)
	{
		// 22 44 66 ...
		cout << "전" << ++j << endl;
		cout << "후" << j++ << endl; // 세미클론을 만난 뒤에 메모리 접근을 시도한다.
	}

	cout << "\n";

	// 대부분의 반복문은 반복문 안에 반복문을 허용한다.
	// ㄴ 이를 중첩 반복문이라고 한다.
	// C와 C++ 언어에서는 삼중까지는 OK
	// ㄴ 4중보다는 정말 고민을 좀 해보면 좋을것 같다.

	// 2중 포문
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{

		}
	}

	// ranged for 범위기반 포문
	// ㄴ for 문이 한번 돌때마다 : 다음에 있는 녀석에 다음꺼 -> 다음꺼를 가져오고 n - 1 에 도달하면 종료.
	//for (UActorComponent* Component : Component) // 처음 객체를 주소로 찍어놓고, 그 주소의 요소를 다른 요소로 하나씩 참조한다.
	//{

	//}

	//vector<int> vNumber;
	//vector<int>::iterator viNumber;

	//// 알고리즘 함수의 하나. 단순 숫자 객체를 가져온다 하면 쓰면 좋다.
	//for each(auto p in vNumber) // auto 자동적으로 자료형을 구성
	//{
	//	cout << p << endl;
	//}

	//int Value = 2;
	//for_each(vNumber.begin(), vNumber.end(), [&Value](auto& number));
	//transform();



	/*
	02. while문

	- 무한 (Loop)
	ㄴ 반복 조건에 1이 들어갈 경우 무한 루프에 빠지게 된다.
	ㄴ 이는 논리식으로 빠져나오거나 아니면 제어문을 통해 강제로 탈출을 해야 한다.
	ㄴ 조건이 참 (true) 일때만 작동

	- while문은 특정 조건을 주고 그 조건을 만족하는 동안 특정 영역을 계속해서 반복하는 구조이다.
	
	*/

	int PlayerHp = 1000;

	while (PlayerHp)
	{
		int hit = 100;

		PlayerHp -= hit;
		cout << "체력 : " << PlayerHp << endl;
	}

	cout << "\n";

	int numC = 0;
	
	while (numC < 5)
	{
		cout << "이게 while문 이다." << endl;
		numC++;
	}

	cout << "\n";

	/*
	// 03. do ~ While 

	- while문의 차이점 : 조건을 검사하는 시점이 다르다.

	- 일단 무조건 한번 실행을 하고 while문의 조건을 검사 -> 이후 do ~ while문 안의 문장을
	실행할 것인지에 대하여 판단한다.

	do
	{
		
	} while(조건식);

	*/

	int numD = 0;

	// 1번 실행된다.
	do
	{
		cout << "do ~ while문" << endl;
		numD++;
	} while (numD < -1);
	
	do
	{
		cout << "2번째 do ~ while문" << endl;
		numD++;
	} while (numD < 3);


	cout << "\n";

	int total = 0, num = 0;
	do
	{
		cout << "숫자 입력 (종료하고 싶을시 0 번을 누르시오.)" << endl;
		cin >> num;
		total += num;
	} while (num != 0);

	cout << "입력한 숫자의 합계 : " << total << endl;

	cout << "\n";





	int a = 0;
}


/*
과제1. 구구단 구현

- > 3종의 반복문을 이용해서 구구단 구현
 ㄴ for / while / do ~ while


 과제2. 연산자 활용

 - a. 2개의 정수를 받아서 두 수의 덧셈과 뺄셈의 결과를 출력하는 프로그램 작성

 - b. 3개의 정수 (num1, num2, num3)을 받아서 다음 연산의 결과를 출력하는 프로그램 작성
 ㄴ EX: (num1 + num2) * (num3 + num1) % num 1= ?

 - c. 입력 받은 두 정수를 나누었을 때 얻게 되는 몫과 나머지를 출력하는 프로그램 작성
 ㄴ EX: 7과 2가 입력 -> 몫으로 3 / 나머지는 1이 출력되면 된다.

 과제3. 반복문 출력
  -> for / while / do ~ while문 모두 사용
  
  -> 1 ~ 20까지 모두 출력
   ㄴ 짝수만

  -> 20 ~ 1까지 출력

 과제4. 반복문 숙달
 가장 적합한 반복문으로
 - 정수 하나를 입력 받아 -5씩 반복적으로 연산이 되는 식을 만든다.
 ㄴ 종료 조건은 -15를 넘어가면 탈출
 ㄴ 조건 : 입력 받는 값은 -10 ~ 10 사이의 숫자여야 하고, 이외의 값을 입력시 프로그램 종료를 시킨다.

 ※ 조건식과 논리 연산자를 잘 보고 조건실을 만들어 반복문이 돌아가게 만드는게 포인트

 과제5. 별찍기
 - 본인이 판단한 효율적인 반복문 1종을 선정해서 사용할 것.
 
 *****
 ****
 ***
 **
 * 
 
 * 
 **
 ***
 ****
 *****
 
 합쳐서 마름모로 만들기.

 *
 **
 ***
 ****
 *****
 ******
 *****
 ****
 ***
 **
 * 
  
 
    *  
   ***
  *****
 *******
  *****
   ***
    *

 도전과제1. 마름모 찍기
 - 조건 : for문 1번 + 1줄 (나머지 연산)
  ㄴ 배운것 이외에는 사용 금지


 한줄조사. 조건문
 - 노트에 적어온다.
 - 비유할 것 생각해 온다. (EX : 조건문은 OOO 이다.)


*/