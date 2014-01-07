#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;

struct info {
  vector<int> dims;
  int id;
};

info boxes[N];
int n, k, is_first, fa[N], dp[N];
vector<int> path;

bool cmp(const info& a, const info& b) {
  for (int i = 0; i < a.dims.size(); ++i) {
    if (a.dims[i] > b.dims[i])
      return false;
  }
  return true;
}

bool can_put(int p1, int p2) {
  // all edges in p1 should less than p2.
  for (int i = 0; i < boxes[p1].dims.size(); ++i) 
    if (boxes[p1].dims[i] >= boxes[p2].dims[i])
      return false;
  return true;
}

void print_path(int pos) {
  if (pos == -1)
    return;
  print_path(fa[pos]);
  path.push_back(boxes[pos].id);
}

int main() {
  //freopen("test.txt", "r", stdin);

  int v;
  while (cin >> n >> k) {
    for (int i = 1; i <= n; ++i) {
      boxes[i].dims.clear();
      boxes[i].id = i;
      for (int j = 0; j < k; ++j) {
        cin >> v;
        boxes[i].dims.push_back(v);
      }
      sort((boxes[i].dims).begin(), (boxes[i].dims).end());
    }

    sort(boxes+1, boxes+n+1, cmp);
    memset(fa, -1, sizeof(fa));
    for (int i = 0; i <= n; ++i)
      dp[i] = 1;
    for (int i = 2; i <= n; ++i)
      for (int j = 1; j < i; ++j) {
        if (can_put(j, i)) {
          if (dp[i] < dp[j]+1) {
            dp[i] = dp[j]+1;
            fa[i] = j;
          }
        } 
      }
    int pos = 1;    
    for (int i = pos+1; i <= n; ++i)
      if (dp[i] > dp[pos])
        pos = i;
    cout << dp[pos] << endl;
    path.clear();
    print_path(pos);
    for (int i = 0; i < path.size()-1; ++i)
      cout << path[i] << " ";
    cout << path[path.size()-1] << endl;
  }
  return 0;
} 
