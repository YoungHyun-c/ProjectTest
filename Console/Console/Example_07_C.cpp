#include <iostream>
using namespace std;

// String Class

void StringLength();
void StringCopy();
void StringCopy(const string _Str); // const�� ���̸� �������� �����ϱ� ������ ���̴°� ����.
//���� �ȿ��ִ� ���� ������� �ʴ� �ȿ� ���ؼ�.
void StringConnection();
void StringCompare();
void StringSubStr();
void StringReplace();
void StringErase();


int main()
{
	//string s;

	StringLength();
	StringCopy();
	StringConnection();
	StringCompare();
	StringSubStr();
	StringReplace();
	StringErase();


	return 0;
}

void StringLength()
{
	string Str = "Hello World";
	cout << "���ڿ��� ����" << Str.length() << endl;
}

void StringCopy()
{
	string Str = "Hello World";
	string dest = Str; // ����
	cout << "����� ���ڿ� : " << dest << endl;

}

void StringCopy(string _Srt)
{
	string dest = _Srt;
	cout << "����� ���ڿ� : " << dest << endl;
}

void StringConnection()
{
	string str1 = "Hello, ";
	string str2 = "World";
	// ���ڿ��� ����.
	str1 += str2; // stringŬ���� ���ο��� �����ڰ� �����ε� �Ǿ��ֱ� ������ �����ϴ�.
	cout << "����� ���ڿ� : " << str1 << endl;
}

void StringCompare()
{
	string str1 = "Hello";
	string str2 = "Hello";
	string str3 = "World";

	if (str1 == str2)cout << "���ڿ��� ����." << endl;
	if (str1 < str3) cout << "str1�� str3���� �տ� ����." << endl;
}

void StringSubStr()
{
	string str = "Hello, World";
	string subStr = str.substr(7, 5); // ���� ���ڿ���, Ư�� ���� ��ġ�������� ������ ���� ��ŭ ��ȯ���ش�.
	cout << "Substr ���ڿ� : " << subStr << endl;
}

void StringReplace()
{
	string Str = "Hello, World";
	Str.replace(7, 5, "C++"); // ���ڿ����� Ư�� ��ġ���� ������ ���� ��ŭ �� ���ڿ��� ��ü�� �ϴ� ��.
	cout << "Replace ���ڿ� : " << Str << endl;
}

void StringErase()
{
	string Str = "Hello World";
	Str.erase(5, 7); // ���� ��ġ��, ���� ������ �޾� ����� ���
	// Str.erase(); ��ü �����
	cout << "Erase ���ڿ� : " << Str << endl;
}
