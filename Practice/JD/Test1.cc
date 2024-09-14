#include <climits>
#include <iostream>
using namespace std;

const int MAXN = 1000005;
int a[MAXN];
int n;
long long totalSum = 0, preSum = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    totalSum += a[i];
  }

  long long cost = LLONG_MAX, cur = 0;
  for (int i = 0; i < n - 1; ++i) {
    preSum += a[i];
    long long postSum = totalSum - preSum;
    cost = std::min(cost, postSum * preSum);
  }

  printf("%lld\n", cost);

  return 0;
}
// 64 位输出请用 printf("%lld")