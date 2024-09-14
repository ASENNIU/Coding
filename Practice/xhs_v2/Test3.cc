#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
vector<pair<int, long long>> adj[MAXN];

int xor_value[MAXN];
unordered_map<int, int> xor_count;

int result[MAXN];

void dfs(int node, int parent, long long xor_acc) {
    xor_value[node] = xor_acc;
    xor_count[xor_acc]++;
    for (auto& e : adj[node]) {
        int next = e.first;
        long long  w = e.second;
        if (next != parent) {
            dfs(next, node, xor_acc ^ w);
        }
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    dfs(1, -1, 0);
    for (int i = 0; i < q; ++i) {
        int u;
        long long k;
        cin >> u >> k;
        long long target = xor_value[u] ^ k;
        cout << xor_count[target] << endl;
    }
    
    return 0;
    
}

