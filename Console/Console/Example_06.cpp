#include <iostream>



// �迭
// ����� �����͸� �����ϴ� �Ͱ� ����.
// ���� �ڷ����� ���� ���ӵ� �޸� �������� �̷���� �ڷᱸ��.
// �̷� �迭�� ���� �ڷ����� ���� �������� ������ �ʿ��Ҷ� ���.
// ���� ���� �����͸� ó���� �� �����ϴ�.
int main()
{
	int num;
	int num1;
	int num2;
	int num3;
	int num4;
	int num1000 = 10;

	
	// �迭 ������
	//					 [�迭 ����]
	// �ڷ��� / �迭 �̸� [10] ;
	int arr[4] = { 1, 2, 3, 4 };

#pragma region �ʱ�ȭ ���
	// �迭�� �ʱ�ȭ ���
	/*
	1. ũ�⸦ ����ϰ� �ʱ�ȭ
	int arr[4] = {1, 2, 3, 4};
	
	2. �迭�� ũ�⸦ �����ϰ� �ʱ�ȭ
	int arr[] = { 1, 2, 3 };

	3. ũ�⸦ ��������� �����ϰ�, �Ϻ� ��Ҹ� �ʱ�ȭ
	int arr[5] = { 1, 2, 3 }; // �������� 0���� �ڵ� �ʱ�ȭ

	4. ��� ��Ҹ� �ʱ�ȭ ���� ����
	int arr[5] = {}; // 0���� �ڵ� �ʱ�ȭ
	*/
#pragma endregion


#pragma region Arr01 1���� �迭

	//std::cout << "arr[0] ��° ������ : " << arr[0] << std::endl;
	//std::cout << "arr[1] ��° ������ : " << arr[1] << std::endl;
	//std::cout << "arr[2] ��° ������ : " << arr[2] << std::endl;
	//std::cout << "arr[3] ��° ������ : " << arr[3] << std::endl;

	//std::cout << "=================================" << std::endl;

	//std::cout << arr << std::endl; // �迭�� ���� �ּҴ� �迭�� 0��° �ε��� �ּҿ� ����.
	//std::cout << &arr[0] << std::endl;
	//std::cout << &arr[1] << std::endl;
	//std::cout << &arr[2] << std::endl;
	//std::cout << &arr[3] << std::endl;

	//std::cout << "for ���� �̿��� �迭 ��� " << std::endl;
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
	//// ���� 10���� �л� ������ �Է�-> �迭�� �����ϰ�, ������ ����� ���Ϸ���?
	//// �Է� -> ó�� -> ���
	//std::cout << "===================================" << std::endl;
	//int Total = 0;
	//int Ave = 0;
	//constexpr int StudentNum = 10;

	//int Student[StudentNum] = { };

	//for (int i = 0; i < StudentNum; i++)
	//{
	//	int Point = 0;
	//	printf("%d��° �л� ������ �Է��ϼ��� : ", i+1);
	//	std::cin >> Student[i];
	//	Total += Student[i];
	//}

	//Ave = Total / StudentNum;

	//std::cout << "�� ���� : " << Total << std::endl;
	//std::cout << "��� ���� : " << Ave << std::endl;

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

	std::cout << "0�� ��� ���" << &arr1[0][0] << "," << &arr1[0][1] << "," << &arr1[0][2] << std::endl;
	std::cout << "1�� ��� ���" << &arr1[1][0] << "," << &arr1[1][1] << "," << &arr1[1][2] << std::endl;
	std::cout << "2�� ��� ���" << arr1[2][0] << "," << arr1[2][1] << "," << arr1[2][2] << std::endl;
	std::cout << "3�� ��� ���" << arr1[3][0] << "," << arr1[3][1] << "," << arr1[3][2] << std::endl;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << arr1[i][j] << std::endl;
		}
	}


	// 1.���ݺ��� 4���� �������
	// �迭�� Ȱ���ϱ�
	// ��ǲ�� �޾Ƽ� �Է¹��� ������ ������ ��� ����� �迭�� �����ϰ� ����ϱ�. �� �Է½�, ���� ��� ��� �迭�� �����ϰ� , ���

	//2. ���� ǥ���� ���� �հ�, ������ ��� ���� ���� ���ض�.
	/*
		����
		90 78 77 66 55
		90 78 48 18 58
		89 58 76 85 78
		48 68 79 85 87
	*/


	const int ArraySize = 8;
	int* MyVariableSizxeArray = new int[ArraySize];




	return 0;
}