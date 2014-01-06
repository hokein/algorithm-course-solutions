// LCA
// Transfer to RMQ problem, using segment tree.
// 
// Some data structures.
// depth[]: record node's depth in tree
// vs[]: the dfs vis sequence
// id[v]: for each node v, the first appear position(index) in vs[]
//
// LCA(u, v) = vs[id[u] <= i <= id[v], i is the minimum depth[i]]
//
// Sample:
//         1
//        / \
//       2  3
//      /\   \ 
//     4  5   6
//       / \
//      7  8
// vs[]:     1 2 4 2 5 7 5 8 5 2 1 3 6 3 1
// depth[]:  0 1 2 1 2 3 2 3 2 1 0 1 2 1 0
// id[]:     0 1 11 2 4 12 5 7
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int N = 20005;

vector<int> maze[N];
int n, st, ed;

int vs[N], ids[N], cnts, depth[N];
bool is_root[N];

// record minimum value/position of range node.
int mini[N<<4], mini_index[N<<4];

void dfs(int u, int parent, int level) {
  vs[cnts] = u;
  ids[u] = cnts; // record first appear position.
  depth[cnts++] = level;
  for (int i = 0; i < maze[u].size(); ++i) {
    int v = maze[u][i];
    if (v != parent) {
      dfs(v, u, level+1);
      vs[cnts] = u;
      depth[cnts++] = level;
    }
  }
}

void push_up(int rt) {
  mini[rt] = mini[rt<<1];
  mini_index[rt] = mini_index[(rt<<1)];
  if (mini[rt<<1] > mini[(rt<<1)+1]) {
    mini[rt] = mini[(rt<<1)+1];
    mini_index[rt] = mini_index[(rt<<1)+1];
  }
}

void build_tree(int l, int r, int rt) {
  if (l == r) {
    mini_index[rt] = l;
    mini[rt] = depth[l];
    return ;
  }
  int m = (l+r) >> 1;
  build_tree(l, m, rt<<1);
  build_tree(m+1, r, (rt<<1)+1);
  push_up(rt);
}

P query(int ql, int qr, int l, int r, int rt) {
  if (ql <= l && r <= qr)
    return P(mini[rt], mini_index[rt]);
  int m = (l+r) >> 1;
  P res(2*N, 0);
  if (ql <= m)
    res = query(ql, qr, l, m, rt<<1);
  if (qr > m) {
    P tmp = query(ql, qr, m+1, r, (rt<<1)+1);
    if (tmp.first < res.first)
      res = tmp;
  }
  return res;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int T, a, b;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    cnts = 1;
    memset(is_root, 1, sizeof(is_root));
    for (int i = 0; i < N; ++i)
      maze[i].clear();

    for (int i = 0; i < n-1; ++i) {
      scanf("%d %d", &a, &b);
      maze[a].push_back(b);
      is_root[b] = false;
    }

    scanf("%d %d", &st, &ed);
    for (int i = 1; i <= n; ++i)
      if (is_root[i]) {
         dfs(i, 0, 0);
         build_tree(1, cnts-1, 1);
         int id_u = ids[st];
         int id_v = ids[ed];
         cout << vs[ query(min(id_u, id_v), max(id_u, id_v), 1, cnts-1, 1).second ] << endl;
         break;
      }
  }
  return 0;
} 
