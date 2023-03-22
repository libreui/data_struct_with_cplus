#include <iostream>
#include <stack>

using namespace std;

const int N = 10;  // 迷宫的大小

int maze[N][N] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
};  // 迷宫地图

struct Point {
    int x;
    int y;
    Point(int i, int j) : x(i), y(j) {}
};

int main() {
    stack<Point> s;
    bool visited[N][N] = {false};  // 标记是否访问过

    s.push(Point(1, 1));  // 入口

    while (!s.empty()) {
        Point p = s.top();
        s.pop();

        int x = p.x;
        int y = p.y;

        if (x == N - 2 && y == N - 2) {  // 到达出口
            cout << "Path Found!" << endl;
            break;
        }

        if (visited[x][y]) continue;  // 已访问过

        visited[x][y] = true;

        // 上下左右四个方向
        if (maze[x - 1][y] == 1) s.push(Point(x - 1, y));
        if (maze[x + 1][y] == 1) s.push(Point(x + 1, y));
        if (maze[x][y - 1] == 1) s.push(Point(x, y - 1));
        if (maze[x][y + 1] == 1) s.push(Point(x, y + 1));
    }

    return 0;
}
