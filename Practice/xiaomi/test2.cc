#include <bits/stdc++.h>

int t, n;
const int MAXN = 10005;
int a[MAXN];
int b[MAXN];
int tmp[MAXN];

bool solve1() {
    a[0] = b[0] = tmp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int cur_min = std::min(a[i], b[i]);
        int cur_max  = std::max(a[i], b[i]);
        if (cur_max < tmp[i-1]) {
            return false;
        }
        if (cur_min >= tmp[i-1]) {
             tmp[i] = cur_min;
        } else {
             tmp[i] = cur_max;
        }
        
    }
    return true;
}
bool solve2() {
    a[0] = b[0] =  tmp[0] = 1e9;
    for (int i = 1; i <= n; ++i) {
        int cur_min = std::min(a[i], b[i]);
        int cur_max  = std::max(a[i], b[i]);
        if (cur_min > tmp[i-1]) {
            return false;
        }
        if (cur_max <= tmp[i-1]) {
            tmp[i] = cur_max;
        } else {
            tmp[i] = cur_min;
        }
        
    }
    return true;
}

int main()
{
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
        }
        if (solve1() || solve2()) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
         }
    }
}