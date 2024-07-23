#include <iostream>
#include <algorithm> // 셔플
#include <random> // 메르센

using namespace std;

int main()
{
	// 메르센 트위스터
	random_device rd;
	mt19937 gen(rd()); // 메르센트위스터 난수 생성기 엔진
	uniform_int_distribution<> dist(0, 9); // 0 ~ 9까지 균등하게 분포. //중복 제거가 아님.

	int Num;
	cin >> Num;

	int dest, sour, temp;

	int Number[10] = {};

	for (int i = 0; i < 10; i++)
	{
		Number[i] = i;
	}

	for (size_t i = 0; i < 10; i++)
	{
		cout << "number[" << i << "]인덱스 : " << Number[i] << endl;
	}

	// 섞어보자.
	for (size_t i = 0; i < 1000; i++)
	{
		dest = dist(gen);
		sour = dist(gen); // 고품질의 난수 생성 

		temp = Number[dest];
		Number[dest] = Number[sour];
		Number[sour] = temp;
	}

	std::cout << "================================================" << endl;

	for (size_t i = 0; i < 10; i++)
	{
		cout << "number[" << i << "]인덱스 : " << Number[i] << endl;
	}
	
	// 오늘의 과제.
	// 1. Player vs Computer
	/*
	1. C는 임의의 숫자 3개를 뽑는다.
	2. 플레이어는 차례대로 숫자 3개를 입력한다.
	3. ex ) C = 5, 3 ,1 P = 1, 2, 3 => 중복 1, 3  -> 2ball 자리는 다른데 숫자가 동일하면 Ball
	4. 만약 자리도 같고, 숫자도 동일하면 Strike
	5. 조건 : 난수 발생 범위 (1 ~ 10), 만약 유저가 1 ~ 10 외 다른 숫자입력시 다시 입력 문구 출력.
	6. 종료조건 : 3out -> 3Strike 한번에 1 out임


	*/
	

	return 0;
}