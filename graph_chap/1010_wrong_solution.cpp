#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 20005;

vector<int> maze[N];
int n, m, indegrees[N];

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    memset(indegrees, 0, sizeof(indegrees));
    for (int i = 1; i <= n; ++i) {
      maze[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      maze[a].push_back(b);
      ++indegrees[b];
    }
    vector<int> nodes;
    for (int i = 1; i <= n; ++i)
      if (indegrees[i] == 0) {
        nodes.push_back(i);
      }

    int base = 100;
    int ans = 0, cnt = 0;
    while (!nodes.empty()) {
      vector<int> new_nodes;
      ans += base*nodes.size();
      base++;
      for (int i = 0; i < nodes.size(); ++i) {
        ++cnt;
        int u = nodes[i];
        for (int j = 0; j < maze[u].size(); ++j) {
          int v = maze[u][j];
          --indegrees[v];
          if (indegrees[v] == 0)
            new_nodes.push_back(v);
        } 
      }
      nodes = new_nodes;
    }
    if (cnt != n) {
      cout << "Poor Xed" << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
} 

