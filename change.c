
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int a[1000000], b[1000000];

int up(const void* first, const void* second) {
    return *(int*)first - *(int*)second;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    qsort(a, n, sizeof(int), up);
    qsort(b, n, sizeof(int), up);

    for (int i = 0; i < k; i++) {
        if (a[i] < b[n - 1 - i]) {
            int temp = a[i];
            a[i] = b[n - 1 - i];
            b[n - 1 - i] = temp;
        }
        else break;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];

    printf("%lld\n", sum);
    return 0;
}