#include <iostream>


#pragma region ����1
// For
void ForGo()
{
	int Result = 0;
	for (int i = 1; i < 10; i++)
	{
		std::cout << i << "�� : " << std::endl;
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
		printf("%d �� : \n", i);

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
		printf("%d �� : \n", i);
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

#pragma region ����2

void AResult(int _Num1, int _Num2)
{
	std::cout << "���� : " << _Num1 + _Num2 << " ";

	std::cout << "���� : " << _Num1 - _Num2 << std::endl;
}

void BResult(int _Num1, int _Num2, int _Num3)
{
	int Result = (_Num1 + _Num2) * (_Num3 + _Num1) % _Num1;
	printf("�� : (_Num1 + _Num2) * (_Num3 + _Num1) % _Num1 = ? \n");
	printf("(%d + %d) * (%d + %d) %% %d = %d", _Num1, _Num2, _Num3, _Num1, _Num1, Result);
}

#pragma endregion

int main()
{
	// ����1.
	{
		//ForGo();
		//WhileGO();
		//DoWhileGO();
	}

	// ���� 2.
	{
		// a
		/*{
			int Num1, Num2 = 0;
			std::cout << "ù��° ���� : ";
			std::cin >> Num1;
			std::cout << "�ι�° ���� : ";
			std::cin >> Num2;
			AResult(Num1, Num2);
		}*/
		// b
		/* {
			int Num1, Num2, Num3 = 0;
			std::cout << "ù��° ���� : ";
			std::cin >> Num1;
			std::cout << "�ι�° ���� : ";
			std::cin >> Num2;
			std::cout << "����° ���� : ";
			std::cin >> Num3;
			BResult(Num1, Num2, Num3);
		}*/
		// c
		/*{
			int Num1, Num2 = 0;
			std::cout << "ù��° ���� :";
			std::cin >> Num1;
			std::cout << "�ι�° ���� :";
			std::cin >> Num2;

			printf("%d / %d = ? \n", Num1, Num2);
			printf("�� : %d , ������ : %d \n", Num1 / Num2, Num1 % Num2);
		}*/

	}

	// ���� 3.
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

	// ���� 4.
	{
		//int Num = 0, Result = 0;
		////do
		//{
		//	std::cout << "�Է� ����(-10 ~ 10) : ";
		//	std::cin >> Num;
		//	while (Num > -10 && Num < 10)
		//	{
		//		for (int Result = Num; Result >= -15; Result -= 5)
		//		{
		//			std::cout << Result << " ";
		//		}
		//		std::cout << '\n';
		//		std::cout << "�Է� ����(-10 ~ 10) : ";
		//		std::cin >> Num;
		//	}
		//}// while (Num > -10 && Num < 10);
	}

	// ���� 5. �����
	{
		// �پ���
		//****
		//***
		//**
		//*
		bool Value = true;
		/*while (Value)
		{
			int Num = 0;
			std::cout << "�Է� �ϰ� ���� ��(0 �Է½� ����) : ";
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

		// �þ��
		//*
		//**
		//***
		//****
		/*while (Value)
		{
			int Num = 0;
			std::cout << "�Է� �ϰ� ���� ��(0 �Է½� ����) : ";
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
		// ������ �پ���
		/*while (Value)
		{
			int Num = 0;
			std::cout << "�Է� �ϰ� ���� ��(0 �Է½� ����) : ";
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

		// �ؿ��� ���� �þ��
		//    *
		//   **
		//  ***
		// ****
		/*while (Value)
		{
			int Num = 0;
			std::cout << "�Է� �ϰ� ���� ��(0 �Է½� ����) : ";
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

		// ������ �׸���
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