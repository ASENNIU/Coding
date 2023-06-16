#include <stdio.h>
#include <algorithm>

#define N 1005

typedef long long LL;
int wait[N];
int indexMap[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", wait + i);
		indexMap[i] = i;
	}
	std::sort(indexMap, indexMap + n, [](int idx1, int idx2) {
		return wait[idx1] < wait[idx2];
	});
	LL wait_total = 0;
	for (int i = 0;  i < n - 1; ++i) {
		wait_total += wait[indexMap[i]] * (n - 1 - i);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", indexMap[i] + 1);
	}
	printf("\n%.2f", wait_total * 1.0 / n);
}