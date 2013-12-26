// Tree dp
//
// dp[i][0]: not select tree node i
// dp[i][1]: select tree node i
// 
// dp[i][0] = sum(dp[v][0], dp[v][1]),
// dp[i][1] = sum(dp[v][0]) + value[i]
// node v is node i's son.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 6006;

vector<int> maze[N];
bool vis[N];
int dp[N][2], n, value[N], indegree[N];

void dfs(int node) {
  if (vis[node])
    return;
  vis[node] = 1;
  for (int i = 0; i < maze[node].size(); ++i) {
    int v = maze[node][i];
    dfs(v);
    dp[node][0] += max(dp[v][0], dp[v][1]);
    dp[node][1] += dp[v][0];
  }
  dp[node][1] += value[node];
}
int main() {

  //freopen("test.txt", "r", stdin);

  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i)
      scanf("%d", &value[i]);
    for (int i = 0; i < N; ++i)
      maze[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    memset(indegree, 0, sizeof(indegree));
    int l, k;
    while (scanf("%d%d", &l, &k) != EOF) {
      if (!l && !k) break;
      maze[k].push_back(l);
      ++indegree[l];
    }
    for (int i = 1; i <= n; ++i)
      if (indegree[i] == 0) {
        dfs(i);
        cout << max(dp[i][0], dp[i][1]) << endl;
        break;
      }
  }
  return 0;
} 
