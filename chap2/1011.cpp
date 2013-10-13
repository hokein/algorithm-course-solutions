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

const int N = 10005;
int n, k, ans = 0;
vector<P> maze[N];
set<P> vis;

void dfs(int p, int len) {
  ans = ans>len?ans:len;
  for (int i = 0; i < maze[p].size(); ++i) {
    int next_p = maze[p][i].first;
    if (vis.find(P(p, next_p)) == vis.end() && 
        vis.find(P(next_p, p)) == vis.end()) {
      P pp(p, next_p);
      vis.insert(pp);
      dfs(next_p, len+maze[p][i].second);
      vis.erase(pp);
    }
  }
}

int main() {
  int x, y, d;
  while (cin >> n >> k) {
    for (int i = 1; i <= n; ++i)
      maze[i].clear();
    for (int i = 0; i < n-1; ++i) {
      cin >> x >> y >> d;
      maze[x].push_back(P(y, d));
      maze[y].push_back(P(x, d));
    }
    ans = 0;
    dfs(k, 0);
    cout << ans << endl;
  }
  return 0;
} 
