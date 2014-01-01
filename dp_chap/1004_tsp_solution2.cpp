// TSP variation.
// first, use floyed calculate all shortest path.
// second, use dp
//
// dp[v][S]: minimum length that begin from v, visit all city in set S and return to city 0
//
// dp[0][0] = 0;
// dp[v][S] = min(maze[v][u]+dp[u][S-{u}])
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

    for (int s = 0; s < (1<<n); ++s)
      for (int i = 0; i < n; ++i)
        dp[i][s] = INF;
    dp[0][0] = 0;
    for (int s = 1; s < (1<<n); ++s) {
      for (int v = 0; v < n; ++v) {
        for (int u = 0; u < n; ++u) {
          if ((s>>u)&1)
            dp[v][s] = min(dp[v][s], dp[u][s-(1<<u)] + maze[v][u]);
        }
      }
    }
    cout << dp[0][(1<<n)-1] << endl;
  }
  return 0;
} 
