#include <iostream>
#include <Windows.h>

// 1. ����
void Character()
{
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
	std::cout << "���������������������������������������������������" << std::endl;
}

void Gotoxy(short X, short Y)
{
	COORD pos = { X, Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void NemoPrint(int X, int Y, int Xlength) 
{
	Gotoxy(X, Y);

	for (int i = 0; i < Xlength; i++)
	{
		std::cout << "���";
	}
	std::cout << std::endl;
}

void RevTriPrint(int X, int Y, int Xlength)
{
	Gotoxy(X, Y);

	for (int i = 0; i < Xlength; i++)
	{
		std::cout << "���";
	}
	std::cout << std::endl;
}

void TriPrint(int X, int Y, int Xlength)
{
	Gotoxy(X, Y);

	for (int i = 0; i < Xlength; i++)
	{
		std::cout << "���";
	}
	std::cout << std::endl;
}

void CharacterXY()
{
	NemoPrint(15, 2, 5);
	NemoPrint(11, 3, 9);
	NemoPrint(9, 4, 11);
	NemoPrint(9, 5, 11);
	NemoPrint(7, 6, 13);
	NemoPrint(7, 7, 1); NemoPrint(15, 7, 3); NemoPrint(27, 7, 3);
	NemoPrint(7, 8, 1); NemoPrint(11, 8, 1); NemoPrint(15, 8, 2); NemoPrint(23, 8, 1); NemoPrint(29, 8, 2);
	NemoPrint(7, 9, 1); NemoPrint(11, 9, 1); NemoPrint(15, 9, 2); NemoPrint(23, 9, 1); NemoPrint(29, 9, 2);
	NemoPrint(7, 10, 1);  NemoPrint(29, 10, 2);
	NemoPrint(9, 11, 1);  NemoPrint(29, 11, 1);
	NemoPrint(11, 12, 1); NemoPrint(27, 12, 3);
	NemoPrint(9, 13, 1); NemoPrint(13, 13, 10);
	NemoPrint(7, 14, 2); NemoPrint(33, 14, 1);
	NemoPrint(5, 15, 1); NemoPrint(9, 15, 1); NemoPrint(33, 15, 1);
	NemoPrint(5, 16, 1); NemoPrint(9, 16, 1); NemoPrint(25, 16, 1); NemoPrint(35, 16, 1);
	NemoPrint(3, 17, 1); NemoPrint(7, 17, 1); NemoPrint(25, 17, 1); NemoPrint(37, 17, 1);
	NemoPrint(3, 18, 1); NemoPrint(7, 18, 1); NemoPrint(25, 18, 1); NemoPrint(31, 18, 1); NemoPrint(37, 18, 1);
	NemoPrint(1, 19, 1); NemoPrint(7, 19, 1); NemoPrint(25, 19, 1); NemoPrint(31, 19, 1); NemoPrint(37, 19, 1);
	NemoPrint(1, 20, 1); NemoPrint(5, 20, 1); NemoPrint(27, 20, 1); NemoPrint(31, 20, 1); NemoPrint(39, 20, 1);
	NemoPrint(3, 21, 2); NemoPrint(29, 21, 2); NemoPrint(39, 21, 1);
	NemoPrint(5, 22, 1); NemoPrint(39, 22, 1);
	NemoPrint(5, 23, 1); NemoPrint(39, 23, 1);
	NemoPrint(5, 24, 1); NemoPrint(29, 24, 1); NemoPrint(37, 24, 1);
	NemoPrint(5, 25, 1); NemoPrint(9, 25, 1); NemoPrint(27, 25, 1); NemoPrint(35, 25, 1);
	NemoPrint(7, 26, 3); NemoPrint(25, 26, 3); NemoPrint(33, 26, 1);
	NemoPrint(7, 27, 1); NemoPrint(13, 27, 6); NemoPrint(31, 27, 1);
	NemoPrint(9,28, 2); NemoPrint(25, 28, 3);

	// ��
	RevTriPrint(15, 10, 2);
	TriPrint(15, 11, 2);
}

// 2. ����
void Myself()
{
	std::cout << "========================================================" << std::endl;
	std::cout << "�̸�   : ȫ���� " << std::endl;
	std::cout << "����   : 28" << std::endl;
	std::cout << "����ó : 010-3424-1433" << std::endl;
	std::cout << "�ּ�   : ����Ư���� ��� 1�� 17 �Ѿ����� APT 101�� 403ȣ" << std::endl;
	std::cout << "�̸��� : dudgus614@naver.com" << std::endl;
	std::cout << "����   : ��ǥ�ϴ� ȸ�翡 ���ڽ��ϴ�." << std::endl;
	std::cout << "������� ȸ��  : �ؽ�" << std::endl;
	std::cout << "������������ : �ν�Ʈ��ũ" << std::endl;
	std::cout << "���   : �����ϴ� ��" << std::endl;
	std::cout << "========================================================" << std::endl;
}

// 3. ��������
#include <string.h>
class Introduce
{

public :
	void PrintIntroduceMyself()
	{
		std::cout << "========================================================" << std::endl;
		std::cout << "�̸�   : " << Name << std::endl;
		std::cout << "����   : " << Age << std::endl;
		std::cout << "����ó : " << PhoneNum << std::endl;
		std::cout << "�ּ�   : " << Address << std::endl;
		std::cout << "�̸��� : " << Email << std::endl;
		std::cout << "����   : " << Resolution << std::endl;
		std::cout << "������� ȸ��  : " << WCompany << std::endl;
		std::cout << "������������ : " << WMGame << std::endl;
		std::cout << "���   : " << Hobby << std::endl;
		std::cout << "========================================================";
	}

public:
	std::string Name = " ";
	std::string Age = " ";
	std::string PhoneNum = " ";
	std::string Address = " ";
	std::string Email = " ";
	std::string Resolution = " ";
	std::string WCompany = " ";
	std::string WMGame = " ";
	std::string Hobby = " ";
};


int main()
{
	// 1. ����. �밡��
	//Character();

	// 1. ����. ��ǥ
	//CharacterXY();

	// 2. ����
	Myself();

	// 1. ��������
	Introduce Myself;

	Myself.Name = "ȫ����";
	Myself.Age = "28";
	Myself.PhoneNum = "010-3424-1433";
	Myself.Email = "dudgus614@naver.com";
	Myself.Address = "����Ư���� ��� 1�� 17 �Ѿ����� APT 101�� 403ȣ";
	Myself.Resolution = "��ǥ�ϴ� ȸ�翡 ���ڽ��ϴ�.";
	Myself.WCompany = "�ؽ�";
	Myself.WMGame = "�ν�Ʈ��ũ";
	Myself.Hobby = "�����ϴ� ��";

	Myself.PrintIntroduceMyself();

	return 0;
}
