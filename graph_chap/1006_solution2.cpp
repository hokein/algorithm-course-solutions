// Determine whether a directed graph is acyclic
// Solutions: Besides, use topologic sort.

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 200;

bool maze[N][N];
int n, m, indegrees[N];

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    int u, v;
    memset(maze, 0, sizeof(maze));
    memset(indegrees, 0, sizeof(indegrees));
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      maze[u][v] = 1;
      ++indegrees[v];
    }

    
    vector<int> nodes;
    for (int i = 1; i <= n; ++i)
      if (indegrees[i] == 0)
        nodes.push_back(i);

    int cnt = 0;
    while (!nodes.empty()) {
      int v = nodes.back();
      ++cnt;
      nodes.pop_back();
      for (int i = 1; i <= n; ++i)
        if (maze[v][i]) {
          --indegrees[i];
          if (indegrees[i] == 0)
            nodes.push_back(i);
        }
    }
    cout << (cnt==n?1:0) << endl;
  }
  return 0;
} 
