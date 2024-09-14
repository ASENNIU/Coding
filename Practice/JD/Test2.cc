#include <bits/stdc++.h>

using namespace std;

bool cmp(const string& s1, const string& s2, const map<char, int>& rank) {
  int len = min(s1.length(), s2.length());
  for (int i = 0; i < len; ++i) {
    if (s1[i] != s2[i]) {
      return rank.at(s1[i]) < rank.at(s2[i]);
    }
  }

  return s1.length() < s2.length();
}

int main() {
  string order;
  cin >> order;
  map<char, int> rank;
  for (int i = 0; i < 26; ++i) {
    rank[order[i]] = i;
  }

  int n;
  cin >> n;
  vector<string> strings(n);

  for (int i = 0; i < n; ++i) {
    cin >> strings[i];
  }

  sort(strings.begin(), strings.end(),
       [&rank](const string& s1, const string& s2) {
         return cmp(s1, s2, rank);
       });

  for (int i = 0; i < n; ++i) {
    cout << strings[i] << endl;
  }

  return 0;
}
// 64 位输出请用 printf("%lld")