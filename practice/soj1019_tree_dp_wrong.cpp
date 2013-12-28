// An wrong solution.
//
// Since we can retrieve same node more than one times.
// This solution will calculate the longest path, and each node will retrieve at most one time.
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
int dp[N][K][3];

void dfs1(int u, int fa, int k) {
  int larger, largest;
  largest = larger = 0;
  for (int i = 0; i < maze[u].size(); ++i) {
    int v = maze[u][i];
    if (v != fa) {
      dfs1(v, u, k);
      int tmp = dp[v][k-1][0]+num[u];
      if (tmp >= largest) {
        larger = largest;
        largest = tmp;
      } else if (tmp > larger) {
        larger = tmp;
      }
    }
  }
  dp[u][k][0] = largest;
  dp[u][k][1] = larger;
}

void dfs2(int u, int fa, int k) {
  for (int i = 0; i < maze[u].size(); ++i) {
    int v = maze[u][i];
    if (v != fa) {
      if (dp[u][k-1][0]+num[v] != dp[u][k][0])
        dp[v][k][2] = max(dp[u][k-1][0], dp[u][k-1][2])+num[v];
      else
        dp[v][k][2] = max(dp[u][k-1][1], dp[u][k-1][2])+num[v];
      dfs2(v, u, k);
    }
  }
}

int main() {
  freopen("test.txt", "r", stdin);

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
    for (int j = 1; j <= k; ++j) {
      dfs1(1, 0, j);
      dfs2(1, 0, j);
    }
    int maxx = 0;
    for (int i = 1; i <= n; ++i)
      maxx = max(max(dp[i][k][0], dp[i][k][2]), maxx);
    cout << maxx << endl;
  }
  return 0;
} 
