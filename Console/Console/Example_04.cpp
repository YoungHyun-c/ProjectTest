#include <iostream>

using namespace std;

#pragma region 조건문
/*

▶ 조건문
- 프로그램이 실행되는 동안 정해져 있는 경우의 수에 맞춰서 서로 다른 결과를 도출하기 위한
 문법을 의미한다.

 - 조건문을 이용하면 다양한 결과를 출력하는 프로그램을 작성하는 것이 가능하다.

 - C / C++ 언어 조건문의 종류

 - if ~ else 조건문
 ㄴ for

 ★ bool 과의 조합에 주의해야 한다. -> 남발


 - switch ~ case 조건문
 ㄴ while

 ▷ if ~ else 문
  - 조건적 실행 (조건에 따라 실행 유무)
  
  - 조건을 만족하는 if 문을 발견하면 나머지 if 문을 건너 뛴다.

  - 또한 if 와 else가 만나서 이루는 문장의 수는 둘이 아니라 1개이다.

  - if ~ else 문에서 조건의 만족 여부 검사는 위에서 아래로 절차지향적으로 진행.

  - 조건이 만족되어 해당 블록을 실행하고 나면 마지막 else 까지도 건너뛴다.

  - 조건이 성립 되지 않을시 마지막의 else 문을 실행한다.


EX) 
if (조건식)
{
	조건식이 참이면 실행될 코드
}
else if (조건식)
{
	조건식이 참이면 실행될 코드
}
else
{
	위 조건들이 만족되지 않으면 실행 될 코드
}


▷ switch 문
 - 스위치 문을 사용하는 경우는 일일이 조건별로 세팅을 해주기가 용이하기 때문에 상태 변화,
	조건이 많은 경우에 사용하면 좋은 효율을 낼 수 있는 문법이다.

 - 그리고 if 문과 매우 흡사하다는 특징이 있으며, switch 문으로 작성이 되는 로직은 전부 if 문으로 대체가 가능하다.
  (단, 코드량이 엄청나게 길어질 수 있으니 주의해야 한다.)

EX)
 - 데이터 타입에는 int, char 형이 올 수 있다.
 ㄴ 하지만 일반적으로 int형을 사용해 주는게 유리하다.
switch (Data Type)
{
	case 1:

	case 2:

	default:
}

 - 스위치문은 인자 값에 따라서 실행할 영역을 결정한다.
   ㄴ EX : 들어오는 값이 1이면 case 1 : 이실행이 되고 들어오는 값이 2라면 case 2가 실행 된다.

 - 스위치 ~ 케이스 조건문의 디폴트는 if ~ else 조건문의 else 문에 해당하는 역할을 수행한다.
 
 // 면접
 ※ 스위치 ~ 케이스 조건문은 if ~ else 조건문과는 달리 범위에 해당하는 조건을 줄 수 없을뿐더러 조건문으로
 사용 될 수 있는 자료형은 정수형에 한정된다. (정수 이외에 값을 조건으로 줄 경우 올바른 결과를 출력 할 수 없다.)


 ▶ C / C++ 언어 제어문의 종류

 1. return
  ㄴ 조건문 일때는 다시 돌려 보낸다. / 함수에서는 값을 반환하고 초기화

 2. continue
  ㄴ 조건문 일때는 연산을 하지 않고 건너 뛴다. / while 문에서는 바로 이전 문항으로

 3. break
  ㄴ 만나면 안된다. / while문 같은 경우는 while문을 빠져 나간다.
  ㄴ break 문은 반복문을 탈출하는 용도로 많이 사용이 되는데. break 문의 유무에 따라서 결과 값이
     - 완전히 바뀔 수 있으니 주의해야 한다.

 4. goto
  ㄴ 보통 "점프문" 이라고 불리며 goto 라벨을 지정하면 중간에 있는 코드를 무시하고 해당 라벨로 이동한다.


*/
#pragma endregion


int main()
{
	int nOperator;
	cout << "내가 입력한 숫자 = ";
	cin >> nOperator;

	// 만약
	if (nOperator == 0)
	{
		cout << "첫번째 게임" << endl;
	} // 또는
	else if (nOperator == 1)
	{
		cout << "두번째 게임" << endl;
	} // 나머지
	else
	{
		cout << "나머지 게임" << endl;
	}

	cout << "\n";

	int InputNumber;

	cout << "0 번, 1번, 2번중 하나를 선택해라." << endl;
	cout << "inputNumber = ";
	cin >> InputNumber;

	// 단일 사용은 그렇게 권장 X
	// ㄴ 짝궁이 있다. -> 열거형
	switch (InputNumber)
	{
	case 0:
		cout << "0번 입력시 내가 출력한다." << endl;
		break;
	case 1:
		cout << "1번 입력시 내가 출력한다." << endl;
		break;
	case 2:
		cout << "2번 입력시 내가 출력한다." << endl;
		break;
	default:
		cout << "그 외 번호를 입력했다." << endl;
		break;
	}

	cout << "\n";

	/*
	 - C / C++ 언어 증 / 감 연산자 종류

	 - 전위 증/감 연산자
	 - 후위 증/감 연산자

	 - 전위 증/감 연산자는 해당 변수의 값을 증/감 시킨 후 연산에 활용하고 후위 증/감 연산자는
	 연산에 활용이 된 후 해당 변수의 값이 변경이 된다. (보통 개행을 기반으로 발생하며 우선 순위 연산을 따른다.)
	*/

	int nValue = 10;

	cout << "증 / 감 에 대한 연산 결과" << endl;

	cout << ++nValue << endl;
	cout << --nValue << endl;
	cout << nValue++ << endl;
	cout << nValue-- << endl;

	cout << "nValue 값 : " << nValue << endl;

	cout << '\n';
	
	int nValueA, nValueB, nValueC, nValueD;
	nValueA = nValueB = nValueC = nValueD = 10;

	if ((nValue == nValueB++) && (nValueC++ < ++nValueD))
	{
		cout << nValueA << endl;
		cout << nValueB << endl;
		cout << nValueC << endl;
		cout << nValueD << endl;
	}

	cout << '\n';

	/*
	- goto
	ㄴ 사용할 때 주의가 필요한 문법
	 ㄴ 가독성을 떨어뜨리고 스파게티 코드를 완성 시키는데 일조하기 때문에
	  ㄴ 사용하기 전에 "정말 여기서 goto문이 필요할까?" 라는 생각을 먼저 해보고 사용하자.

	EX:
	goto 레이블:

	레이블 :
	
	*/

	for (int i = 2; i < 10; i += 1)
	{
		for (int j = 1; j < 10; j += 1)
		{
			if (i % 2 == 0)
			{
				goto EXIT_1;
			}

			if (i % 5 == 0)
			{
				goto EXIT_2;
			}


			cout << i << "x" << j << "=" << i * j << endl << endl;
		}
	EXIT_1:
		cout << "i 단을 출력 후 실행" << i << endl << endl;
	}

EXIT_2:
	cout << "반복문 나와 버렸네? " << endl;

}


/*
 과제1. 가위바위보 게임

 - if 문을 사용해서 만든다.
  ㄴ 스위치문은 사용 금지.

 - 게임의 진행횟수는 총 5판
  ㄴ 이후는 게임 종료

 - 필수 : 치트 (컴퓨터가 낸 수 확인)

 ※ 팁을 주자면 코드를 최대한 간결하게 해오는게 좋을것이다.


 과제2. 일수 출력기

 - if 문과 switch 문 중에 본인이 판단해 효율적인 것을 선택해서 만든다.

 - 시작하면 사용자의 입력을 받고 입력한 숫자에 따라 ??일 인지 출력

 EX : 4를 입력시 -> 4월은 30일까지 있습니다. -> 다시 입력 커맨드 활성화

 - 1월부터 12월까지 확인이 가능해야 하고, 이외의 숫자는 예외처리를 진행한다.

 - 총 5번을 입력하면 프로그램 종료.

 ※ 같은 일수 교집합.


 과제3. 도전과제 함수와 포인터를 활용한 가위바위보.
 void* Function(int* a, int** b, int*** c)
{
	// 내용 작성
}

void main2()
{
	// 이외에 코드가 있으면 안된다.
	Function(a, b, c);
}

 한줄 조사.
 함수에 대해서

 - 노트에 적어온다.

 - 비유할 것 생각해 온다. (EX : 함수는 OOO이다.)


*/