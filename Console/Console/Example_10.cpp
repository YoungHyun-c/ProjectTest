#include <iostream>
#include <string>

#pragma region Ŭ������
/*
========================================
class
- ��ü���� ���α׷���?
 �� �츮�� ��� �ִ� ���� ���谡 ��ü��� �����Ǿ�, �ִ� �� ó��
 ����Ʈ��� ��ü�� �����ϴ� ���.
 �� ���, TV, ��Ź��, ����� ���... ���� ��ü�� ����
 �� ������ ����� �����ϰ�, �ٸ� ��ü��� ��ȣ�ۿ��� �Ѵ�.

 -> ��ü?
 �� Ŭ����-> Ʋ�̳� ���赵 -> ��ü�� �����ϴ� Ʋ�̳� ���赵
 �� Ʋ�� ��������� �ǳ�? -> ��Ծ�� �ȴ�.
 �� ��ü�� ���赵�� ������� ��üȭ ��Ű�� ��. -> �׷��� ���������ϱ�
========================================
*/
#pragma endregion
// ����ü
struct Circle
{
public:
	int Radius;
	std::string Color;
	double calArea()
	{
		return 3.14 * Radius * Radius;
	}
};
// Ŭ����
// ����ü�� Ŭ������ �ٸ���?
class Circle1
{
private:
	int radius;
	std::string Color;
	double claArea()
	{
		return 3.14 * radius * radius;
	}
};

class MyClass
{
public:

private:

private:

};

class Student
{
private:

public:

	void Print() { std::cout << "��Ʃ��Ʈ Ŭ������ ����Ʈ �Լ�"; }
	void Print(int a, int b) {}
	void Print(std::string Str = "����Ʈ �Ű�����") { std::cout << Str << std::endl; }

	int Sum(int a, int b);
};

class Square
{
public:
	void SetXY(int _X, int _Y)
	{
		X = _X;
		Y = _Y;
		std::cout << "�簢���� X : " << X << std::endl;
		std::cout << "�簢���� Y : " << Y << std::endl;
	}

	void AreaCalcul()
	{
		Area = X * Y;
	}

	void AreaPrint() const
	{
		std::cout << "�簢���� ���� : " << Area << std::endl;
	}

private:
	int X = 0;
	int Y = 0;
	int Area = 0;
};

int main()
{
	// ����ü
	Circle C;
	C.Radius = 5;

	// Ŭ����
	Circle1 CC;
	// ������ �ȵȴ�. default �������� �����ڰ� �ٸ��� �����̴�.
	//CC.radius = 5;
	
	// ����ü�� Ŭ������ ���̴� ����Ʈ �������������ڰ� �ٸ���.
	// private, public, protected.
	// ����ü�� �Ϲ������� public:
	// Ŭ������ �Ϲ������� Private:
	// private: Ŭ���� ���ο����� ��������. -> ��������
	// �����ܾ��� ������� 
	// public : �Լ�(���), ������, �Ҹ���, 

	/*
	��������		Ŭ��������		Ŭ�����ܺ�		���Ŭ����
	private			O				X				X
	public			O				O				O
	protectd		O				X				O
	*/

	Square N;
	int X, Y = 0;
	std::cout << "X ���� �Է����ּ��� : ";
	std::cin >> X;
	std::cout << "Y ���� �Է����ּ��� : ";
	std::cin >> Y;
	N.SetXY(X, Y);
	N.AreaCalcul();
	N.AreaPrint();



	return 0;
}

int Student::Sum(int a, int b)
{
	return 0;
}

/*
�簢���� Ŭ������ ��������
-��� �Լ��δ� �簢���� ���̸� ���.
�� ��±��� �غ�����


*/