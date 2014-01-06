// LCA, Tarjan offline algorithm
// DFS + disjoint-set
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
const int N = 100005;

int father[N];

// disjoint-set
void make_set(int a) {
  father[a] = a;
}

int find_set(int a) {
  if (father[a] != a)
    return father[a] = find_set(father[a]);
  return a;
}

void union_set(int a, int b) {
  father[b] = a;
}

vector<int> maze[N];
int n, m, ans[N], ancestor[N], indegree[N], depth[N];
P queries_records[N];
bool vis[N];
map<string, int> str2ids;
// (u, v, ids)
vector<P> queries[N];

// Tarjan
void lca(int u, int level) {
  make_set(u);
  ancestor[find_set(u)] = u;
  depth[u] = level+1;
  for (int i = 0; i < maze[u].size(); ++i) {
    int v = maze[u][i];
    lca(v, level+1);
    union_set(u, v); // Careful! (u, v) not (v, u), make v is subtree of u
    ancestor[find_set(u)] = u;
  }
  vis[u] = 1;
  for (int i = 0; i < queries[u].size(); ++i) {
    int v = queries[u][i].first;
    int id = queries[u][i].second;
    if (vis[v])
      ans[id] = ancestor[find_set(v)];
  }
}

void clean_all() {
  str2ids.clear();
  memset(indegree, 0, sizeof(indegree));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < N; ++i) {
    queries[i].clear();
    maze[i].clear();
  }
}
int main() {
  //freopen("test.txt", "r", stdin);

  int T, pos1, pos2;
  string dir1, dir2;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    clean_all();
    //str2ids.clear();

    int cnt = 0;
    for (int i = 0; i < n-1; ++i) {
      cin >> dir1 >> dir2;
      if (str2ids.find(dir1) == str2ids.end()) {
        str2ids[dir1] = cnt++;
      }
      if (str2ids.find(dir2) == str2ids.end()) {
        str2ids[dir2] = cnt++;
      }
      pos1 = str2ids[dir1];
      pos2 = str2ids[dir2];
      maze[pos2].push_back(pos1);
      ++indegree[pos1];
    }

    for (int i = 0; i < m; ++i) {
      cin >> dir1 >> dir2;
      pos1 = str2ids[dir1];
      pos2 = str2ids[dir2];
      queries[pos1].push_back(P(pos2,i));
      queries[pos2].push_back(P(pos1,i));
      queries_records[i] = P(pos1, pos2);
    }
    int root = 0;
    for (int i = 0; i < cnt; ++i)
      if (indegree[i] == 0) {
        root = i;
        break;
      }
    lca(root, 0);
    for (int i = 0; i < m; ++i) {
      int lca_node = ans[i];
      int u = queries_records[i].first;
      int v = queries_records[i].second;
      int d = depth[u]-depth[lca_node];
      if (v == u)
        d = 0;
      else if (v != lca_node)
        ++d;
      cout << d << endl;
    }
  }
  return 0;
}
