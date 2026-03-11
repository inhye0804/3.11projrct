
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[1000000]; 

int main() {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    int high = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > high) high = a[i]; 
    }
    int low = 0, final = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > mid) sum += a[i] - mid;
        }

        if (sum >= m) { 
            final = mid;
            low = mid + 1;
        }
        else {      
            high = mid - 1;
        }
    }

    printf("%d\n", final);
    return 0;
}