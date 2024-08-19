#include <windows.h>

#include <iostream>
#include <stdio.h>
#include <conio.h>

#include "PackManScreen.h"
#include "Utill.h"

#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"

#include "AStartPathFinder.h"


int main()
{
    system("mode con cols = 100 lines = 50 | title PackMan");
    // 프레임이 너무 느려 간단하게 바꾸기

    int2 ScreenSize = { 100, 50 };
    PackManScreen::GetMainScreen().SetScreenSize(ScreenSize);

    PackManScreen::GetMainScreen().Start();

    AStartPathFinder Test;
    int Size = 7;
    std::vector<std::vector<int>> map(Size, std::vector<int>(Size, 0));
    std::pair<int, int> Start, Gold;
    Start = { 5, 1 };
    Gold = { 1, 5 };
    map = { {0,0,0,0,0,0,0},
        {0,0,0,0,0,6,0},
        {0,0,0,0,0,0,0},
        {0,1,1,1,1,0,0},
        {0,0,0,0,0,0,0},
        {0,5,0,0,0,0,0},
        {0,0,0,0,0,0,0},
    };
    Test.print_map(map);
    Test.Astar(map, Start, Gold);

    {
        /*Monster Mon = Monster(12, 12);
        Mon.MonsterPrint();*/

        //Monster Mon = Monster(9, 9); // 파랑
        //Mon.MonsterPrint();

        //Monster Mon = Monster(13, 13); // 보라
        //Mon.MonsterPrint();

        //Monster Mon = Monster(14, 14); // 노랑
        //Mon.MonsterPrint();
    }

    // 만들었던 프레임 워크 이거로 안할꺼임
    {
        //int2 ScreenSize = { 100, 50 };
        //PackManScreen::GetMainScreen().SetScreenSize(ScreenSize);
        //PackManScreen::GetMainScreen().VoidCursor();

        //GameObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);
        //while (true)
        //{
        //    while (Player::IsGameUpdate)
        //    {
        //        GameObjectManager::ConsoleAllObjectUpdate();
        //        GameObjectManager::ConsoleAllObjectRender();
        //        //GameObjectManager::ConsoleAllObjectRelease();
        //    }
        //    if (Player::IsGameUpdate == false)
        //    {
        //        char Ch = _getch();
        //        if (Ch == 'p')
        //        {
        //            Player::IsGameUpdate = true;
        //        }
        //    }
        //}
        //GameObjectManager::ConsoleAllObjectDelete();
    }

    return 0;
}


// 바깥에서 시간
// clock_t start = clock();
 //void Player::PlayerPrint(clock_t _Start)
    //{*/
    //    /*clock_t current = clock() - _Start;
    //    int sec;
    //    sec = current / CLOCKS_PER_SEC;
    //    if (sec < 0.5)
    //    {
    //        DrawChar(PlayerPos.X, PlayerPos.Y , PlayerArr1);
    //    }
    //    if (1 < sec)
    //    {
    //        DrawChar(PlayerPos.X, PlayerPos.Y, PlayerArr2);
    //        sec = 0;
    //    }*/
    //}


//{
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//    using namespace std;
//
//    const int WIDTH = 10;
//    const int HEIGHT = 10;
//    const int WALL = 1;
//    const int EMPTY = 0;
//
//    struct Node {
//        int x, y;
//        int g; // Cost from start to current node
//        int h; // Heuristic cost from current node to goal
//        int f; // Total cost (g + h)
//        Node* parent;
//
//        Node(int x, int y, int g, int h, Node* parent)
//            : x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}
//
//        // Comparator for priority queue
//        bool operator>(const Node& other) const {
//            return f > other.f;
//        }
//    };
//
//    int map[WIDTH][HEIGHT] = {
//        {1, 0, 0, 0, 0, 1, 0, 1, 0, 0},
//        {0, 0, 1, 1, 0, 0, 1, 1, 0, 1},
//        {1, 0, 0, 1, 1, 0, 0, 0, 1, 0},
//        {0, 1, 0, 0, 0, 1, 1, 0, 0, 1},
//        {1, 1, 0, 1, 0, 0, 1, 0, 0, 0},
//        {0, 1, 1, 0, 1, 1, 0, 0, 1, 0},
//        {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
//        {1, 0, 1, 0, 0, 1, 0, 0, 0, 0},
//        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
//        {1, 0, 0, 1, 0, 1, 0, 0, 1, 0}
//    };
//
//    bool isInBounds(int x, int y) {
//        return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
//    }
//
//    bool isWalkable(int x, int y) {
//        return map[x][y] == EMPTY;
//    }
//
//    int heuristic(int x1, int y1, int x2, int y2) {
//        return abs(x1 - x2) + abs(y1 - y2);
//    }
//
//    vector<Node*> getNeighbors(Node* node, int goalX, int goalY) {
//        vector<Node*> neighbors;
//        int dx[] = { -1, 1, 0, 0 };
//        int dy[] = { 0, 0, -1, 1 };
//
//        for (int i = 0; i < 4; ++i) {
//            int newX = node->x + dx[i];
//            int newY = node->y + dy[i];
//
//            if (isInBounds(newX, newY) && isWalkable(newX, newY)) {
//                int g = node->g + 1;
//                int h = heuristic(newX, newY, goalX, goalY);
//                Node* neighbor = new Node(newX, newY, g, h, node);
//                neighbors.push_back(neighbor);
//            }
//        }
//
//        return neighbors;
//    }
//
//    void printPath(Node* node) {
//        if (node == nullptr) return;
//        printPath(node->parent);
//        cout << "(" << node->x << ", " << node->y << ") ";
//    }
//
//    void astar(int startX, int startY, int goalX, int goalY) {
//        priority_queue<Node*, vector<Node*>, greater<Node*>> openSet;
//        vector<vector<bool>> closedSet(WIDTH, vector<bool>(HEIGHT, false));
//
//        Node* startNode = new Node(startX, startY, 0, heuristic(startX, startY, goalX, goalY), nullptr);
//        openSet.push(startNode);
//
//        while (!openSet.empty()) {
//            Node* current = openSet.top();
//            openSet.pop();
//
//            if (current->x == goalX && current->y == goalY) {
//                cout << "Path found: ";
//                printPath(current);
//                cout << endl;
//                return;
//            }
//
//            closedSet[current->x][current->y] = true;
//
//            vector<Node*> neighbors = getNeighbors(current, goalX, goalY);
//            for (Node* neighbor : neighbors) {
//                if (closedSet[neighbor->x][neighbor->y]) {
//                    delete neighbor;
//                    continue;
//                }
//
//                openSet.push(neighbor);
//            }
//        }
//
//        cout << "No path found." << endl;
//    }
//
//    int main() {
//        int startX = 1, startY = 1; // Start position
//        int goalX = 8, goalY = 8;   // Goal position
//
//        cout << "Starting A* algorithm..." << endl;
//        astar(startX, startY, goalX, goalY);
//
//        return 0;
//    }
//
//}