#include <iostream>
#include <list>
#include <map>

/*
���Ϳ� ����Ʈ�� �������� �ݵ�� �˾Ƶξ�� �Ѵ�.


����Ʈ
������ ���� ������ �ݺ��ڸ� �������� �ʴ´�.
-> ���� ���ٸ� �����ϴ�. -> ���Ϳ� ��������� ã�°� ������.
-> ���ͺ��� ��������� �޸� ��뷮�� ����. -> �����͵� ��ƾߵǸ�
-> �߰�������, ���� ���� ���� ����� ������ ����, ������ �ִ� ���� �������ִ� ��峢�� �����Ѵ�. insert

����Լ�
push_back : ����Ʈ ���� �߰�.
push_front : ����Ʈ �տ� �߰�
pop_back : ����Ʈ �� �������.
pop_front : ����Ʈ �� �������.
insert : ������ ��ġ�� ��� ����.
erase : ������ ��ġ�� ��� ����.
Clear : ��� ��� ����.
size : ����Ʈ ��� ���� ��ȯ.
front : ù ��° ��� ��ȯ
back : ������ ��� ��ȯ.
remove : ������ ���� ������ ��� ��� ����.
reverse : ����Ʈ ���� ������.
sort : ����.


���� �����̳�
Map�� ���� ���̰� �ȴ�.

Map
-> ���������̳� �߿� ���� ����ϴ� �����̳�.
-> Key, Value�� ������ ����(pair)
-> Key ���� �����̳ʿ� �ߺ����� ������ �� ����. -> ���� �ߺ����� �����ϰ� ������, Multimap�� ���� �ȴ�.
-> ���� ������ ���� �˻� Ʈ���� �Ǿ��ִ�. -> Red Black Tree
-> 





*/


int main()
{
	std::list<int> List = { 3, 1, 45, 7, 10 };

	List.push_back(9); // ����Ʈ ���� 9 �߰�,

	for (auto& i : List)
	{
		std::cout << i << std::endl;
	}

	List.push_front(6); // ����Ʈ �տ� 6 �߰�.

	std::list<int>::iterator Iter = List.begin();
	
	std::map<std::string, int> data;
	// �ݺ���.
	std::map<std::string, int>::iterator mIter = data.begin();
	
	
	// Pair
	// �ΰ��� ���� ��� �ϳ��� ��ü�� ����ϴ� ���ø� Ŭ����
	// �ΰ��� ���� �ٸ� Ÿ���� ���� �Բ� ���尡��
	// ���� �ΰ��� ����� ������ �ִ�.
	// first, second.
	std::pair<std::string, int> Pair;

	// 1. value_type�� �̿��� ���
	// �⺻���� Ű - ���� ������ Ÿ���� ��Ÿ����.
	// �ΰ��� ���� �ٸ� Ÿ���� ���� ������ �� �ִ�.
	// pair ��ü�� ������ ������ insert�� ����.
	// �������� ������.
	data.insert(std::map<std::string, int>::value_type("�ٺ�", 1));

	// 2. make_pair : pair��� ��ü�� �����ϴ� �Լ� ���ø�.
	// make_pair("����", 5) -> std::pair<string, list> �䷯�� ������ ��ü�� �������ش�. ���� ����.
	// ���ø� ���ڸ� �ڵ����� �߷���.
	data.insert(std::make_pair("����", 5));

	// 3. Pair�� �̿��� ���.
	data.insert(std::pair<std::string, int>("BTS", 10));
	data.insert(std::pair<std::string, int>("����", 30));
	data.insert(std::pair<std::string, int>("������", 170));
	data.insert(std::pair<std::string, int>("���켺", 400));
	data.insert(std::pair<std::string, int>("�𸮾�", 20));
	
	// 4. ��ü�� ���� �����ϴ� ���.
	std::pair<std::string, int> Pt1("���ѹα�", 10);
	data.insert(Pt1);

	data.erase("���켺");

	for (auto& pPair : data)
	{
		std::cout << "Ű �� : " << pPair.first << " ������ �� : " << pPair.second << std::endl;
	}
	
	std::map<std::string, int> m;
	m.insert(std::pair<std::string, int>("Apple", 1));
	m.insert(std::pair<std::string, int > ("Banana", 2));
	m.insert(std::make_pair("Grape", 3));

	auto Res = m.insert(std::make_pair("Banana", 10));

	if (!Res.second)
	{
		// ������ 2�� ������⿡ 10�� �ȸ��������.
		std::cout << "�ٳ����� ������? : " << Res.first->second << std::endl;
	}
	
	// find
	auto aiter = m.find("Apple");
	if (aiter != m.end())
	{
		std::cout << "ã��! " << aiter->second << std::endl;
	}
	else
	{
		std::cout << "����" << std::endl;
	}

	// Count -> �־��� Ű�� ������ ����. 0�̳� 1�� ����
	std::cout << "Apple : " << m.count("Apple") << std::endl;
	std::cout << "������ : " << m.size() << std::endl;

	// Clear : ��� ��Ҹ� ������.
	// empty : ����ֳ�?
	// size : �ʿ� ����� ��� ������ ����.
	for (auto it = m.begin(); it != m.end(); ++it)
	{

	}
	// ����
	for (auto it = m.rbegin(); it != m.rend(); ++it)
	{

	}

	return 0;
}