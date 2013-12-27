#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 505;
const int INF = 100000000;
int maze[N][N], n, d[N];
bool vis[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int v;
        cin >> v;
        maze[i][j] = maze[j][i] = v;
      }
    }

    memset(vis, 0, sizeof(vis));
    vis[0] = 0;
    for (int i = 0; i < n; ++i)
      d[i] = maze[0][i];
    int ans = d[0];
    while (1) {
      int min_len = INF;
      int pos = -1;
      for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
          if (min_len > d[i]) {
            min_len = d[pos=i];
          }
        }
      }
      if (pos == -1) break;
      ans = max(ans, min_len);
      vis[pos] = 1;
      for (int i = 0; i < n; ++i)
        if (!vis[i] && d[i] > maze[pos][i])
          d[i] = maze[pos][i];
    }
    cout << ans << endl;
    if (T > 0)
      cout << endl;
  }
  return 0;
} 
