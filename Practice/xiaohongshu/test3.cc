#include <bits/stdc++.h>

typedef long long ll;

ll a[1000010];

int n;

int f(ll x) {
   return std::bitset<64>(x).count();
}

bool cmp(ll a, ll b) {
    if (f(a) != f(b)) {
        return f(a) < f(b);
    }
    return a < b;
}

ll fnext(ll a) {
    if (a == 0) {
        return 0;
    }

    ll base = 1;
    while ((base & a) == 0) {
        base <<= 1; 
    }

    while ((base & a) == a) {
        base <<= 1;
    }
    a += base >> 1;
    ll res = a % base;
    a -= res;
    while (res > 0 && res & 1 == 0) {
        res >>= 1;
    }

    return a + res;
}

int solve() {
   
    if (n == 0) {
        return 0;
    }
    int maxLength = 1, curLength = 1;
    std::sort(a, a + n, cmp);
    for (int i = 1;  i < n; ++i) {
        if (a[i] == fnext(a[i-1])) {
            ++curLength;
        } else if (a[i] == a[i-1]) {
            continue;
        } else {
            maxLength = std::max(maxLength, curLength);
            curLength = 1;
        }
    }
    return maxLength;
}

int main()
{
  
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }

    int max_length = solve();
    printf("%d\n", max_length);

    return 0;
}