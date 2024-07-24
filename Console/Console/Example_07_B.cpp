#include <iostream>
using namespace std;

int main()
{
	char c = 'a';
	// char h[3] = "ㅁ"; // 뒤에 Null문자(\0)가 들어가서 오류남
	char h[4] = "ㅁ";

	// 문자배열
	//char str[] = "Hello World";
	//cout << str << endl;
	//cout << sizeof(str) << endl;

	//char str[50];

	//strcpy_s(str, "Hello world");
	//cout << str << endl;

	//// 문자열 길이 출력
	//cout << strlen(str) << endl;

	//char str1[] = "Hello";

	//for (int i = 0; str1[i] != '\0'; ++i)
	//{
	//	cout << "문자" << i << " : " << str1[i] << endl;
	//}

	//// strcat_s 문자열을 붙여주는 기능
	//char str3[50] = "Hello, ";
	//char str4[] = "world";

	//strcat_s(str3, str4); // 붙일 곳, 붙일 문자

	//cout << str3 << endl; // 붙은 문자 출력

	char str1[] = "Hello";
	char str2[] = "Hello";
	char str3[] = "World";

	// 문자열의 비교는 문자열의 끝에 도달하면 종료
	int Result1 = strcmp(str1, str2); // 두개의 문자열을 비교해주는 함수.
	int Result2 = strcmp(str1, str3);

	cout << "str1, str2 결과 : " << Result1 << endl; // 0 -> 두 문자열이 동일할 때
	cout << "str1, str3 결과 : " << Result2 << endl; // -1 -> 비교를할때 첫번째 문자열이 두번째 문자열보다 앞서있으면
	// 1-> 비교를할때 첫번째 문자열의 알파벳(ex h)이 두번째 문자열의 알파벳(a) 보다 뒤에있으면. 대문자 소문자도 구분 대문자가 먼저.

	return 0;
}