#include <iostream>
// 문자열에 관련된 헤더
// ㄴ STL -> string -> 메모리 블록이나 문자열을 다룰 수 있는 함수들을 포함한다.
// ㄴ char 
#include <string>
// worldwide
// 멀티 바이트, 유니 코드.
// 멀티바이트는 1 바이트 또는 2바이트 각각의 장단점이 있다. 유니코드는 2바이트
// 멀티바이트로 영어를 쓰면 1바이트 문자로 메모리를 아낄 수 있지만, 한글도 쓰게 되면 1, 2 계산하게 되어 느려질 순 있다.

#include <wchar.h>


using namespace std;

#pragma region 함수
/*

▶ 함수

-> 구조적 프로그래밍이 대표 문법.

-> 대강 음료수 자판기 (음료수 자판기는 음료수를 배출하는 기계)

 - 함수를 사용하는 이유.

-> 중복 로직 제거
-> 관리 용이함
-> 가독성 향상
-> 관리성

EX) 함수를 선언하는 방법
반환 자료형 함수이름(입력 자료형 (인자 or 인수라고 불린다.)

{ <- 함수의 시작

	함수의 내용

} <- 함수의 끝

void main()
{

}

- 설명

함수 이름 : 말 그대로 함수의 이름(함수를 실행할 때 사용이 된다.)
인자(인수): (함수가 해야 할 일의 세부사항을 지정하며, 함수의 작업 거리라고 할 수 있다.)
반환 자료형: 함수가 리턴하는 값의 데이터 형이며, 함수의 작업 결과.
함수 내용: {} 안에 함수의 실제 코드가 존재.

 - 함수의 이름은 "기본적"으로 유일해야 한다.
 ㄴ 동일한 이름의 함수를 N개 이상 선언하는 것은 불가능하다.

 ▷ void 형 함수란?
 - 리턴 (반환)할 값이 없는 함수가 되시겠다.
 - 함수의 입력 또는 출력이 없을 경우 void 키워드를 통해서 해당 입/출력이 없다는 것을 명시해야 한다.

 - 우리가 사용한 함수?
 ㄴ rand() : 랜덤값을 뽑는 함수
 ㄴ Sleep(1000) : 1초간 멈추게 하는 함수.

 ★ 함수의 선언은 기본적으로 메인함수 윗쪽에 한다.

 ▷ C / C++ 언어의 함수 선언이 필요한 이유.

 -> C / C++ 언어의 컴파일러는 기본적으로 파일의 내용을 위에서 아래로 해석한다.

 -> 이때 컴파일러가 이미 지나친 라인에서 포함되어 있지 않은 함수를 호출 할 경우 컴파일러가
	이에 대해 내용을 모르기 때문에 에러가 발생한다.

 -> 그렇기 때문에 함수의 선언을 통해서 컴파일러에게 해당 함수가 파일 어딘가에 존재한다는 여부를 알려줘야 한다.

 -> 즉, 함수의 선언과 정의가 반드시 동일한 파일에 존재하지 않아도 된다는 것을 의미

 -> 또한 함수의 선언은 중복으로 명시하는 것이 가능하지만 함수의 정의는 반드시 유일해야 한다.

 규약
 ㄴ 네이티브 -> 카멜식 / 상용 엔진 -> 파스칼 케이스

 

*/
#pragma endregion


// 함수 선언
void OutputValueA();

// 인트형을 받지만 반환은 하지 않는다. (void)
void OutputValueB(int numA);
void OutputValueC(int numA, int numB);

// 문자열 (반환 o / 반환 x)
void OutputString(string str);
string GetStringFunc(string strA, string strB);
int CheckingString(string strA, string strB);

// 반환값이 존재 (int)
int GetAddValue(int numA, int numB);
int GetSubValue(int numA, int numB);
int GetMultipleValue(int numA, int numB);
float GetDivideValue(int numA, int numB);


namespace NS_A
{
	void EnemyAttack()
	{
		cout << "내가 바로 NS_A 함수" << endl;
	}
}

namespace NS_B
{
	void EnemyAttack()
	{
		cout << "내가 바로 NS_B 함수" << endl;
	}
}



void main()
{
	/*NS_A::EnemyAttack();
	NS_B::EnemyAttack();*/

	cout << '\n';

	OutputValueA();
	OutputValueB(5);
	OutputValueC(1, 9);

	OutputString("과제가 너무 재밌다.");

	int nResultA = GetAddValue(18, 25);


	// 변수 형태
	OutputValueB(nResultA);

	string sResultB = GetStringFunc("좋네", "좋아");
	OutputString(sResultB);

	nResultA = CheckingString("과제가 너무 재밌다.", "과제가 너무 재밌다.");
	OutputValueB(nResultA);

	cout << '\n';

	int numL = 0;
	int numR = 0;

	cout << "정수 (2개) 입력 : " << endl;

	cin >> numL >> numR;

	printf("%d + %d = %d\n", numL, numR, GetAddValue(numL, numR));
	printf("%d - %d = %d\n", numL, numR, GetSubValue(numL, numR));
	printf("%d * %d = %d\n", numL, numR, GetMultipleValue(numL, numR));
	printf("%d / %d = %f\n", numL, numR, GetDivideValue(numL, numR));

	/*
	- 이처럼 함수는 다양한 유형을 가질 수 있다.

	C / C++ 언어의 함수 유형

	- 입력 O, 출력 O
	- 입력 O, 출력 X
	- 입력 X, 출력 O
	- 입력 X, 출력 X

	EX)
	// 입력 O , 출력 X
	void ShowInfo(int nAge, char psName);
	// 입력 X, 출력 O
	int GetRandomValue(void);
	// 입력 X, 출력 X
	void SomeFunction(void);



	*/


}







/*
- 이번주. 7.22 ~ 7.26
도전 과제 1. 문자열 관련 테스트

- 펄어비스
<주의 사항>
C++ 언어로 풀어야 하고, 빈칸을 알맞게 채워 넣으시오.
C 런타임 라이브러리 / STL등 기타 라이브러리 함수를 사용하면 안됩니다.
특히 STL string을 사용시 바로 탈락 처리되니 유의 바랍니다.
그리고 해당 방법에 대해 왜 그렇게 작성을 했는지 짧은 주석을 넣어 주세요.

문제. 주어진 문자열을 단어 단위로 순서를 뒤집어 출력하시오,
<예>
입력 값 : "Hello World this is Pearl Abyss"
반환 값 : "Pearl Abyss is this World Hello" 펄어비스는 안뒤집음.
<조건>
입력 문자열은 앞뒤에 공백이 없다고 가정
모든 단어는 공백 한 칸으로 구분된다고 가정.

void ReverseWords(char* output, int outputArraySize, cont char* input)
{
	// 이 곳을 채워 넣으시오.
}

작성이 끝나면 시간 복잡도를 계산하는 수식을 별도의 함수로 구현하고,
동작방식과 왜 그렇게 작성했는지 기술하시오.


*/


// 적절한 입력 데이터와 출력 데이터가 있으면 해당 구문을 함수라고 지정할 수 있다.
// 또한 C / C++ 언어는 함수 단위로 실행하기 때문에, 컴퓨터의 명령문을 작성하기 위해서는 반드시 해당 구문을
// 함수 안에 작성해 주어야 한다.


void OutputValueA()
{
	cout << "내가 바로 함수다" << endl;
}

void OutputValueB(int numA)
{
	cout << numA << endl;
}

void OutputValueC(int numA, int numB)
{
	cout << numA << numB << endl;
}

void OutputString(string str)
{
	cout << str << endl;
}

string GetStringFunc(string strA, string strB)
{
	// 함수는 return 키워드를 통해서 함수의 종료 또는 결과 값을 반환하는 것이 가능하다.
	// 함수의 결과 값은 입력과는 달리 하나의 결과만을 반환할 수 있다. (함수 관점)

	// ?
	// string은 문자열을 다룰 수 있는 다양한 기능을 포함하고 있다. (+ 예외처리)
	// return strA + strB; 처리 안됨
	return strA.append(strB);
}

int CheckingString(string strA, string strB)
{
	// 같으면 1 / 다르면 0
	return strA == strB;
}

int GetAddValue(int numA, int numB)
{
	return numA + numB;
}

int GetSubValue(int numA, int numB)
{
	return numA - numB;
}

int GetMultipleValue(int numA, int numB)
{
	return numA * numB;
}

float GetDivideValue(int numA, int numB)
{
	return numA / (float)numB;
}
