#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <conio.h>   // _kbhit(), _getch() 사용
#include <chrono>    // 시간 측정을 위해 사용
#include <thread>    // sleep_for 함수 사용
#include <cstdlib>   // rand(), srand() 사용
#include <ctime>     // time() 사용
#include <Windows.h>

const int WIDTH = 100;   // 게임 보드의 너비
const int HEIGHT = 46;   // 게임 보드의 높이

void Gotoxy(short _X, short _Y)
{
    COORD Pos = { _X, _Y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


struct Position {
    int x;
    int y;

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Position& other) const {
        return !(*this == other);
    }
};

// 플레이어와 몬스터의 초기 위치
Position initialPlayer = { WIDTH / 2 - 1, HEIGHT / 2 - 1 };
Position initialMonster = { 1, 1 };
Position player = initialPlayer;
Position monster = initialMonster;

// 아이템 목록
std::vector<Position> items;

// 맵에 장애물 추가 (1은 장애물, 0은 빈 공간)
int map[HEIGHT][WIDTH] = { 0 };

// 플레이어와 몬스터의 크기 (3x3)
const int ENTITY_SIZE = 3;

// 아이템의 크기 (2x2)
const int ITEM_SIZE = 2;

// 점수
int score = 0;

// A* 알고리즘에서 사용할 노드 구조체
struct Node {
    Position pos;
    int gCost;  // 시작 노드부터 현재 노드까지의 비용
    int hCost;  // 현재 노드부터 목표 노드까지의 예상 비용
    Node* parent;

    int fCost() const {
        return gCost + hCost;
    }
};

// 노드를 비교하기 위한 연산자 오버로딩 (우선순위 큐에서 사용)
struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
        return a->fCost() > b->fCost();
    }
};

// 게임 보드를 그리는 함수
void drawBoard() {
    Gotoxy(0, 0);

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            bool entityDrawn = false;

            // 플레이어와 몬스터를 3x3 크기로 그리기
            for (int dy = 0; dy < ENTITY_SIZE; ++dy) {
                for (int dx = 0; dx < ENTITY_SIZE; ++dx) {
                    if (x == player.x + dx && y == player.y + dy) {
                        std::cout << 'P';
                        entityDrawn = true;
                        break;
                    }
                    else if (x == monster.x + dx && y == monster.y + dy) {
                        std::cout << 'M';
                        entityDrawn = true;
                        break;
                    }
                }
                if (entityDrawn) break;
            }

            // 아이템 그리기
            if (!entityDrawn) {
                bool itemDrawn = false;
                for (const Position& item : items) {
                    for (int dy = 0; dy < ITEM_SIZE; ++dy) {
                        for (int dx = 0; dx < ITEM_SIZE; ++dx) {
                            if (x == item.x + dx && y == item.y + dy) {
                                std::cout << '*';
                                itemDrawn = true;
                                break;
                            }
                        }
                        if (itemDrawn) break;
                    }
                }
                if (!itemDrawn) {
                    if (map[y][x] == 1)
                        std::cout << '#';  // 장애물
                    else
                        std::cout << '.';  // 빈 공간
                }
            }
        }
        std::cout << std::endl;
    }

    // 점수 표시
    std::cout << "Score: " << score << std::endl;
}

// A* 알고리즘에서 사용하는 휴리스틱 함수 (맨해튼 거리)
int heuristic(const Position& a, const Position& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

// A* 알고리즘으로 경로를 찾는 함수
std::vector<Position> findPath(const Position& start, const Position& target) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> openSet;
    std::vector<Node*> allNodes;

    Node* startNode = new Node{ start, 0, heuristic(start, target), nullptr };
    openSet.push(startNode);
    allNodes.push_back(startNode);

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        // 목표 지점에 도달한 경우 경로를 역추적
        if (current->pos == target) {
            std::vector<Position> path;
            while (current != nullptr) {
                path.push_back(current->pos);
                current = current->parent;
            }
            for (Node* node : allNodes) {
                delete node;
            }
            return path;
        }

        for (int i = 0; i < 4; ++i) {
            Position neighborPos = { current->pos.x + dx[i], current->pos.y + dy[i] };
            if (neighborPos.x >= 0 && neighborPos.x < WIDTH && neighborPos.y >= 0 && neighborPos.y < HEIGHT && map[neighborPos.y][neighborPos.x] == 0) {
                int gCost = current->gCost + 1;
                Node* neighbor = new Node{ neighborPos, gCost, heuristic(neighborPos, target), current };
                openSet.push(neighbor);
                allNodes.push_back(neighbor);
            }
        }
    }

    for (Node* node : allNodes) {
        delete node;
    }

    return {};  // 경로를 찾지 못한 경우 빈 벡터 반환
}

// 몬스터를 A* 알고리즘으로 경로에 따라 한 걸음 이동시키는 함수
void moveMonsterTowardsPlayer() {
    std::vector<Position> path = findPath(monster, player);
    if (path.size() > 1) {
        monster = path[path.size() - 2];  // 다음 위치로 이동
    }
}

// 플레이어가 이동하는 함수
void movePlayer(char input) {
    Position newPlayerPosition = player;

    switch (input) {
    case 'w':
        if (player.y > 0) newPlayerPosition.y--;
        break;
    case 's':
        if (player.y < HEIGHT - 1) newPlayerPosition.y++;
        break;
    case 'a':
        if (player.x > 0) newPlayerPosition.x--;
        break;
    case 'd':
        if (player.x < WIDTH - 1) newPlayerPosition.x++;
        break;
    }

    // 새 위치에 장애물이 없는 경우에만 이동
    if (map[newPlayerPosition.y][newPlayerPosition.x] != 1) {
        player = newPlayerPosition;
    }
}

// 두 위치 간의 거리를 계산하는 함수
double distance(const Position& pos1, const Position& pos2) {
    return std::sqrt(std::pow(pos2.x - pos1.x, 2) + std::pow(pos2.y - pos1.y, 2));
}

// 맵에 랜덤으로 아이템을 생성하는 함수
void generateItems(int itemCount) {
    srand(time(0));  // 난수 시드 설정

    for (int i = 0; i < itemCount; ++i) {
        Position item;
        do {
            item.x = rand() % (WIDTH - ITEM_SIZE);
            item.y = rand() % (HEIGHT - ITEM_SIZE);
        } while (map[item.y][item.x] == 1);  // 장애물 위치는 피해서 생성
        items.push_back(item);
    }
}

// 맵에 랜덤으로 장애물을 생성하는 함수
void generateObstacles(int obstacleCount) {
    srand(time(0));  // 난수 시드 설정

    for (int i = 0; i < obstacleCount; ++i) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        map[y][x] = 1;
    }
}

// 플레이어가 아이템을 먹는지 확인하는 함수
void checkItemCollision() {
    for (auto it = items.begin(); it != items.end(); ) {
        bool itemEaten = false;
        for (int dy = 0; dy < ENTITY_SIZE; ++dy) {
            for (int dx = 0; dx < ENTITY_SIZE; ++dx) {
                if (player.x + dx >= it->x && player.x + dx < it->x + ITEM_SIZE &&
                    player.y + dy >= it->y && player.y + dy < it->y + ITEM_SIZE) {
                    itemEaten = true;
                    break;
                }
            }
            if (itemEaten) break;
        }
        if (itemEaten) {
            score += 10;
            it = items.erase(it);
        }
        else {
            ++it;
        }
    }
}

// 몬스터와 플레이어가 충돌했는지 확인하는 함수
bool checkCollision() {
    for (int dy = 0; dy < ENTITY_SIZE; ++dy) {
        for (int dx = 0; dx < ENTITY_SIZE; ++dx) {
            if (monster.x + dx >= player.x && monster.x + dx < player.x + ENTITY_SIZE &&
                monster.y + dy >= player.y && monster.y + dy < player.y + ENTITY_SIZE) {
                return true;  // 충돌 발생
            }
        }
    }
    return false;
}

int main() {
    generateObstacles(150);  // 맵에 150개의 장애물 생성
    generateItems(30);  // 맵에 10개의 아이템 생성

    auto lastMonsterMoveTime = std::chrono::steady_clock::now();  // 마지막으로 몬스터가 이동한 시간을 기록
    const std::chrono::milliseconds moveInterval(100);  // 몬스터가 이동할 시간 간격 (1초)

    while (true) {
        drawBoard();

        // 몬스터와 플레이어의 충돌 확인
        if (checkCollision()) {
            std::cout << "The monster has caught you! Resetting positions..." << std::endl;
            // 몬스터와 플레이어를 초기 위치로 되돌리기
            player = initialPlayer;
            monster = initialMonster;
            std::this_thread::sleep_for(std::chrono::seconds(1));  // 1초 대기 후 위치 초기화
        }

        // 현재 시간 계산
        auto currentTime = std::chrono::steady_clock::now();

        // 몬스터를 1초마다 한 칸씩 이동시킴
        if (currentTime - lastMonsterMoveTime >= moveInterval) {
            moveMonsterTowardsPlayer();
            lastMonsterMoveTime = currentTime;  // 마지막 이동 시간 업데이트
        }

        // 플레이어의 입력을 기다림
        if (_kbhit()) {
            char input = _getch();
            movePlayer(input);
            checkItemCollision();  // 아이템 먹기 확인
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));  // CPU 사용을 줄이기 위해 약간의 딜레이 추가
    }

    return 0;
}
