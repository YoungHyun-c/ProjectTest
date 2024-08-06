#include <iostream>

/*
다형성
-> 객체의 속성이나 기능이 상황에 따라 여러가지 형태를 가질 수 있는 성질

VirtualFunction
// 상속관게에 있는 클래스에서 부모클래스의 함수를 자식 클래스에서의 재정의(오버라이딩)
// 재정의하고, 부모클래스의 포인터나 참조를 통해 자식클래스의 함수 호출

★★★★★★
면접질문
// 오버로딩 VS 오버라이딩 ?
virtual을 왜 붙이나요.
부모 클래스 함수에 virtual을 붙여야 자식클래스에서 override 함수 호출
동적 바인딩, 정적 바인딩


*/

#include "Bike.h"
#include "Car.h"

int main()
{
	Vehicle* v; // 부모 포인터  // 동적바인딩 -> 부모 포인터로, 자식클래스를 참조하여 사용.
	
	v = new Car("현기차"); // 자식
	v->Move();

	delete v;

	v = new Bike("오토바이");
	v->Move();
	delete v;



	return 0;
}