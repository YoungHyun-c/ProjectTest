#include <iostream>
using namespace std;

int main()
{
	char c = 'a';
	// char h[3] = "��"; // �ڿ� Null����(\0)�� ���� ������
	char h[4] = "��";

	// ���ڹ迭
	//char str[] = "Hello World";
	//cout << str << endl;
	//cout << sizeof(str) << endl;

	//char str[50];

	//strcpy_s(str, "Hello world");
	//cout << str << endl;

	//// ���ڿ� ���� ���
	//cout << strlen(str) << endl;

	//char str1[] = "Hello";

	//for (int i = 0; str1[i] != '\0'; ++i)
	//{
	//	cout << "����" << i << " : " << str1[i] << endl;
	//}

	//// strcat_s ���ڿ��� �ٿ��ִ� ���
	//char str3[50] = "Hello, ";
	//char str4[] = "world";

	//strcat_s(str3, str4); // ���� ��, ���� ����

	//cout << str3 << endl; // ���� ���� ���

	char str1[] = "Hello";
	char str2[] = "Hello";
	char str3[] = "World";

	// ���ڿ��� �񱳴� ���ڿ��� ���� �����ϸ� ����
	int Result1 = strcmp(str1, str2); // �ΰ��� ���ڿ��� �����ִ� �Լ�.
	int Result2 = strcmp(str1, str3);

	cout << "str1, str2 ��� : " << Result1 << endl; // 0 -> �� ���ڿ��� ������ ��
	cout << "str1, str3 ��� : " << Result2 << endl; // -1 -> �񱳸��Ҷ� ù��° ���ڿ��� �ι�° ���ڿ����� �ռ�������
	// 1-> �񱳸��Ҷ� ù��° ���ڿ��� ���ĺ�(ex h)�� �ι�° ���ڿ��� ���ĺ�(a) ���� �ڿ�������. �빮�� �ҹ��ڵ� ���� �빮�ڰ� ����.

	return 0;
}