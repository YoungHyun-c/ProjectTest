#include <iostream>

/*
STL
 - 프로그램에 필요한 자료구조와 알고리즘 템플릿으로 제공하는 라이브러리.

 - 컨테이너 : 객체를 보관하는 객체. 클래스 탬플릿의 형태로 구현이 되어있음.
  ㄴ각각의 원소에 접근할 수 있도록 다양한 멤버함수를 제공.
  ㄴ접근하는 방법은 직접 함수를 호출하거나, 반복자 (iterator)라는 것을 이용해 접근.

  ㄴ이터레이터(반복자): 포인터와 비슷한 개념으로 컨테이너의 원소를 가리키고, 가리키는
  원소에 접근하여, 다음 원소를 가리키게 하는 기능.

 - 알고리즘 : 정렬, 삭제, 검색 등을 해결하는 일반화 된 방법을 제공하는 함수 템플릿.
 - 시퀀스 컨테이너 -> 선형적 -> 직선의 형태
 - 연관 컨테이너 -> 비선형

 - 시퀀스 컨테이너(선형) : 컨테이너 원소가 자신만의 삽입위치(순서)를 가지는 컨테이너.
 ㄴ vector, list, deque

 - 연관 컨테이너(비선형적) : 저장원소가 삽입 순서와 다르게, 특정 정렬기준에 의해 자동 정렬되는 컨테이너.
 ㄴ set, multiset, map, multimap. -> 각각이 장단점이 있어, 자신의 데이터에 따라 맞는, 효율적인 데이터를 써야된다.

 많이 쓰는 것.
 -> vector, list, map.


 -Vector란?
 -> 가변길이 배열.
 -> 순차적으로 저장, 내부적으로 동적배열을 사용하여 크기를 자동으로 조절.
 -> 인덱스를 통해서, 임의의 원소에 접근가능 (배열의[], 멤버함수 at)
 
 ★★★★★★★
 면접 질문
 벡터 VS 리스트
 벡터는 임의이 접근이 빠르다.
 문제는 중간의 요소가 사라지면, 뒤의 데이터는 앞으로 땡겨진다.
 ∴ 중간 삽입 삭제가 느리다. (리스트와 상대적으로)

 리스트는 노드 기반이다. Node
 데이터를 저장할 공간과, 다음 메모리를 가리키는 포인터로 이루어져 있다.
 내부 라이브러리는 양방향으로 이루어져있다.
 단방향과 양방향이 있다.
 단방향은 그 다음 노드를 가리키고, 양방향은 그 전 노드도 가리키고 있다.
 중간에 있는 요소를 삭제했을때, 그 다음 노드를 가리키면 돼서, 벡터에 비해 빠르다.




*/

#include <vector>
int main()
{
	std::vector<int> V1; // 빈 벡터.
	std::vector<int>V2(10); //10개의 기본값(0)으로 초기화된 벡터 생성.
	std::vector<int>V3(10, 5); // 10개의 요소를 5로 초기화한 벡터 생성.
	std::vector<int>V4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::cout << "벡터의 사이즈 V1 : " << V1.size() << std::endl; // size는 원소의 개수를 리턴함.
	std::cout << "벡터의 사이즈 V2 : " << V2.size() << std::endl; // 용량이랑은 다르다.
	std::cout << "벡터의 사이즈 V3 : " << V3.size() << std::endl;
	std::cout << "벡터의 사이즈 V4 : " << V4.size() << std::endl;

	std::cout << "=============================================" << std::endl;
	// capacity는 현재 할당된 메모리에서의 용량.
	std::cout << "벡터의 capacity V1 : " << V1.capacity() << std::endl;
	std::cout << "벡터의 capacity V2 : " << V2.capacity() << std::endl;
	std::cout << "벡터의 capacity V3 : " << V3.capacity() << std::endl;
	std::cout << "벡터의 capacity V4 : " << V4.capacity() << std::endl;

	V4.push_back(11);
	// 통상적으로 알아서 이전에 있었던 메모리의 반만큼 늘린다. ex) 10 -> 10 + 5 = 15;
	std::cout << "벡터의 capacity V4 (푸시백 후) : " << V4.capacity() << std::endl;


	std::vector<int> V5;
	V5.push_back(1);
	V5.push_back(2);
	V5.push_back(3);
	V5.push_back(4);
	V5.push_back(5);

	std::cout << "=============================================" << std::endl;
	for (int i = 0; i < V5.size(); i++)
	{
		std::cout << "for문으로 벡터 V5[] 출력 : " << V5[i] << std::endl;
		std::cout << "for문으로 벡터 V5.at 출력 : " << V5.at(i) << std::endl; // at으로도 접근 가능.
	}

	std::cout << "=============================================" << std::endl;
	for (int& i : V5)
	{
		// 컨테이너의 모든 요소를 자기가 알아서 돈다.
		// 복사를 하게 되어 복사 비용이 든다.
		// -> 따라서 참조 연산자 &를 붙이는게 좋다.

		i += 1;
		std::cout << "for문(범위기반)으로 벡터 V5 출력 : " << i << std::endl;
	}

	std::cout << "=============================================" << std::endl;
	for (const auto& i : V5) // 컴파일러가 자동으로 타입을 추론해준다. 복잡한 타입을 사용할 때는 유용하다.
	{
		std::cout << "for문(범위기반)으로 벡터 V5 출력 : " << i << std::endl;
	}
	
	// empty() : 벡터가 비어있는지 확인.
	// clear() : 벡터의 모든 요소 제거.
	// at() : 벡터의 요소 접근.
	// front() : 벡터의 첫번째 요소반환.
	// back() : 벡터의 마지막 요소반환.
	// pop_back() : 벡터의 끝에서 요소를 제거.
	// push_back() : 벡터의 끝에 요소 추가.
	// insert() : 지정한 위치에 요소를 삽입
	// erase() : 지정한 위치에 요소를 제거.
	// reserve() : 벡터의 용량을 지정.
	// swap() : 두 벡터를 교환.
	// begin() : 시작점.
	// end() : 끝점.

	std::cout << "=============================================" << std::endl;

	std::vector<int> V6;
	V6.push_back(1);
	V6.push_back(2);
	V6.push_back(3);
	V6.push_back(4);
	V6.insert(V6.begin() + 1, 10); // 인덱스 1에 10 삽입
	V6.erase(V6.begin() + 3); // 인덱스 3에 해당하는 요소 제거.
	V6.pop_back(); // 마지막 요소 제거.

	for (auto& i : V6)
	{
		std::cout << "V6 : " << i << std::endl;
	}
	// 1, 2, 3, 4
	// 1, 10, 2, 3, 4
	// 1, 10, 2, 4
	// 1, 10, 2
	// 결과 1, 10, 2

	std::cout << "=============================================" << std::endl;

	// iterator
	// 포인터와 비슷한 녀석, 컨테이너의 저장된 요소를 순회하고 접근하는 방법.
	// begin()-> 시작을 나타냄(실제 원소를 )
	// end()-> 실제 원소가 아닌 끝을 나타냄 (마지막 요소의 다음)

	std::vector<int> V7;
	V7.push_back(1);
	V7.push_back(2);
	V7.push_back(3);
	V7.push_back(4);
	V7.push_back(5);

	std::cout << "===반복자로 출력 * ==== " << std::endl;
	std::vector<int>::iterator it = V7.begin();
	for (it; it != V7.end(); it++)
	{
		std::cout << "iterator V7 : " << *it << std::endl;
	}

	std::vector<int> V8;
	V8.push_back(1);
	V8.push_back(2);
	V8.push_back(3);
	V8.push_back(4);
	V8.push_back(5);

	std::cout << "====================== " << std::endl;
	std::vector<int>::iterator iter = V8.begin(); // 시작 원소를 가리키는 반복자.
	std::cout << iter[0] << std::endl; // 1
	std::cout << iter[1] << std::endl; // 2
	std::cout << iter[2] << std::endl; // 3
	std::cout << iter[3] << std::endl; // 4
	std::cout << iter[4] << std::endl; // 5
	// std::cout << iter[5] << std::endl; // Error -> 범위 초과시 에러, Out of Range

	iter += 2;
	std::cout << *iter << std::endl; // 시작 위치에서 2 더한 위치 값 출력 => 3.

	std::cout << "====================== " << std::endl;
	for (std::vector<int>::reverse_iterator rit = V8.rbegin(); rit != V8.rend(); rit++)
	{

	}

	std::cout << "====================== " << std::endl;
	
	std::vector<int> Vec = { 10, 20, 30, 40, 50 };
	for (auto it = Vec.begin(); it != Vec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "뻥튀기" << std::endl;
	for (auto& i : Vec)
	{
		i *= 2;
	}
	for (auto it = Vec.begin(); it != Vec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}








	return 0;
}