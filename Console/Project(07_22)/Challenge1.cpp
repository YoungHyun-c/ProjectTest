#include <iostream>

//도전 과제 1. 문자열 관련 테스트
//
//- 펄어비스
//<주의 사항>
//C++ 언어로 풀어야 하고, 빈칸을 알맞게 채워 넣으시오.
//C 런타임 라이브러리 / STL등 기타 라이브러리 함수를 사용하면 안됩니다.
//특히 STL string을 사용시 바로 탈락 처리되니 유의 바랍니다.
//그리고 해당 방법에 대해 왜 그렇게 작성을 했는지 짧은 주석을 넣어 주세요.
//
//문제.주어진 문자열을 단어 단위로 순서를 뒤집어 출력하시오,
//<예>
//입력 값 : "Hello World this is Pearl Abyss"
//반환 값 : "Pearl Abyss is this World Hello" 펄어비스는 안뒤집음.
//<조건>
//입력 문자열은 앞뒤에 공백이 없다고 가정
//모든 단어는 공백 한 칸으로 구분된다고 가정.
//
//void ReverseWords(char* output, int outputArraySize, cont char* input)
//{
//	// 이 곳을 채워 넣으시오.
//}
//
//작성이 끝나면 시간 복잡도를 계산하는 수식을 별도의 함수로 구현하고,
//동작방식과 왜 그렇게 작성했는지 기술하시오.

void Swap(char* pA, char* pB)
{
	char ch = *pA;
	*pA = *pB;
	*pB = ch;
}

void Reverse(char* _Begin, char* _End)
{
	while (_Begin + 1 < _End)
	{
		Swap(_Begin++, --_End);
	}
}

void Reverse_By_Index(char* _Str, size_t _Ibegin, size_t _iEnd)
{
	Reverse(_Str + _Ibegin, _Str + _iEnd);
}

void ReverseWords(char* _OutPut, int const _OutPutArraySize, char* _Input)
{
	int Len = _OutPutArraySize;

	size_t ibegin = 0;
	size_t chars = 0;
	size_t redundant_spaces = 0;

	for (size_t i = 0; i <= Len; i++)
	{
		if (*(_Input + i) == ' ' || *(_Input + i) == '\0')
		{
			if (chars > 0)
			{
				Reverse_By_Index(_Input, ibegin, i);
				ibegin = i + 1;
				chars = 0;
			}
			else
			{
				redundant_spaces++;
			}
		}
		else
		{
			chars++;
		}
	}
}

void ReverseByWords(char* _Str, size_t _Len)
{
	Reverse_By_Index(_Str, 0, _Len);
	ReverseByWords(_Str, _Len);
}

size_t trim_right(char* _Str, size_t _Len)
{
	size_t i = _Len - 1;
	for (; i >= 0 && *(_Str + i) == ' '; i--){}
	if (i != _Len - 1)
	{
		*(_Str + i + 1) = '\0';
	}

	return i + 1;
}

size_t reverse_words_with_trim(char* _Str, size_t _Len)
{
	Reverse_By_Index(_Str, 0, _Len);
	ReverseWords(_Str, _Len, _Str);
	return trim_right(_Str, _Len);
}

int main()
{
	char S1[] = "Hello World this is Pearl Abyss";
	ReverseWords(S1, strlen(S1), S1);

	for (int i = 0; i < strlen(S1); i++)
	{
		std::cout << S1[i];
	}

	return 0;
}