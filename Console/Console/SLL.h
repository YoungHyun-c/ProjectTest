#pragma once

struct node
{
	int Value; // 데이터
	node* pNext; // 노드를 가리키는 포인터.

	node(int n) : Value(n), pNext(nullptr) {}
};

class SLL
{
private:
	node* phead; // 첫번째 노드를 가리키는 포인터.

public:
	SLL();
	~SLL();

	void Insert(int num);
	void Delete(int num);
	void print();

};
