#include <stdio.h>
#include <algorithm>

#define N 105

int weight[N];
int value[N];
int indexMap[N];

int main()
{
	printf("process start..\n");
	int n, t;
	scanf("%d %d", &n, &t);
	for (size_t i = 0; i < n; i++) {
		scanf("%d %d", weight + i, value + i);
		indexMap[i] = i;
	}
	//printf("before..\n");
	// for (size_t i = 0;  i < n;  ++i) {
	// 	printf("%d %d %d\n", weight[i], value[i], indexMap[i]);
	// }
	std::sort(indexMap, indexMap + n, [](int idx1, int idx2){
		return  (float)value[idx2] / weight[idx2] < (float)value[idx1] / weight[idx1];
	});

	//printf("sorted\n");
	// for (size_t i = 0;  i < n;  ++i) {
	// 	printf("%d ", indexMap[i]);
	// }
	float result = 0;
	int idx = 0;
	while(t != 0 && idx < n) {
		int tmp = std::min(t, weight[indexMap[idx]]);
		result += ((float)value[indexMap[idx]] / weight[indexMap[idx]]) * tmp;
		t -= tmp;
		++idx;

	}
	printf("%.2f\n", result);
	return 0;
}