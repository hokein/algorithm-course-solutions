// Tree dp.
//
// dp[u][0] = sum{dp[v][1]}, v is u's son.
// dp[u][1] = sum{min(dp[v][0], dp[v][1])}, v is u's son.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
const int N = 100005*2;

vector<int> maze[N];
int dp[N][2]; // dp[i][0]: not select. dp[i][1]:  select.
bool vis[N];
int n, del_u, del_v;

bool find_cycle(int u, int fa) {
  vis[u] = 1;
  for (int i = 0; i < maze[u].size(); ++i) {
    int v = maze[u][i];
    if (v != fa) {
      if (vis[v]) {
        del_u = u;
        del_v = v;
        return true; 
      }
      if (find_cycle(v, u)) return true;
    }
  }
  return false;
}

void dfs(int u, int fa) {
  dp[u][1] = 1;
  dp[u][0] = 0;
  for (int i = 0; i < maze[u].size(); ++i) {
    int v = maze[u][i];
    if ((u == del_u && v == del_v) || (u == del_v && v == del_u)) continue;
    if (v != fa) {
      dfs(v, u);
      dp[u][0] += dp[v][1]; // node u not selected, all its son should be selected.
      dp[u][1] += min(dp[v][0], dp[v][1]); // node u selected, it's son either selected or not.
    }
  }
}

int main() {
  //freopen("test.txt", "r", stdin);

  int k, v;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i <= n; ++i)
      maze[i].clear();

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &k);
      for (int j = 0; j < k; ++j) {
        scanf("%d", &v);
        maze[i].push_back(v);
      }
    }

    memset(vis, 0, sizeof(vis));
    find_cycle(1, 0);
    dfs(del_u, 0);
    int maxx = dp[del_u][1];
    dfs(del_v, 0);
    maxx = min(maxx, dp[del_v][1]);
    printf("%d\n", maxx);
  }
  return 0;
} 
