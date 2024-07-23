#include <iostream>
#include <algorithm> // ����
#include <random> // �޸���

using namespace std;

int main()
{
	// �޸��� Ʈ������
	random_device rd;
	mt19937 gen(rd()); // �޸���Ʈ������ ���� ������ ����
	uniform_int_distribution<> dist(0, 9); // 0 ~ 9���� �յ��ϰ� ����. //�ߺ� ���Ű� �ƴ�.

	int Num;
	cin >> Num;

	int dest, sour, temp;

	int Number[10] = {};

	for (int i = 0; i < 10; i++)
	{
		Number[i] = i;
	}

	for (size_t i = 0; i < 10; i++)
	{
		cout << "number[" << i << "]�ε��� : " << Number[i] << endl;
	}

	// �����.
	for (size_t i = 0; i < 1000; i++)
	{
		dest = dist(gen);
		sour = dist(gen); // ��ǰ���� ���� ���� 

		temp = Number[dest];
		Number[dest] = Number[sour];
		Number[sour] = temp;
	}

	std::cout << "================================================" << endl;

	for (size_t i = 0; i < 10; i++)
	{
		cout << "number[" << i << "]�ε��� : " << Number[i] << endl;
	}
	
	// ������ ����.
	// 1. Player vs Computer
	/*
	1. C�� ������ ���� 3���� �̴´�.
	2. �÷��̾�� ���ʴ�� ���� 3���� �Է��Ѵ�.
	3. ex ) C = 5, 3 ,1 P = 1, 2, 3 => �ߺ� 1, 3  -> 2ball �ڸ��� �ٸ��� ���ڰ� �����ϸ� Ball
	4. ���� �ڸ��� ����, ���ڵ� �����ϸ� Strike
	5. ���� : ���� �߻� ���� (1 ~ 10), ���� ������ 1 ~ 10 �� �ٸ� �����Է½� �ٽ� �Է� ���� ���.
	6. �������� : 3out -> 3Strike �ѹ��� 1 out��


	*/
	

	return 0;
}