#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

typedef struct {
    int x, y;
} Node;

int n, m;
int maze[201][201];
Node queue[40001];
int head = 0;
int tail = 0;

void push(int x, int y) {
    queue[tail].x = x;
    queue[tail].y = y;
    tail++;
}

Node pop() {
    return queue[head++];
}

int is_empty() {
    return head == tail;
}

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
    maze[0][0] = 1;
    push(0, 0);
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
  

    while (!is_empty()) {
        Node cur = pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maze[nx][ny] == 0) continue;

            if (maze[nx][ny] == 1) {
                if (nx == 0 && ny == 0) continue;

                maze[nx][ny] = maze[cur.x][cur.y] + 1;
                push(nx, ny);
            }
        }
    }

    printf("%d\n", maze[n - 1][m - 1]);
    return 0;
}