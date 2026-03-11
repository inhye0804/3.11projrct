#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    unsigned long long fib[91];

    if (scanf("%d", &n) != 1) return 0;

    if (n < 1 || n > 90) return 0;

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 1; i <= n; i++) {
        printf("%llu", fib[i]);

        if (i < n) {
            printf(", ");
        }
    }
    printf("\n"); 

    return 0;
}