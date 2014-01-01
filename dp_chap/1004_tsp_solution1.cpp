// TSP变型
// first, use floyed calculate all shortest path.
// second, use dp
//
// dp[v][S]: minimum length that begin from v, visit all city not in set S and return to city 0
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMax = 11;
const int INF = 1000000000;

int maze[kMax][kMax], n;
int dp[kMax][1<<kMax];

int DP(int u, int S) {
  if (dp[u][S] != -1)
    return dp[u][S];

  if (u == 0 && S == (1<<n)-1)
    return dp[u][S] = 0;
  int mini = INF;
  for (int v = 0; v < n; ++v) {
    if (S&(1<<v)) continue;
    mini = min(mini, DP(v, S|(1<<v))+maze[u][v]);
  }
  return dp[u][S] = mini;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n && n) {
    ++n;
    int v;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        cin >> v; 
        maze[i][j] = v;
      }
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          maze[i][j] = min(maze[i][j], maze[i][k]+maze[k][j]);
    memset(dp, -1, sizeof(dp));
    cout << DP(0, 0) << endl;
  }
  return 0;
} 
