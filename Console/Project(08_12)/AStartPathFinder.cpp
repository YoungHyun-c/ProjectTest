#include "AStartPathFinder.h"

int2 AStartPathFinder::Astar(std::pair<int, int> _Start, std::pair<int, int> _End)
{
	bool Close[100][50] = { 0, }; // 폐쇄 리스트 (리스트&visit)
	Node S_Node;

	int cx[8] = { 0,1,0,-1,1,1,-1,-1 };
	int cy[8] = { -1,0,1,0,1,-1,1,-1 };

	S_Node.X = _Start.second;
	S_Node.Y = _Start.first;
	S_Node.G = 0;
	S_Node.H = (abs(_End.second - S_Node.X) + abs(_End.first - S_Node.Y)) * 10;
	S_Node.Parent = std::make_pair(-1, -1);
	OpenList.push(S_Node);
	Close[S_Node.Y][S_Node.X] = true;

	// std::vector<std::vector<int>> Result;// = map;
	while (OpenList.size())
	{
		int X = OpenList.top().X;
		int Y = OpenList.top().Y;
		int G = OpenList.top().G;

		CloseList.push_back(OpenList.top());
		int CheckY = Y;
		int CheckX = X;
		//Result[Y][X] = 8; // MonsterArr;
		OpenList.pop();

		if (X == _End.second && Y == _End.first) break;

		Node Add;
		for (int i = 0; i < 4; i++)
		{
			int NextX = X + cx[i];
			int NextY = Y + cy[i];
			if (NextX >= 0 && NextX < 100 && NextY >= 0 && NextY < 50)
			{
				if (Close[NextY][NextX] == false)
				{
					Add.X = NextX;
					Add.Y = NextY;
					Add.G = i < 4 ? G + 10 : G + 14;
					Add.H = (abs(_End.second - Add.X) + abs(_End.first - Add.Y)) * 10;
					Add.Parent = std::make_pair(Y, X);
					Close[NextY][NextX] = true;
					//Result[NextY][NextX] = 9; // 
					OpenList.push(Add);
					//print_map(Result);
				}
			}
		}

		X = OpenList.top().X;
		Y = OpenList.top().Y;
		G = OpenList.top().G;
		return { Y, X };
		//Result[Y][X] = 9; // PreveArr
	}
}



int AStartPathFinder::Astar(std::vector<std::vector<int>> map, std::pair<int, int> _Start, std::pair<int, int> _End)
{
	bool Close[10][10] = { 0, }; // 폐쇄 리스트 (리스트&visit)
	Node S_Node;

	int cx[8] = { 0,1,0,-1,1,1,-1,-1 };
	int cy[8] = { -1,0,1,0,1,-1,1,-1 };

	// 시작지점 초기화
	S_Node.X = _Start.second;
	S_Node.Y = _Start.first;
	S_Node.G = 0;
	S_Node.H = (abs(_End.second - S_Node.X) + abs(_End.first - S_Node.Y)) * 10;
	S_Node.Parent = std::make_pair(-1, -1);
	OpenList.push(S_Node);
	Close[S_Node.Y][S_Node.X] = true;

	std::vector<std::vector<int>> Result = map;
	while (OpenList.size())
	{
		int X = OpenList.top().X;
		int Y = OpenList.top().Y;
		int G = OpenList.top().G;

		CloseList.push_back(OpenList.top());
		Result[Y][X] = 8; // MonsterArr;
		OpenList.pop();

		if (X == _End.second && Y == _End.first) break;

		Node Add;
		for (int i = 0; i < 4; i++)
		{
			int NextX = X + cx[i];
			int NextY = Y + cy[i];
			if (NextX >= 0 && NextX < map.size() && NextY >= 0 && NextY < map.size())
			{
				if (map[NextY][NextX] != 1 && Close[NextY][NextX] == false)
				{
					Add.X = NextX;
					Add.Y = NextY;
					Add.G = i < 4 ? G + 10 : G + 14;
					Add.H = (abs(_End.second - Add.X) + abs(_End.first - Add.Y)) * 10;
					Add.Parent = std::make_pair(Y, X);
					Close[NextY][NextX] = true;
					Result[NextY][NextX] = 9; // 
					OpenList.push(Add);
					system("cls");
					print_map(Result);
				}
			}
		}
		int a = 0;
		//Result[Y][X] = 9; // PreveArr
	}

	//int Px = CloseList.back().X;
	//int Py = CloseList.back().Y;

	//while (CloseList.size())
	//{
	//	if (Px == CloseList.back().X && Py == CloseList.back().Y)
	//	{
	//		Result[Py][Px] = 4;
	//		Px = CloseList.back().Parent.second;
	//		Py = CloseList.back().Parent.first;
	//		// print_map
	//	}
	//	CloseList.pop_back();
	//}

	return 0;
}