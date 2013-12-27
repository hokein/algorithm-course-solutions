#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 200;

bool maze[N][N];
int kinds[N][N];
int pre[N], post[N];
int n, m, k, times;

void dfs(int u) {
  pre[u] = times++;
  for (int i = 1; i <= n; ++i) {
    if (!maze[u][i]) continue;
    if (!pre[i]) {
      kinds[u][i] = 1; // tree edge
      dfs(i);
    } else if (!post[i]) {
      kinds[u][i] = 2; // back edge
    } else if (post[i] < pre[u]) {
      kinds[u][i] = 3; // cross edge
    } else {
      kinds[u][i] = 4; // 
    }
  }
  post[u] = times++;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    memset(maze, 0, sizeof(maze));
    memset(post, 0, sizeof(post));
    memset(pre, 0, sizeof(pre));
    times = 1;
    int u, v;
    for (int i = 0; i < m; ++i) {
       cin >> u >> v;
       maze[u][v] = 1;
    }

    dfs(1);

    cin >> k;
    for (int i = 0; i < k; ++i) {
      cin >> u >> v;
      switch(kinds[u][v]) {
        case 1:
          printf("edge (%d,%d) is Tree Edge\n", u, v);
          break;
        case 2:
          printf("edge (%d,%d) is Back Edge\n", u, v);
          break;
        case 3:
          printf("edge (%d,%d) is Cross Edge\n", u, v);
          break;
        case 4:
          printf("edge (%d,%d) is Down Edge\n", u, v);
          break;
      }
    }
  }
  return 0;
} 
