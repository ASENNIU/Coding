#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v;
  double dist;
  Edge(int x, int y, double d) : u(x), v(y), dist(d) {}
  bool operator<(const Edge& other) { return dist < other.dist; }
};

class UnionFind {
 public:
  vector<int> parent, r;
  UnionFind(int n) {
    parent.resize(n);
    r.resize(n);

    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  bool unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      if (r[rootX] > r[rootY]) {
        parent[rootY] = parent[rootX];
      } else if (r[rootX] < r[rootY]) {
        parent[rootX] = parent[rootY];
      } else {
        parent[rootY] = parent[rootX];
        r[rootX]++;
      }
      return true;
    }
    return false;
  }
};

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> cities(n);

  for (int i = 0; i < n; ++i) {
    cin >> cities[i].first >> cities[i].second;
  }

  vector<Edge> edges;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double d = sqrt(pow(cities[i].first - cities[j].first, 2) +
                      pow(cities[i].second - cities[j].second, 2));
      edges.emplace_back(i, j, d);
    }
  }

  sort(edges.begin(), edges.end());

  UnionFind union_(n);

  double maxD = 0;
  int eCount = 0;
  for (const Edge& e : edges) {
    if (union_.unionSets(e.u, e.v)) {
      maxD = max(maxD, e.dist);
      eCount++;
      if (eCount == n - 1) {
        break;
      }
    }
  }

  int cost = static_cast<int>(ceil(maxD / 2.0));

  cout << cost << endl;
}
// 64 位输出请用 printf("%lld")