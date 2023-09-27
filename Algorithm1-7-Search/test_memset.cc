//
// Created by 13345 on 2023/9/27.
//

#include <cstdio>
#include <cstring>

#define N 10

int a[N][N];

int main()
{
    memset(a, 224, sizeof(int) * N * N);
    for (unsigned i = 0; i < 10; ++i) {
        for (unsigned j = 0; j < 10; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }


    int ans = 0, p = 1;
    for (int i = 0; i < 4; ++i) {
        ans ^= p << (i * 8);
    }
    unsigned char a = 257;
    printf("filled: %d", a);
    return 0;
}