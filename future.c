
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INF 1e6

int main() {
    int n, m, x, k;
    int d[105][105];

    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = (i == j) ? 0 : INF;
        }
    }
    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        d[a][b] = d[b][a] = 1;
    }
    scanf("%d %d", &x, &k);
    for (int last = 1; last <= n; last++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][last] + d[last][j] < d[i][j])
                    d[i][j] = d[i][last] + d[last][j];
            }
        }
    }
    int min = d[1][k] + d[k][x];
    printf("%d\n", (min >= INF) ? -1 : min);
    return 0;
}