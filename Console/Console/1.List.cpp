#include <iostream>
#include <list>
#include <map>

/*
벡터와 리스트의 차이점은 반드시 알아두어야 한다.


리스트
임의의 접근 가능한 반복자를 지원하지 않는다.
-> 순차 접근만 가능하다. -> 벡터와 상대적으로 찾는게 느리다.
-> 벡터보다 상대적으로 메모리 사용량이 높다. -> 포인터도 담아야되면
-> 중간삭제시, 이전 노드와 다음 노드의 연결을 끊고, 이전에 있던 노드와 다음에있던 노드끼리 연결한다. insert

멤버함수
push_back : 리스트 끝에 추가.
push_front : 리스트 앞에 추가
pop_back : 리스트 끝 요소제거.
pop_front : 리스트 앞 요소제거.
insert : 지정된 위치의 요소 삽입.
erase : 지정된 위치의 요소 제거.
Clear : 모든 요소 제거.
size : 리스트 요소 갯수 반환.
front : 첫 번째 요소 반환
back : 마지막 요소 반환.
remove : 지정한 값을 가지는 모든 요소 제거.
reverse : 리스트 순서 뒤집음.
sort : 정렬.


연관 컨테이너
Map은 자주 쓰이게 된다.

Map
-> 연관컨테이너 중에 자주 사용하는 컨테이너.
-> Key, Value의 쌍으로 저장(pair)
-> Key 값은 컨테이너에 중복으로 저장할 수 없다. -> 만약 중복으로 저장하고 싶으면, Multimap을 쓰면 된다.
-> 내부 구조는 이진 검색 트리로 되어있다. -> Red Black Tree
-> 





*/


int main()
{
	std::list<int> List = { 3, 1, 45, 7, 10 };

	List.push_back(9); // 리스트 끝에 9 추가,

	for (auto& i : List)
	{
		std::cout << i << std::endl;
	}

	List.push_front(6); // 리스트 앞에 6 추가.

	std::list<int>::iterator Iter = List.begin();
	
	std::map<std::string, int> data;
	// 반복자.
	std::map<std::string, int>::iterator mIter = data.begin();
	
	
	// Pair
	// 두개의 값을 묶어서 하나의 객체로 사용하는 템플릿 클래스
	// 두개의 서로 다른 타입의 값을 함께 저장가능
	// 페어는 두개의 멤버를 가지고 있다.
	// first, second.
	std::pair<std::string, int> Pair;

	// 1. value_type을 이용한 방법
	// 기본적인 키 - 값을 쌍으로 타입을 나타낸다.
	// 두개의 서로 다른 타입의 값도 저장할 수 있다.
	// pair 객체를 생성한 다음에 insert에 전달.
	// 가독성이 떨어짐.
	data.insert(std::map<std::string, int>::value_type("바보", 1));

	// 2. make_pair : pair라는 객체를 생성하는 함수 템플릿.
	// make_pair("윈터", 5) -> std::pair<string, list> 요러한 형태의 객체를 생성해준다. 둘이 같다.
	// 템플릿 인자를 자동으로 추론함.
	data.insert(std::make_pair("윈터", 5));

	// 3. Pair를 이용한 방법.
	data.insert(std::pair<std::string, int>("BTS", 10));
	data.insert(std::pair<std::string, int>("반장", 30));
	data.insert(std::pair<std::string, int>("아이유", 170));
	data.insert(std::pair<std::string, int>("정우성", 400));
	data.insert(std::pair<std::string, int>("언리얼", 20));
	
	// 4. 객체를 직접 생성하는 방법.
	std::pair<std::string, int> Pt1("대한민국", 10);
	data.insert(Pt1);

	data.erase("정우성");

	for (auto& pPair : data)
	{
		std::cout << "키 값 : " << pPair.first << " 데이터 값 : " << pPair.second << std::endl;
	}
	
	std::map<std::string, int> m;
	m.insert(std::pair<std::string, int>("Apple", 1));
	m.insert(std::pair<std::string, int > ("Banana", 2));
	m.insert(std::make_pair("Grape", 3));

	auto Res = m.insert(std::make_pair("Banana", 10));

	if (!Res.second)
	{
		// 위에서 2로 만들었기에 10은 안만들어진다.
		std::cout << "바나나는 있을까? : " << Res.first->second << std::endl;
	}
	
	// find
	auto aiter = m.find("Apple");
	if (aiter != m.end())
	{
		std::cout << "찾음! " << aiter->second << std::endl;
	}
	else
	{
		std::cout << "없음" << std::endl;
	}

	// Count -> 주어진 키의 갯수를 리턴. 0이나 1을 리턴
	std::cout << "Apple : " << m.count("Apple") << std::endl;
	std::cout << "사이즈 : " << m.size() << std::endl;

	// Clear : 모든 요소를 삭제함.
	// empty : 비어있냐?
	// size : 맵에 저장된 요소 개수를 리턴.
	for (auto it = m.begin(); it != m.end(); ++it)
	{

	}
	// 역순
	for (auto it = m.rbegin(); it != m.rend(); ++it)
	{

	}

	return 0;
}