#include <iostream>
#include <unordered_set>
#include <vector>


using namespace std;

int n, m, t;

class UF {
  vector<int> parent;

 public:
  UF(int n) {
    parent.resize(n);
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

  void combie(int x, int y) {
    int rootX = find(x), rootY = find(y);
    if (rootX != rootY) {
      parent[rootY] = rootX;
    }
  }

  bool isConnet(int x, int y) { return find(x) == find(y); }
};

int main() {
  std::cin >> n >> m >> t;
  UF uf(n + 1);
  std::vector<std::unordered_set<int>> direct(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    direct[a].insert(b);
    direct[a].insert(c);

    direct[b].insert(a);
    direct[b].insert(c);

    direct[c].insert(b);
    direct[c].insert(a);

    uf.combie(a, b);
    uf.combie(a, c);
    uf.combie(b, c);
  }

  for (int i = 0; i < t; ++i) {
    int u, v;
    std::cin >> u >> v;
    if (direct[u].count(v)) {
      std::cout << 1 << std::endl;
    } else if (uf.isConnet(u, v)) {
      std::cout << 2 << std::endl;
    } else {
      std::cout << 3 << std::endl;
    }
  }

  return 0;
}
// 64 位输出请用 printf("%lld")