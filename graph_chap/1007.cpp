#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 200;

int maze[N][N], indegrees[N], n, m, max_level, max_width;
int widths[N];
int vis_cnt;
bool vis[N], is_valid;

void dfs(int u, int level) {
  vis[u] = true;
  ++vis_cnt;
  max_level = max(level, max_level);
  int cnt = 0;
  for (int v = 1; v <= n; ++v)
    if (maze[u][v]) {
      ++cnt;
      if (vis[v]) {
        is_valid = false;
        return;
      } else {
        dfs(v, level+1);
      }
    }
  widths[level] += cnt; // add width for every level.
  max_width = max(max_width, widths[level]);
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m && n) {
    memset(vis, 0, sizeof(vis));
    memset(maze, 0, sizeof(maze));     
    memset(indegrees, 0, sizeof(indegrees));
    memset(vis, 0, sizeof(vis));
    memset(widths, 0, sizeof(widths));
    is_valid = true;
    max_level = 0;
    max_width = 1;
    vis_cnt = 0;
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      maze[u][v] = 1;
      ++indegrees[v];
    }

    vector<int> nodes;
    for (int i = 1; i <= n; ++i)
      if (indegrees[i] == 0)
        nodes.push_back(i);
    max_width = nodes.size();
    for (int i = 0; i < nodes.size(); ++i)
      dfs(nodes[i], 0);
     
    if (is_valid && vis_cnt == n) {
      cout << max_level << " " << max_width << endl;
    } else {
      cout << "INVALID" << endl;
    }
  }
  return 0;
} 
