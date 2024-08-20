#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <conio.h>   // _kbhit(), _getch() ���
#include <chrono>    // �ð� ������ ���� ���
#include <thread>    // sleep_for �Լ� ���
#include <cstdlib>   // rand(), srand() ���
#include <ctime>     // time() ���
#include <Windows.h>

const int WIDTH = 100;   // ���� ������ �ʺ�
const int HEIGHT = 46;   // ���� ������ ����

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

// �÷��̾�� ������ �ʱ� ��ġ
Position initialPlayer = { WIDTH / 2 - 1, HEIGHT / 2 - 1 };
Position initialMonster = { 1, 1 };
Position player = initialPlayer;
Position monster = initialMonster;

// ������ ���
std::vector<Position> items;

// �ʿ� ��ֹ� �߰� (1�� ��ֹ�, 0�� �� ����)
int map[HEIGHT][WIDTH] = { 0 };

// �÷��̾�� ������ ũ�� (3x3)
const int ENTITY_SIZE = 3;

// �������� ũ�� (2x2)
const int ITEM_SIZE = 2;

// ����
int score = 0;

// A* �˰��򿡼� ����� ��� ����ü
struct Node {
    Position pos;
    int gCost;  // ���� ������ ���� �������� ���
    int hCost;  // ���� ������ ��ǥ �������� ���� ���
    Node* parent;

    int fCost() const {
        return gCost + hCost;
    }
};

// ��带 ���ϱ� ���� ������ �����ε� (�켱���� ť���� ���)
struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
        return a->fCost() > b->fCost();
    }
};

// ���� ���带 �׸��� �Լ�
void drawBoard() {
    Gotoxy(0, 0);

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            bool entityDrawn = false;

            // �÷��̾�� ���͸� 3x3 ũ��� �׸���
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

            // ������ �׸���
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
                        std::cout << '#';  // ��ֹ�
                    else
                        std::cout << '.';  // �� ����
                }
            }
        }
        std::cout << std::endl;
    }

    // ���� ǥ��
    std::cout << "Score: " << score << std::endl;
}

// A* �˰��򿡼� ����ϴ� �޸���ƽ �Լ� (����ư �Ÿ�)
int heuristic(const Position& a, const Position& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

// A* �˰������� ��θ� ã�� �Լ�
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

        // ��ǥ ������ ������ ��� ��θ� ������
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

    return {};  // ��θ� ã�� ���� ��� �� ���� ��ȯ
}

// ���͸� A* �˰������� ��ο� ���� �� ���� �̵���Ű�� �Լ�
void moveMonsterTowardsPlayer() {
    std::vector<Position> path = findPath(monster, player);
    if (path.size() > 1) {
        monster = path[path.size() - 2];  // ���� ��ġ�� �̵�
    }
}

// �÷��̾ �̵��ϴ� �Լ�
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

    // �� ��ġ�� ��ֹ��� ���� ��쿡�� �̵�
    if (map[newPlayerPosition.y][newPlayerPosition.x] != 1) {
        player = newPlayerPosition;
    }
}

// �� ��ġ ���� �Ÿ��� ����ϴ� �Լ�
double distance(const Position& pos1, const Position& pos2) {
    return std::sqrt(std::pow(pos2.x - pos1.x, 2) + std::pow(pos2.y - pos1.y, 2));
}

// �ʿ� �������� �������� �����ϴ� �Լ�
void generateItems(int itemCount) {
    srand(time(0));  // ���� �õ� ����

    for (int i = 0; i < itemCount; ++i) {
        Position item;
        do {
            item.x = rand() % (WIDTH - ITEM_SIZE);
            item.y = rand() % (HEIGHT - ITEM_SIZE);
        } while (map[item.y][item.x] == 1);  // ��ֹ� ��ġ�� ���ؼ� ����
        items.push_back(item);
    }
}

// �ʿ� �������� ��ֹ��� �����ϴ� �Լ�
void generateObstacles(int obstacleCount) {
    srand(time(0));  // ���� �õ� ����

    for (int i = 0; i < obstacleCount; ++i) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        map[y][x] = 1;
    }
}

// �÷��̾ �������� �Դ��� Ȯ���ϴ� �Լ�
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

// ���Ϳ� �÷��̾ �浹�ߴ��� Ȯ���ϴ� �Լ�
bool checkCollision() {
    for (int dy = 0; dy < ENTITY_SIZE; ++dy) {
        for (int dx = 0; dx < ENTITY_SIZE; ++dx) {
            if (monster.x + dx >= player.x && monster.x + dx < player.x + ENTITY_SIZE &&
                monster.y + dy >= player.y && monster.y + dy < player.y + ENTITY_SIZE) {
                return true;  // �浹 �߻�
            }
        }
    }
    return false;
}

int main() {
    generateObstacles(150);  // �ʿ� 150���� ��ֹ� ����
    generateItems(30);  // �ʿ� 10���� ������ ����

    auto lastMonsterMoveTime = std::chrono::steady_clock::now();  // ���������� ���Ͱ� �̵��� �ð��� ���
    const std::chrono::milliseconds moveInterval(100);  // ���Ͱ� �̵��� �ð� ���� (1��)

    while (true) {
        drawBoard();

        // ���Ϳ� �÷��̾��� �浹 Ȯ��
        if (checkCollision()) {
            std::cout << "The monster has caught you! Resetting positions..." << std::endl;
            // ���Ϳ� �÷��̾ �ʱ� ��ġ�� �ǵ�����
            player = initialPlayer;
            monster = initialMonster;
            std::this_thread::sleep_for(std::chrono::seconds(1));  // 1�� ��� �� ��ġ �ʱ�ȭ
        }

        // ���� �ð� ���
        auto currentTime = std::chrono::steady_clock::now();

        // ���͸� 1�ʸ��� �� ĭ�� �̵���Ŵ
        if (currentTime - lastMonsterMoveTime >= moveInterval) {
            moveMonsterTowardsPlayer();
            lastMonsterMoveTime = currentTime;  // ������ �̵� �ð� ������Ʈ
        }

        // �÷��̾��� �Է��� ��ٸ�
        if (_kbhit()) {
            char input = _getch();
            movePlayer(input);
            checkItemCollision();  // ������ �Ա� Ȯ��
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));  // CPU ����� ���̱� ���� �ణ�� ������ �߰�
    }

    return 0;
}
