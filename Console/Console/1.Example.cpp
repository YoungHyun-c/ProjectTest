#include <memory>
#include <Windows.h>
#include <iostream>

using namespace std;

void AddHp(int hp, int value)
{
	hp += value;
}


void main()
{
	int hp = 100;
	AddHp(hp, 100);

	// 100?
	cout << hp << endl;

	int a = 0;
}

#pragma region 디자인 패턴 (싱글톤)
/*
▶ 디자인 패턴
-> 객체 지향 프로그래밍 설계 단계에서 자주 발생하는 / 알려진 문제들을 피하기 위해 사용하는 기법 / 패턴이라고 할 수 있다.

▷ 장점.
1. 의사 소통 간결화 -> 효율 증가 (작업 속도 UP)
2. 평준화 되고, 안정적인 코드 동작성을 보장하는 경우가 많다.
  ㄴ 많은 프로그래머가 이미 동일한 증상을 겪어 보았기 때문에 시간이 지남에 따라 해결 방안도 이미 대부분 나온 상태.
3. 프로그래밍 작성에 앞서 디자인 타임에서의 다양한 상황에 대한 가이드 및 방향성 제시에 유리하다.
  ㄴ 경험이 부족하더라도 이미 어느정도 성능과 효율이 보장된 디자인 패턴을 사용하면, 평균이상은 간다.

▷ 단점.
1. 디자인 패턴은 단순히 코드를 설계하고, 작성하는 하나의 방법이다.
  ㄴ 패턴병 조심.
2. 대부분의 디자인 패턴은 원본 부분과 활용 부분으로 나뉘는 경우가 많기 때문에 코드 간결화 면에서는 불리하다.
  ex) 싱글톤을 만들게 되면, 일단 만든 것에 대한 메모리를 사용했다는 것. 

▶ 싱글톤
 -> 프로젝트 전체에서 1개만 존재해야 하는 객체나 클래스 / 또는 프로젝트 전체에서 공유하는 클래스에 적용할 수 있는 패턴이라고 할 수 있다.
 ex) -> Scene 매니저, 1개만 있으면 됨.

★★★★★
▷ 장점
 -> 한번 new를 통해 객체를 생성하며, 만약 프로젝트 어느곳에서도 사용하지 않는다면 인스턴스를 생성하지 않기 때문에,
 메모리 낭비를 방지할 수 있다.
 ex) -> Scene 매니저를 통해 관리를 하면 됨.

▷ 단점
 결합도가 높은 것은 (ex 플레이어, 몬스터) 싱글톤을 적용할 수 없다.
 -> 결합도 (다른 클래스와 결합할 수 있는 정도, 총, 칼, 마법 등등 플레이어와 결합가능)
 싱글톤은 대부분 전역 접근을 전재하기 때문에, 로직이 복잡해 지면, 코드에 대해서 알아보기 힘들어 지고 (스파게티)
 또한 싱글톤 인스턴에게 너무 많은 데이터가 공유된다면, 결합도 이슈는 반드시 발생을 하기 때문에 유지 보수가 아주 힘들다.




게임
-> 설계
	ㄴ 회사(신입)에게 필요로 하는 설계 점수는 1 ~ 2점 사이 ??? -> 기대감이 없고, 업무랑 관련이 없음.
	-> 설계보다, 언어, 문법, 메모리 구조에 대해 더 공부하는게 좋다.
-> 그래픽스
	ㄴ DX, OpenGL, bool칸 -> 언리얼, 유니티를 안쓰고 그래픽스를 쓰겠다는건데, 언어부터 잘해야 가능하다.
	-> 회사 간 이후에 따로 스스로 공부할 내용.
-> 자료구조 + 알고리즘
	ㄴ 
-> 네트워크.
	ㄴ 
*/
//#pragma endregion
//
//template <class T>
//class Singleton
//{
//protected:
//	static T* singleton;
//
//public:
//	static T* getSing(void);
//	void releaseSing(void);
//};
//
//class MainGame : public Singleton<MainGame>
//{
//
//};
//
//template <typename T1, typename T2, typename T3, typename T4, typename T5>
//class Variants
//{
//public:
//	std::map<T1, map<T2, T3>> data;
//
//	Variants(T1 Val1)
//		: data (Val1, nullptr, nullptr, nullptr, nullptr) {}
//
//	template <size_t I>
//	auto getVariable() const -> decltype (std::get<I>(data)) {return std::get<I>(data); }
//	// decltype -> template에서 자료형을 초기화 해주는 애.
//	// 자료형을 컴파일 타임에 정해줘야 하는게 기본이다.
//	// 메모리 사용량이 많아진다, 자료형이 정해지지 않은 것이 들어올때마다, 자료형을 정해주어야 되기 때문에,
//	// 절차가 추가 된다.
//};
//
//#define MAKE_VARIANTS_I(type0, type1)\
//	Varients<type0, void*, void*, void*, void*>(value1, ...)
//// -> 메모리를 소비하지 않고, 전처리기로 처리하겠다.