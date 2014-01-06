#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100005;

vector<int> maze[N], q[N];
int n, st, ed, indegree[N], father[N], ancestor[N];

bool vis[N];

void make_set(int a) {
  father[a] = a;
}

int find_set(int a) {
  if (a != father[a])
    return father[a] = find_set(father[a]);
  return a;
}

void union_set(int u, int v) {
  father[v] = u;
}

void lca(int u) {
  make_set(u);
  ancestor[find_set(u)] = u;
  for (int i = 0; i < maze[u].size(); ++i) {
    int v = maze[u][i];
    lca(v);
    union_set(u, v); // here (u, v)
    ancestor[find_set(u)] = u;
  }
  vis[u] = 1;
  if (u == st && vis[ed])
    cout << ancestor[find_set(ed)] << endl;
  else if (u == ed && vis[st])
    cout << ancestor[find_set(st)] << endl;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int T, a, b;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(indegree, 0, sizeof(indegree));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; ++i) {
      maze[i].clear();
      q[i].clear();
    }

    for (int i = 0; i < n-1; ++i) {
      scanf("%d %d", &a, &b);
      maze[a].push_back(b);
      ++indegree[b];
    }

    scanf("%d %d", &st, &ed);
    for (int i = 1; i <= n; ++i)
      if (indegree[i] == 0) {
         lca(i);
         break;
      }
  }
  return 0;
} 
