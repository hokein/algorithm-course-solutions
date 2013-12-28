// Tree dp:
//
// dp[u][k][0]: root u tree remains k steps maximum value, will return.
// dp[u][k][1]: root u tree remians k steps maximum value, not return.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;
const int K = 1000;
vector<int> maze[N];
int n, k, num[N];
int dp[N][K][2];

void dfs(int u, int fa, int used_steps) {
  if (used_steps > k)
    return;
  for (int i = 0; i < maze[u].size(); ++i) {
    int v = maze[u][i];
    if (v != fa) {
      dfs(v, u, used_steps+1);
      for (int kk = k-used_steps; kk >= 0; --kk) { // enum remain steps.
        int max0, max1;
        max0 = max1 = num[u];
        for (int j = kk; j >= 1; --j) { // enum steps for subtree v.
          if (j >= 2) {
            max0 = max(max0, dp[u][kk-j][0]+dp[v][j-2][0]); // subtree u returns;
            max1 = max(max1, dp[u][kk-j][1]+dp[v][j-2][0]); // subtree u not return, subtree v returns;
          }
          if (j >= 1)
            max1 = max(max1, dp[u][kk-j][0]+dp[v][j-1][1]); // subtree u not return, subtree v not return;
        }
        dp[u][kk][0] = max(dp[u][kk][0], max0);
        dp[u][kk][1] = max(dp[u][kk][1], max1);
      }
    }
  }
}


int main() {
  //freopen("test.txt", "r", stdin);

  int a, b;
  while (cin >> n >> k) {
    for (int i = 1; i <= n; ++i) {
      cin >> num[i];
      maze[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      cin >> a >> b;
      maze[a].push_back(b);
      maze[b].push_back(a);
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= k; ++j)
        dp[i][j][0] = dp[i][j][1] = num[i];
    dfs(1, 0, 0);
    cout << max(dp[1][k][0], dp[1][k][1]) << endl;
  }
  return 0;
} 

