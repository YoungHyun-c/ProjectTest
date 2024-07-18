#include <iostream>


#pragma region 과제1
// For
void ForGo()
{
	int Result = 0;
	for (int i = 1; i < 10; i++)
	{
		std::cout << i << "단 : " << std::endl;
		for (int j = 1; j < 10; j++)
		{
			Result = i * j;
			std::cout << i << " * " << j << " = " << Result << "  ";
		}
		std::cout << '\n';
	}
}

// While
void WhileGO()
{
	bool End = true;

	int Result = 0;
	int i = 1;

	while (End)
	{
		int j = 1;
		printf("%d 단 : \n", i);

		while (j < 10)
		{
			Result = i * j;
			printf("%d * %d = %d  ", i, j, Result);

			j++;
		}

		printf("\n");
		i++;

		if (i >= 10)
		{
			End = false;
		}
	}
}
// Do While
void DoWhileGO()
{
	int Result = 0;
	int i = 1;
	do
	{
		int j = 1;
		printf("%d 단 : \n", i);
		do
		{
			Result = i * j;
			printf("%d * %d = %d ", i, j, Result);
			j++;
		} while (j < 10);

		printf("\n");
		i++;
	} while (i < 10);



}
#pragma endregion

#pragma region 과제2

void AResult(int _Num1, int _Num2)
{
	std::cout << "덧셈 : " << _Num1 + _Num2 << " ";

	std::cout << "뺄셈 : " << _Num1 - _Num2 << std::endl;
}

void BResult(int _Num1, int _Num2, int _Num3)
{
	int Result = (_Num1 + _Num2) * (_Num3 + _Num1) % _Num1;
	printf("식 : (_Num1 + _Num2) * (_Num3 + _Num1) % _Num1 = ? \n");
	printf("(%d + %d) * (%d + %d) %% %d = %d", _Num1, _Num2, _Num3, _Num1, _Num1, Result);
}

#pragma endregion

int main()
{
	// 과제1.
	{
		//ForGo();
		//WhileGO();
		//DoWhileGO();
	}

	// 과제 2.
	{
		// a
		/*{
			int Num1, Num2 = 0;
			std::cout << "첫번째 정수 : ";
			std::cin >> Num1;
			std::cout << "두번째 정수 : ";
			std::cin >> Num2;
			AResult(Num1, Num2);
		}*/
		// b
		/* {
			int Num1, Num2, Num3 = 0;
			std::cout << "첫번째 정수 : ";
			std::cin >> Num1;
			std::cout << "두번째 정수 : ";
			std::cin >> Num2;
			std::cout << "세번째 정수 : ";
			std::cin >> Num3;
			BResult(Num1, Num2, Num3);
		}*/
		// c
		/*{
			int Num1, Num2 = 0;
			std::cout << "첫번째 정수 :";
			std::cin >> Num1;
			std::cout << "두번째 정수 :";
			std::cin >> Num2;

			printf("%d / %d = ? \n", Num1, Num2);
			printf("몫 : %d , 나머지 : %d \n", Num1 / Num2, Num1 % Num2);
		}*/

	}

	// 과제 3.
	{
		// for
		/*{
			for (int i = 2; i < 22; i += 2)
			{
				std::cout << i << " ";
			}
			std::cout << '\n';
		}*/

		// while
		/*{
			int i = 2;
			while (i <= 20)
			{
				std::cout << i << " ";
				i += 2;
			}
		}*/

		// do while
		/*{
			int i = 2;
			do
			{
				std::cout << i << " ";
				i += 2;
			} while (i <= 20);

		}*/
	}

	// 과제 4.
	{
		//int Num = 0, Result = 0;
		////do
		//{
		//	std::cout << "입력 숫자(-10 ~ 10) : ";
		//	std::cin >> Num;
		//	while (Num > -10 && Num < 10)
		//	{
		//		for (int Result = Num; Result >= -15; Result -= 5)
		//		{
		//			std::cout << Result << " ";
		//		}
		//		std::cout << '\n';
		//		std::cout << "입력 숫자(-10 ~ 10) : ";
		//		std::cin >> Num;
		//	}
		//}// while (Num > -10 && Num < 10);
	}

	// 과제 5. 별찍기
	{
		// 줄어들기
		//****
		//***
		//**
		//*
		bool Value = true;
		/*while (Value)
		{
			int Num = 0;
			std::cout << "입력 하고 싶은 수(0 입력시 종료) : ";
			std::cin >> Num;

			for (int i = Num; i > 0; i--)
			{
				for (int j = i; j > 0; j--)
				{
					std::cout << "*";
				}
				std::cout << "\n";
			}

			while (Num == 0)
			{
				Value = false;
			}
		}*/

		// 늘어나기
		//*
		//**
		//***
		//****
		/*while (Value)
		{
			int Num = 0;
			std::cout << "입력 하고 싶은 수(0 입력시 종료) : ";
			std::cin >> Num;

			for (int i = 0; i < Num; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					std::cout << "*";
				}
				std::cout << "\n";
			}

			while (Num == 0)
			{
				Value = false;
			}
		}*/

		// ****
		//  ***
		//   **
		//    *
		// 역으로 줄어들기
		/*while (Value)
		{
			int Num = 0;
			std::cout << "입력 하고 싶은 수(0 입력시 종료) : ";
			std::cin >> Num;

			for (int j = Num; j > 0; j--)
			{
				for (int k = 0; k < Num - j; k++)
				{
					std::cout << " ";
				}
				for (int i = j; i > 0; i--)
				{
					std::cout << "*";
				}
				std::cout << '\n';
			}

			while (Num == 0)
			{
				Value = false;
			}
		}*/

		// 밑에서 위로 늘어나기
		//    *
		//   **
		//  ***
		// ****
		/*while (Value)
		{
			int Num = 0;
			std::cout << "입력 하고 싶은 수(0 입력시 종료) : ";
			std::cin >> Num;

			for (int j = Num; j > 0; j--)
			{
				for (int i = j; i > 0; i--)
				{
					std::cout << " ";
				}
				for (int k = 0; k <= Num - j; k++)
				{
					std::cout << "*";
				}
				std::cout << '\n';
			}

			while (Num == 0)
			{
				Value = false;
			}
		}*/

		// 마름모 그리기
		{
			int Num = 12;
			int Mul = 0;
			for (int i = 1; i <= 7; i++)
			{
				for (int j = 0; j < Num / 2; j++)
				{
					printf(" ");
				}

				for (int j = 0; j < 2 * Mul; j++)
				{
					printf("*");
				}

				for (int j = Num / 2; j < Num; j++)
				{
					printf(" ");
				}

				Num -= 2;
				Mul++;
				std::cout << "\n";
			}

			int SubValue = 10;
			for (int i = 1; i <= 7; i++)
			{
				for (int j = 0; j < i; j++)
				{
					printf(" ");
				}

				for (int j = 0; j < SubValue; j++)
				{
					printf("*");
				}

				for (int j = 0; j < i; j++)
				{
					printf(" ");
				}

				SubValue -= 2;
				std::cout << "\n";
			}
		}

	}

	return 0;
}