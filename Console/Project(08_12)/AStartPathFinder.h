#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include "ConsoleGameMath.h"


struct Node
{
	int X, Y;
	int G, H;
	std::pair<int, int> Parent; // 역추적에 쓰일 노드.
};

// 우선순위 큐 비교 함수
struct cmp
{
	bool operator()(const Node U, const Node V)
	{
		if (U.G + U.H > V.G + V.H)
		{
			return true;
		}
		else if (U.G + U.H == V.G + V.H) // F 가 같다면 G가 큰게 위로 오게.
		{
			if (U.G < V.G)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};

class AStartPathFinder
{
public:
	int Astar(std::vector<std::vector<int>> map, std::pair<int, int> _Start, std::pair<int, int> _End);

	int2 Astar(std::pair<int, int> _Start, std::pair<int, int> _End);

	void print_map(std::vector<std::vector<int>> map) { // 맵 출력 함수
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map.size(); j++) std::cout << map[i][j] << " ";
			std::cout << '\n';
		}
	}

protected:
	std::priority_queue<Node, std::vector<Node>, cmp> OpenList;
	std::vector<Node>CloseList;
};
