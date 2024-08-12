#include "SLL.h"
#include <iostream>

SLL::SLL() : phead(nullptr) {}

SLL::~SLL()
{
	// ��尡 nullptr�� �ƴҶ����� ������.
	while (phead != nullptr)
	{
		// ���� ��带 ����Ű�� �����͸� �ӽó�忡 ����
		node* temp = phead;
		phead = phead->pNext;
		delete temp;
	}
}

void SLL::Insert(int num)
{
	// ���ο� ��带 �����.
	node* newNode = new node(num);

	// ��尡 ������ �翬�� ���� ���־�� �Ѵ�.
	if (phead == nullptr)
	{
		// ���ο� ��带 ���� ����.
		phead = newNode;
		return;
	}
	else
	{
		node* temp = phead;
		// ��ȸ�� �����Ͱ� nullptr�� �ƴҶ����� ���鼭.
		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = newNode;
	}
}

void SLL::Delete(int num)
{
	// ���� ��带 ����Ű�� �����Ϳ�, ���� ��带 ����Ű�� �����͸� �˾ƾ� �ȴ�.
	node* pCurrent = phead;
	// ���� ��带 ����Ű�� ������.
	node* pNext = phead->pNext;
	// ���� ù��° ��尡 �����Ϸ��� �����,
	if (pCurrent->Value == num)
	{
		phead = pNext; // phead�� ���� ���� �̵�.
		delete pCurrent;
		return;
	}
	while (pNext->Value != num)
	{
		// ���� ��带 �� ���� ����.
		pCurrent = pCurrent->pNext;
		// ���� ��带 �� ���� ���� �̵�.
		pNext = pNext->pNext;
		if (pNext == nullptr)
		{
			return;
		}
	}
	pCurrent->pNext = pNext->pNext;
	delete pNext;
}

void SLL::print()
{
	node* temp = phead;
	std::cout << "=================Print=====================" << std::endl;
	while (temp->pNext != nullptr)
	{
		std::cout << temp->Value << " ";
		temp = temp->pNext;
	}
	std::cout << std::endl;
}