#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10;
int maze[N][N];

int n, m, q, ans;
inline bool isvalid(int i, int j) {
  for (int ii = i-1; ii >= 0; --ii)
    if (maze[ii][j]) {
      for (int k = ii-1; k >= 0; --k) {
        if (maze[k][j]) {
          if (maze[k][j] == 2)
            return false;
          break;
        }
      }
      break;
    }

  for (int jj = j-1; jj >= 0; --jj) {
    if (maze[i][jj]) {
      for (int k = jj-1; k >= 0; --k) {
        if (maze[i][k]) {
          if (maze[i][k] == 2) {
            return false;
          }
          break;
        }
      }
      break;
    }
  }
  return true;
}

void dfs(int cnt, int x, int y) {
  if (x >= n) { 
    ans = max(ans, cnt);
    return;
  }
  if (y >= m) {
    dfs(cnt, x+1, 0);
    return;
  }
  if (maze[x][y]) {
    dfs(cnt, x, y+1);
    return;
  }

  dfs(cnt, x, y+1);
  if (!isvalid(x, y)) return ;
  maze[x][y] = 2;
  dfs(cnt+1, x, y+1);
  maze[x][y] = 0;
  return;
}

int main() {
  freopen("test.txt", "r", stdin);

  while (scanf("%d%d%d", &n, &m, &q) != EOF) {
    memset(maze, 0, sizeof(maze));
    int a, b;
    for (int i = 0; i < q; ++i) {
      scanf("%d%d", &a, &b);
      maze[a][b] = 1;
    }
    ans = 0;
    dfs(0, 0, 0);
    printf("%d\n", ans);
  }
  return 0;
} 
