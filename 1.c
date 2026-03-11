#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    int x = 1, y = 1;
    char direc;
    char direction[] = { 'L', 'R', 'U', 'D' };
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };

    if (scanf("%d", &n) != 1) return 0;
    while (scanf(" %c", &direc) == 1) {
        int nx = x, ny = y;
        for (int i = 0; i < 4; i++) {
            if (direc == direction[i]) {
                nx += dx[i];
                ny += dy[i];
                break;
            }
        }
        if (nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
            x = nx;
            y = ny;
        }

        if (getchar() == '\n') break;
    }
    printf("%d %d\n", x, y);
    return 0;
}