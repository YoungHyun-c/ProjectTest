#pragma once

struct node
{
	int Value; // ������
	node* pNext; // ��带 ����Ű�� ������.

	node(int n) : Value(n), pNext(nullptr) {}
};

class SLL
{
private:
	node* phead; // ù��° ��带 ����Ű�� ������.

public:
	SLL();
	~SLL();

	void Insert(int num);
	void Delete(int num);
	void print();

};
