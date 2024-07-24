#include <iostream>
using namespace std;

// String Class

void StringLength();
void StringCopy();
void StringCopy(const string _Str); // const를 붙이면 안전성을 보장하기 때문에 붙이는게 좋다.
//물론 안에있는 값이 변경되지 않는 안에 한해서.
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
	cout << "문자열이 길이" << Str.length() << endl;
}

void StringCopy()
{
	string Str = "Hello World";
	string dest = Str; // 복사
	cout << "복사된 문자열 : " << dest << endl;

}

void StringCopy(string _Srt)
{
	string dest = _Srt;
	cout << "복사된 문자열 : " << dest << endl;
}

void StringConnection()
{
	string str1 = "Hello, ";
	string str2 = "World";
	// 문자열을 연결.
	str1 += str2; // string클래스 내부에서 연산자가 오버로딩 되어있기 때문에 가능하다.
	cout << "연결된 문자열 : " << str1 << endl;
}

void StringCompare()
{
	string str1 = "Hello";
	string str2 = "Hello";
	string str3 = "World";

	if (str1 == str2)cout << "문자열이 같다." << endl;
	if (str1 < str3) cout << "str1이 str3보다 앞에 있음." << endl;
}

void StringSubStr()
{
	string str = "Hello, World";
	string subStr = str.substr(7, 5); // 원본 문자열의, 특정 시작 위치에서부터 지정한 길이 만큼 반환해준다.
	cout << "Substr 문자열 : " << subStr << endl;
}

void StringReplace()
{
	string Str = "Hello, World";
	Str.replace(7, 5, "C++"); // 문자열내의 특정 위치에서 지정된 범위 만큼 새 문자열로 대체를 하는 것.
	cout << "Replace 문자열 : " << Str << endl;
}

void StringErase()
{
	string Str = "Hello World";
	Str.erase(5, 7); // 시작 위치와, 지울 갯수를 받아 지우는 기능
	// Str.erase(); 전체 지우기
	cout << "Erase 문자열 : " << Str << endl;
}
