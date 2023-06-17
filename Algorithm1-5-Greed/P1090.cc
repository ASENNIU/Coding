#include <stdio.h>
#include <queue>
#include <vector>


#define N 10005

//int a[N];

int main()
{
	int n, tmp; 
	std::priority_queue<int, std::vector<int>, std::greater<int>> minq;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		minq.push(tmp);
	}
	int ans = 0, a, b;
	while(!minq.empty() && minq.size() >= 2) {
		a = minq.top(); 
		minq.pop();
		b = minq.top();
		minq.pop();
		ans += a + b;
		minq.push(a + b);
	}
	printf("%d\n", ans);
	return 0;
}