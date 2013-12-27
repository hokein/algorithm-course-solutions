// Determine whether a directed graph is acyclic
// Solutions: dfs to find whether there exits a back edge.

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 200;

bool maze[N][N];
int n, m, pre[N], post[N];
int times;
bool is_cycle;

void dfs(int u) {
  pre[u] = times++;
  for (int v = 1; v <= n; ++v) {
    if (!maze[u][v]) continue;
    if (!pre[v]) {
      dfs(v); // tree
    } else {
      if (!post[v])
        is_cycle = true;
    }
  }
  post[u] = times++;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    int u, v;
    times = 1;
    memset(maze, 0, sizeof(maze));
    memset(pre, 0, sizeof(pre));
    memset(post, 0, sizeof(post));
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      maze[u][v] = 1;
    }
    is_cycle = false;
    for (int i = 1; i <= n && !is_cycle; ++i) {
      if (!pre[i])
        dfs(i);
    }
    cout << (is_cycle?0:1) << endl;
  }
  return 0;
} 
