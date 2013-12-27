#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1005;

bool maze[N][N], vis[N];
int color[N];
int n, m;

bool dfs(int u) {
  vis[u] = true;
  for (int v = 0; v < n; ++v) {
    if (maze[u][v]) {
      if (vis[v]) {
        if (color[u] == color[v]) return false;
      } else {
        color[v] = !color[u];
        if (!dfs(v))
          return false;
      }
    }
  }
  return true;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    memset(maze, 0, sizeof(maze));
    memset(color, 0, sizeof(color));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      maze[u][v] = maze[v][u] = 1;
    }

    color[1] = 1;
    if (dfs(1))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
} 
