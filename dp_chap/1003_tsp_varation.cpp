// TSP DP
//
// dp[s][u]: the longest way, start from node u, visit all nodes in set s.  
//
// dp[s][v] = path[v][u] + dp[s-{v}][u], u in s.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 15;

int maze[N][N], n;
int dp[1<<N][N];
int son[1<<N][N];
int ans;

void print_path(int s, int u) {
  if (s == 0)
    return;
  cout << " " << u+1;
  print_path(s-(1<<u), son[s][u]);
}

int main() {
  //freopen("test.txt", "r", stdin);

  bool is_first = true;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> maze[i][j];
   
    memset(dp, 0, sizeof(dp));
    dp[(1<<n)-1][0] = 0;
    for (int s = 1; s < (1<<n); ++s) {
      for (int v = 0; v < n; ++v) { // enum new reach node.
        if (!((s>>v)&1)) continue;
        // v should not in set s.
        for (int u = 0; u < n; ++u) // enum node in u
          if (((s>>u)&1) && u != v) { //  u should in s
            int len = dp[s-(1<<v)][u]+maze[v][u];
            if (maze[v][u] && dp[s][v] < len) {
              dp[s][v] = len;
              son[s][v] = u;
            }
          }
      }
    }
    int maxx = 0, max_pos, max_s;
    for (int s = 1; s < (1<<n); ++s)
      for (int i = 0; i < n; ++i)
        if (maxx < dp[s][i]) {
          maxx = dp[s][i];
          max_pos = i;
          max_s = s;
        }
          
    if (!is_first)
      cout << endl;
    is_first = false;
    cout << "The longest path has length " << maxx << endl; 
    if (maxx > 0) {
      cout << "Such a path is";
      print_path(max_s, max_pos);
      cout << endl;
    }
  }
  return 0;
} 
