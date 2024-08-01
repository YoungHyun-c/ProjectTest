#include <iostream>

#pragma region 배열과 포인터
/*
★★★★★★ 면접 질문
포인터
callbyRef
callbyValue

값에 의한 전달 -> CallByValue
함수에 인수를 전달할때 인수의 값이 복사되어 함수의 매개변수로 전달.
함수 내부에서 매개변수를 변경하더라도, 호출한 함수의 실제 인수는 변하지 않는다.

*/


int Sum(int a, int b)
{
	int Res;

	return 0;
}

void Value(int n);

//참조에 의한 호출
void Address(int* n);
// 함수 호출시 인수로 변수의 주소를 전달하는 방식
// 함수가 매개변수로 받은 참조를 통해 실제 인수의 값을 직접 수정가능
// 함수 내부에서 매개변수의 값을 변경하면 호출한 함수의 실제 인수도 변경
// 값을 복사하는 대신 주소를 전달. -> 메모리와 성능적 효율이 좋다.
// 구조체나.. 클래스나

// 함수가 원본데이터에 직접 접근하고, 변경할 수 있게 해준다.
// 변수의 별명, 별칭을 전달한다.
// 함수의 값을 직접 수정할 수 있게한다.
void Reference(int& n);
// 얘가 조금 더 안전하게 사용할 수 있다.
// 메모리 주소가 동일하다.
// 포인터는 Null을 참조할 수 있다. 즉 유효하지 않은 주소를 참조할 수 있다.
// -> 잘 못 된 메모리 접근이 발생할 수 있다.

// 아래와 같은 형태는 전달이 아니라 복사의 형태
// Num1, Num2에 각각 저장된 10, 20이 복사.
// 즉 Swap내부에서만 값이 변경되고, 메인함수에 있는 Num1, Num2는 전혀 영향을 받지 않는다.
void Swap(int a, int b);

void SwapAddress(int* a, int* b);

void SwapReference(int& a, int& b);

#pragma endregion


int main()
{
	/*{
		int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		for (int i = 0; i < 10; i++)
		{
			std::cout << &arr[i] << std::endl;
		}
	}*/

	//배열과 포인터의 관계
	// 포인터로도 배열 원소에 접근이 가능함!
	// 즉, 배열의 시작부분을 가리키는 포인터를 정의하고,
	// 포인터에 1을 더하면 그 다음 원소를 가리키고
	// 2를 더하면 그 다음다음 원소를 가리키게 된다.

	//{
	//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//	int* Parr; // 정수형 포인터
	//	int i;
	//	// parr포인터를 배열의 첫번째 요소의 주소를 저장
	//	Parr = &arr[0];

	//	for (i = 0; i < 10; i++)
	//	{
	//		std::cout << "arr의 주소 " << &arr[i] << std::endl;
	//		std::cout << "parr의 값(주소) : " << (Parr + i) << std::endl;
	//		std::cout << "parr의 값 : " << *(Parr + i) << std::endl;
	//	}
	//}

	// 값 전달.
	//{
	//	int Num = 30;
	//	Value(Num);
	//	std::cout << "Num의 값 :" << Num << std::endl;
	//	std::cout << "Num의 주소값 :" << &Num << std::endl;
	//}
	//{
	//	std::cout << "============" << std::endl;
	//	int Num = 40;
	//	Address(&Num);
	//	std::cout << "Num 의 값 : " << Num << std::endl;
	//	std::cout << "Num 의 주소값 : " << &Num << std::endl;
	//}
	//{
	//	std::cout << "============" << std::endl;
	//	int Num = 50;
	//	Reference(Num);
	//	std::cout << "Num 의 값 : " << Num << std::endl;
	//	std::cout << "Num 의 주소값 : " << &Num << std::endl;
	//}


	// Swap
	{
		std::cout << "Swap" << std::endl;
		int Num1 = 10;
		int Num2 = 20;

		std::cout << "스왑전 데이터 : " << Num1 << ',' << Num2 << std::endl;
		Swap(Num1, Num2);
		std::cout << "스왑후 데이터 : " << Num1 << ',' << Num2 << std::endl;
	}
	// SwapPointer
	{
		std::cout << "SwapPointer" << std::endl;
		int SwapNum1 = 10;
		int SwapNum2 = 20;

		std::cout << "스왑전 데이터 : " << SwapNum1 << ',' << SwapNum2 << std::endl;
		SwapAddress(&SwapNum1, &SwapNum2);
		std::cout << "스왑후 데이터 : " << SwapNum1 << ',' << SwapNum2 << std::endl;
	}
	// SwapReference
	{
		std::cout << "SwapReference" << std::endl;
		int SwapNum1 = 10;
		int SwapNum2 = 20;

		std::cout << "스왑전 데이터 : " << SwapNum1 << ',' << SwapNum2 << std::endl;
		SwapReference(SwapNum1, SwapNum2);
		std::cout << "스왑후 데이터 : " << SwapNum1 << ',' << SwapNum2 << std::endl;
	}

	{
		/*
		void Pointer
			->자료형이 없는 포인터 변수
			->자료형에 제약을 받지 않고, 어떤 자료형의 주소든 저장가능.
			// 값을 참조하려면 강제형변환을 해야한다.
			// 형변환을 잘 못 했을 경우에, 예기치 못한 오류가 발생할 수 있다.
		*/
		void* vp = nullptr;
		int c = 3;
		double d = 3.1;

		int a = 1;
		int* p = &a;
		*p = 3;

		vp = &d;
		//*vp = 1; ->Error //우리가 알고 있는 방법으로는 불가능.
		// -> 강제 형변환을 해주면 된다.
		// (자료형*)을 붙임으로써 가능하게 함 : 강제 형변환.
		
		*(int*)vp = 5;
		 std::cout << *(int*)vp << std::endl;
	}

	{
		int* ptr = new int(10);

		delete ptr;
		int* Array = new int[5];
		
		for (int i = 0; i < 5; i++)
		{
			Array[i] = i * 2;
		}
		delete[] Array;
		Array = nullptr; // -> 삭제를 하고, 가리키지 않는다.
	}

	{
		int num = 10;
		
		int* p = &num;
		*p = 777;

		int** pp;
		pp = &p;
		std::cout << "pp의 값 : (p의 주소값)" << pp << std::endl;

		std::cout << "num의 주소값 :"  << *pp << std::endl;
	}

	return 0;
}

void Value(int n)
{
	n = 10;
	std::cout << "n의 값 : " << n << std::endl;
	std::cout << "n의 주소값 : " << &n << std::endl;
}

void Address(int* n)
{
	*n = 10;
	std::cout << "N의 값 : " << *n << std::endl;
	std::cout << "N의 주소값 : " << &n << std::endl;
}

void Reference(int& n)
{
	n = 10;
	std::cout << "N의 값 : " << n << std::endl;
	std::cout << "N의 주소값 : " << &n << std::endl;
}

void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	std::cout << "Swap()함수 내부의 값 : ";
	std::cout << a << ", " << b << std::endl;
}

void SwapAddress(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapReference(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


// 과제
/*
1. 정적할당과, 동적할당의 차이점.

메모리를 쓸 때 동적할당을 하게 되면, 무조건 해제를 해주어야 한다.
해제를 제때 제때 하지 않으면, 메모리 누수 현상이 일어난다.

C -> malloc memory allocation
	-> free
C++ -> new
	-> delete -> 메모리를 해제

	유효하지 않은 메모리 주소를 가리키는 포인터가 댕글링 포인터. (해제 했는데 가리키게 되면)

int* Cptr = (int*)malloc(sizeof(int) * 10); // 메모리에서 10개를 할당.
int* CppPtr = new int(10); // int형 변수 하나를 동적할당하고, 10으로 초기화 하겠다.

int* Array = new int[5]; // 5개의 int를 지정할 수 있는 배열을 할당.


2. 클래스란 무엇인가요?

3. 구조체를 활용한 학생정보 출력하기.
 ㄴ 학생정보를 출력하는 함수 생성,
 ㄴ 학생정보를 추가하는 함수 생성.

아래와 같은 복사가 아닌 참조 방식으로 하기.
void print(Student s)
{

}

*/
