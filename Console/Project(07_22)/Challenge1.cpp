#include <iostream>

//���� ���� 1. ���ڿ� ���� �׽�Ʈ
//
//- �޾��
//<���� ����>
//C++ ���� Ǯ��� �ϰ�, ��ĭ�� �˸°� ä�� �����ÿ�.
//C ��Ÿ�� ���̺귯�� / STL�� ��Ÿ ���̺귯�� �Լ��� ����ϸ� �ȵ˴ϴ�.
//Ư�� STL string�� ���� �ٷ� Ż�� ó���Ǵ� ���� �ٶ��ϴ�.
//�׸��� �ش� ����� ���� �� �׷��� �ۼ��� �ߴ��� ª�� �ּ��� �־� �ּ���.
//
//����.�־��� ���ڿ��� �ܾ� ������ ������ ������ ����Ͻÿ�,
//<��>
//�Է� �� : "Hello World this is Pearl Abyss"
//��ȯ �� : "Pearl Abyss is this World Hello" �޾�񽺴� �ȵ�����.
//<����>
//�Է� ���ڿ��� �յڿ� ������ ���ٰ� ����
//��� �ܾ�� ���� �� ĭ���� ���еȴٰ� ����.
//
//void ReverseWords(char* output, int outputArraySize, cont char* input)
//{
//	// �� ���� ä�� �����ÿ�.
//}
//
//�ۼ��� ������ �ð� ���⵵�� ����ϴ� ������ ������ �Լ��� �����ϰ�,
//���۹�İ� �� �׷��� �ۼ��ߴ��� ����Ͻÿ�.

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