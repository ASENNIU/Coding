#include <stdio.h>
#include <vector>
#include <algorithm>

#define N 1000005

typedef std::pair<int, int> Region;

int main()
{
	int n, l, r;
	std::vector<Region> v;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &l, &r);
		v.emplace_back(std::make_pair(l, r));
	}
	std::sort(v.begin(), v.end(), [](Region a, Region b){
		return a.second < b.second;
	});
	int ans = 0, idx = 0, cur_time = -1;
	while(idx < n) {
		if (v[idx].first >= cur_time) {
			ans += 1;
			cur_time = v[idx].second;
		}
		++idx;
	}
	printf("%d", ans);
	return 0;
}