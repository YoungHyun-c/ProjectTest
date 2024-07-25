#include <iostream>



// 배열
// 저장된 데이터를 참조하는 것과 같다.
// 같은 자료형을 가진 연속된 메모리 공간으로 이루어진 자료구조.
// 이런 배열은 같은 자료형을 가진 변수들이 여러개 필요할때 사용.
// 많은 양의 데이터를 처리할 때 유용하다.
int main()
{
	int num;
	int num1;
	int num2;
	int num3;
	int num4;
	int num1000 = 10;

	
	// 배열 선언방법
	//					 [배열 길이]
	// 자료형 / 배열 이름 [10] ;
	int arr[4] = { 1, 2, 3, 4 };

#pragma region 초기화 방법
	// 배열의 초기화 방법
	/*
	1. 크기를 명시하고 초기화
	int arr[4] = {1, 2, 3, 4};
	
	2. 배열의 크기를 생략하고 초기화
	int arr[] = { 1, 2, 3 };

	3. 크기를 명시적으로 지정하고, 일부 요소만 초기화
	int arr[5] = { 1, 2, 3 }; // 나머지는 0으로 자동 초기화

	4. 모든 요소를 초기화 하지 않음
	int arr[5] = {}; // 0으로 자동 초기화
	*/
#pragma endregion


#pragma region Arr01 1차원 배열

	//std::cout << "arr[0] 번째 데이터 : " << arr[0] << std::endl;
	//std::cout << "arr[1] 번째 데이터 : " << arr[1] << std::endl;
	//std::cout << "arr[2] 번째 데이터 : " << arr[2] << std::endl;
	//std::cout << "arr[3] 번째 데이터 : " << arr[3] << std::endl;

	//std::cout << "=================================" << std::endl;

	//std::cout << arr << std::endl; // 배열의 시작 주소는 배열의 0번째 인덱스 주소와 같다.
	//std::cout << &arr[0] << std::endl;
	//std::cout << &arr[1] << std::endl;
	//std::cout << &arr[2] << std::endl;
	//std::cout << &arr[3] << std::endl;

	//std::cout << "for 문을 이용한 배열 출력 " << std::endl;
	//for (size_t i = 0; i < 4; i++)
	//{
	//	std::cout << arr[i] << std::endl;
	//}

	//int number[5];

	//for (size_t i = 0; i < 5; i++)
	//{
	//	number[i] = i + 1;

	//	/*
	//	number[0] = 0 + 1;
	//	number[1] = 1 + 1;
	//	number[2] = 2 + 1;


	//	*/
	//}
	//// 만약 10명의 학생 성적을 입력-> 배열에 저장하고, 총점과 평균을 구하려면?
	//// 입력 -> 처리 -> 결과
	//std::cout << "===================================" << std::endl;
	//int Total = 0;
	//int Ave = 0;
	//constexpr int StudentNum = 10;

	//int Student[StudentNum] = { };

	//for (int i = 0; i < StudentNum; i++)
	//{
	//	int Point = 0;
	//	printf("%d번째 학생 성적을 입력하세요 : ", i+1);
	//	std::cin >> Student[i];
	//	Total += Student[i];
	//}

	//Ave = Total / StudentNum;

	//std::cout << "총 점수 : " << Total << std::endl;
	//std::cout << "평균 점수 : " << Ave << std::endl;

#pragma endregion


	int arr1[4][3];

	arr1[0][0] = 1;
	arr1[0][1] = 2;
	arr1[0][2] = 3;

	arr1[1][0] = 4;
	arr1[1][1] = 5;
	arr1[1][2] = 6;

	arr1[2][0] = 7;
	arr1[2][1] = 8;
	arr1[2][2] = 9;

	arr1[3][0] = 10;
	arr1[3][1] = 11;
	arr1[3][2] = 12;

	std::cout << std::endl << std::endl;

	std::cout << "0행 출력 결과" << &arr1[0][0] << "," << &arr1[0][1] << "," << &arr1[0][2] << std::endl;
	std::cout << "1행 출력 결과" << &arr1[1][0] << "," << &arr1[1][1] << "," << &arr1[1][2] << std::endl;
	std::cout << "2행 출력 결과" << arr1[2][0] << "," << arr1[2][1] << "," << arr1[2][2] << std::endl;
	std::cout << "3행 출력 결과" << arr1[3][0] << "," << arr1[3][1] << "," << arr1[3][2] << std::endl;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << arr1[i][j] << std::endl;
		}
	}


	// 1.지금부터 4교시 종료까지
	// 배열을 활용하기
	// 인풋을 받아서 입력받은 숫자의 구구단 계산 결과를 배열에 저장하고 출력하기. 단 입력시, 단의 계산 결과 배열에 저장하고 , 출력

	//2. 다음 표에서 가로 합과, 세로합 모든 수의 합을 구해라.
	/*
		랜덤
		90 78 77 66 55
		90 78 48 18 58
		89 58 76 85 78
		48 68 79 85 87
	*/


	const int ArraySize = 8;
	int* MyVariableSizxeArray = new int[ArraySize];




	return 0;
}