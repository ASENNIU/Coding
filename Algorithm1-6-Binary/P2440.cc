//
// Created by 13345 on 2023/9/21.
//

#include <stdio.h>

#define N 100005

typedef long long LL;

int a[N];

int main()
{
    int n, k;
    LL get;
    LL total_length = 0, max_length, min_length = 0, per_length;
    scanf("%d %d", &n, &k);
    for (size_t i = 0; i < n; ++i) {
        scanf("%d", a + i);
        total_length += a[i];
    }
    max_length = total_length / k + 1;

//    printf("max: %d\n", max_length);

    while (min_length + 1 < max_length) {
        get = 0;
        per_length = (max_length + min_length) / 2;
        for (size_t i = 0; i < n; ++i) {
            get += a[i] / per_length;
        }
        if (get >= k) {
            min_length = per_length;
        } else {
            max_length = per_length;
        }
//        printf("per_length: %d, get: %d\n", per_length, get);
    }

    printf("%d\n", min_length);
    return 0;
}