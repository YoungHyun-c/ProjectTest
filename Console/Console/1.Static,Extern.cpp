#include <iostream>

/*
static,

extern �ܺκ���
�ٸ� ���Ͽ� ���ǵ� ���������� ���� ���Ͽ��� ����� �� �ְ� ���ش�.
���� :
1. ���������� ���������� ���� ���� �ȴ�.
2. �����ϰ� �Ǹ�, ���������� ���������.


*/

// staticVariale.cpp �ȿ� �ִ� ���������� ����
extern int num1;

void Count();
static int sNum;

//============================================
// Ŭ���� ���� static?
// Ŭ���� ���ο��� static���� ����� ������ �ش� Ŭ������
// ��� �ν��Ͻ����� ��������. Ŭ������ �ν��Ͻ����� �������� ���Ǵ� ����.
// �׷��ٴ°� Ŭ������ �ν��Ͻ��� ���̵� ������.

// ���� ���
// Ŭ���� ���ο��� static�� ����Ͽ� ����.
// �� ������ �����Ϸ�����, �ش� Ŭ������ ���� ��������� ������ �˷���.

// �ܺο��� �ʱ�ȭ�ؾ���.
// �������������� ::�� ����ؼ� �ʱ�ȭ�� �ؾ���.

//============================================

class Character
{
private:
	static int count;

	int num = 0;
public:
	Character()
	{
		count++;
	}
	// �Լ� �տ� static�� ���̸�, Ŭ������ �ν��Ͻ� ���� �θ� �� �ִ�.
	// �������� �۾��� �Ҷ� ����� ���� �ȴ�.
	static void PrintCount()
	{
		std::cout << count << std::endl;
		// �Ϲ� ��� ������ ȣ���� �� ����.
		// std::cout << num << std::endl; // -> Error static(����) ����Լ������� static ���������, ����Լ��� ȣ�� �����ϴ�.
	}


};
int Character::count = 0; // �������������ڸ� ���ؼ� �ʱ�ȭ�� �Ѵ�.

int main()
{
	Count();
	Count();
	Count();

	Character::PrintCount();
	Character::Character();
	Character::PrintCount();

	return 0;
}

void Count()
{
	static int x = 0; // ����
	int y = 0; //����
	x = x + 1;
	y = y + 1;

	std::cout << "X�� : " << x << "Y�� : " << y << std::endl;
}