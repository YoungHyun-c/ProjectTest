#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include "ConsoleGameMath.h"


struct Node
{
	int Fcost() const
	{
		return G + H;
	}

	int2 Pos;
	int G, H;
	Node* NParent;

	bool operator<(const Node& other) const {
		return Fcost() > other.Fcost();  // ���� ���� �켱������ �������� ����
	}

	//std::pair<int, int> Parent; // �������� ���� ���.
};

// �켱���� ť �� �Լ�
struct cmp
{
	//bool operator()(const Node U, const Node V)
	//{
	//	if (U.G + U.H > V.G + V.H)
	//	{
	//		return true;
	//	}
	//	else if (U.G + U.H == V.G + V.H) // F �� ���ٸ� G�� ū�� ���� ����.
	//	{
	//		if (U.G < V.G)
	//		{
	//			return true;
	//		}
	//		else
	//		{
	//			return false;
	//		}
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}

	bool operator()(const Node* _A, const Node* _B) const
	{
		return _A->Fcost() > _B->Fcost();
	}
};

class AStartPathFinder
{
public:
	//int Astar(std::vector<std::vector<int>> map, std::pair<int, int> _Start, std::pair<int, int> _End);

	//int2 Astar(char _Map[50][101], std::pair<int, int> _Start, std::pair<int, int> _End);

	//void print_map(std::vector<std::vector<int>> map) { // �� ��� �Լ�
	//	for (int i = 0; i < map.size(); i++) {
	//		for (int j = 0; j < map.size(); j++) std::cout << map[i][j] << " ";
	//		std::cout << '\n';
	//	}
	//}

	int Heuristic(const int2& A, const int2& B)
	{
		return abs(A.X - B.X) + abs(A.Y - B.Y);
	}

	std::vector<int2> FindPath(const int2& _Start, const int2& _Target);

protected:
	std::priority_queue<Node, std::vector<Node>, cmp> OpenList;
	std::vector<Node>CloseList;
};
