#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000;

struct Node {
  char c;
  int l, r;
};

Node nodes[N];
bool vis[N], is_root[N];
int n;

void pre_order(int u) {
  cout << nodes[u].c;
  if (nodes[u].l == 0 && nodes[u].r == 0)
    return;
  if (nodes[u].l != 0)
    pre_order(nodes[u].l);
  if (nodes[u].r != 0)
    pre_order(nodes[u].r);
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    memset(is_root, 1, sizeof(is_root));
    memset(vis, 0, sizeof(vis));
    int id;
    for (int i = 0; i < n; ++i) {
      cin >> id;
      cin >> nodes[id].c >> nodes[id].l >> nodes[id].r;
      is_root[nodes[id].l] = is_root[nodes[id].r] = false;
      vis[id] = true;
    }

    for (int i = 1; i < N; ++i) {
      if (is_root[i] && vis[i]) {
        pre_order(i);
        cout << endl;
      }
    }
  }
  return 0;
} 
