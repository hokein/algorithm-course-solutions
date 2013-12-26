//
// Change undirected graph to direct tree, random select a root. 
// dp[n][0]: root n subtree 1st biggest len
// dp[n][1]: root n subtree 2nd biggest len
// dp[n][2]: root n subtree through father biggest len
//
// dp[v][2] = max(dp[u][0], dp[u][2]) + w(u,v)  dp[v][0] != dp[u][0]+w
//            max(dp[u][1], dp[u][2]) + w(u,v)  dp[v][0] == dp[u][0]+w
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
const int N = 10005;

vector<P> maze[N];
bool vis[N];
int n;
int dp[N][3]; // 0: sub tree biggest; 1: sub tree 2nd biggest; 2: father

void dfs1(int u) {
  vis[u] = true;
  int big1 = 0, big2 = 0;
  for (int i = 0; i < maze[u].size(); ++i) {
    P p = maze[u][i];
    int v = p.first; 
    int w = p.second; 
    if (vis[v]) continue;
    dfs1(v);
    int tmp = dp[v][0] + w;
    if (tmp >= big1) {
      big2 = big1;
      big1 = tmp;
    } else if (tmp > big2) {
      big2 = tmp;
    }
  }
  dp[u][0] = big1;
  dp[u][1] = big2;
}

void dfs2(int u) {
  vis[u] = true;
  for (int i = 0; i < maze[u].size(); ++i) {
    P p = maze[u][i];
    int v = maze[u][i].first;
    int w = maze[u][i].second;
    if (vis[v]) continue;
    if (dp[u][0] == dp[v][0]+w) {
      dp[v][2] = max(dp[u][1], dp[u][2])+w; // (second_dis, father) + w
    } else {
      dp[v][2] = max(dp[u][0], dp[u][2])+w; // (first_dis, father) + w
    }
    dfs2(v);
  }
}


int main() {
  //freopen("test.txt", "r", stdin);

  while (scanf("%d", &n) != EOF) {
    int a, b;
    for (int i = 0; i < N; ++i)
      maze[i].clear();
    for (int i = 2; i <= n; ++i) {
      cin >> a >> b;
      maze[i].push_back(P(a, b));
      maze[a].push_back(P(i, b));
    }

    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dfs1(1);
    memset(vis, 0, sizeof(vis));
    dfs2(1);
    for (int i = 1; i <= n; ++i)
      cout << max(dp[i][0], dp[i][2]) << endl;
  }
  return 0;
} 
