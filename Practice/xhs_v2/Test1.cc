#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    unordered_map<int, int> mapping;
    long long count = 0;
    
    for (int i = 0; i < n; ++i) {
        int target = a[i] ^ k;
        if (mapping.find(target) != mapping.end()) {
            count += mapping[target];
        }
        mapping[a[i]]++;
    }
    
    cout << count << endl;
    
    return 0;
}