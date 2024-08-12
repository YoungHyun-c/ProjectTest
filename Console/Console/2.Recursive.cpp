
//Recursive
// 재귀함수.
// 자기 자신을 호출하는 녀석.
// -> 프로그래밍에서의 재귀는 복잡한 문제를 더 단순한 하위 문제로 쪼개 해결하는데 사용한다.
// 적어도 하나의 종료조건이 반드시 있어야만 한다. -> 종료조건이 없으면 내 자신을 계속 호출하기 때문에, 무한루프에 빠진다.
// 재귀함수 - 팩토리얼 계산 1~n까지 곱,
// 하노이탑 - 재귀함수.
//

// 단점 -> 오버헤드가 발생할 수 있다. -> 계속해서 메모리에 쌓이게 된다.
// -> 다소 이해하기 까다로울 수 있다. -> 디버깅 자체가 힘들어서.

int factorial(int n)
{
	if (n <= 1) return 1;

	// 재귀단계 : n * (n - 1)의 팩토리얼.
	return n * factorial(n - 1);
	// 호출 순서
	// 3 * factorial(2)
	// factorial(2)
	// factorial(1)
}
// 과정
// 3 * factorial(2)
// 3 * 2 * factorial(1)
// 3 * 2 * 1; <- 방향은 오른쪽에서 왼쪽
#include <iostream>

// 하노이.
void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		std::cout << from << " " << to << std::endl;
	}
	else
	{
		// n -1 개의 판이 2번자리에 옮겨져야 되기 때문에.
		hanoi(n - 1, from, to, by);
		std::cout << from << " " << to << std::endl;
		// n -1 개의 판이 3번 자리에 쌓아 올려져야 되기 때문에.
		hanoi(n - 1, by, from, to);
	}
}

int main()
{
	int Res = factorial(3); // 3 * 2 * 1
	std::cout << Res << std::endl;

	int N;
	std::cout << "입력 : ";
	std::cin >> N;
	int K = static_cast<int>(pow(2, N)) - 1;
	std::cout << K << std::endl;
	hanoi(N, 1, 2, 3);


	return 0;
}

/*
1. 콘솔프로젝트
 ㄴ. 워드나 한글로 기능정의서를 만들어라.
 
 ex)
 주제 : ooo 만들기
 -ooo 기능 구현(Vector)
  ㄴ 간단히 어떤 기능인지 명시하라는 뜻.
 -ooo 기능 구현 (~을 활용)
  
 - 스케줄.
  ㄴ 1. 8/12 ~ 8/13 전투 시스템 구현.
  

  목적 : 프로그래밍의 전반적인 숙련도를 높이기 위해서 하는 것.
  8/22일까지, 23일 발표.

*/