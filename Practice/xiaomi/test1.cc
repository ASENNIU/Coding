#include <bits/stdc++.h>
#include <string.h>

const int MAXN = 1010;
int t, cap, n, c;
// int a[MAXN];
// bool dp[MAXN];
bool solve(std::vector<int>& a) {
    std::vector<bool> dp(cap + 1, 0);
    // memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = cap; j >= a[i]; --j) {
            dp[j] = dp[j] || dp[j - a[i]];
        }
    }
    
    for (int i = 0; i <= cap; ++i) {
        if (dp[i] && i + c >= cap) {
            dp[cap] = true;
        }
    }
    return dp[cap];
}

int main() 
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &cap, &n, &c);
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        bool flag = solve(a);
        if (flag) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
        
    }
    return 0;
}

