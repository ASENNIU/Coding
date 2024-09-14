#include <bits/stdc++.h>

int x, y, z, k;

int w(int a, int b, int c) {
  if (a > x || b > y || c > z) {
    return 0;
  }
  return (x - a + 1) * (y - b + 1) * (z - c + 1);
}

int main()
{
  int t;
  std::cin >> t;
  while (t--) {
    std::cin >> x >> y >> z >> k;
    if (x > y) std::swap(x, y);
    if (y > z) std::swap(y, z);
    if (x > y) std::swap(x, y);

    long long ans = 0;
    for (int i = 1; i <= x; ++i) {
      for (int j = i; j <= y; ++j) {
        int h = k / (i * j);
        if (h < j) break;
        if (i * j * h != k) continue;

        int s = std::max(w(h, i ,j), w(h, j, i));
        int ss = std::max(w(i, j, h), w(j, i, h));
        int sss = std::max(w(h, j, i), w(j, h, i));

        ans += std::max(s, std::max(ss, sss));
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}


