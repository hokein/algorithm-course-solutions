// DP 
// dp[i][j]: all the member from range(i, j) can be defeated, not include i, j, clockwise.
// dp[i][j] = dp[i][k] & dp[k][j] & (i defeats k or j defeats k), k is in range(i, j)
//            
// dp[i][i] = 1, means i can defeat all other members,
//            0, otherwise.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;

bool maze[N][N], dp[N][N];
int n;

int next(int i) {
  return (i+1)%n;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int T, v;
  cin >> T;
  while (T--) {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        cin >> v;
        maze[i][j] = v==1;
      }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
      dp[i][next(i)] = dp[next(i)][i] = 1;

    for (int len = 2; len <= n; ++len) // enum len
      for (int i = 0; i < n; ++i) { // start position
        int j = (i+len)%n; // end position
        for (int k = next(i); k != j; k = next(k)) { // clockwise
          dp[i][j] |= dp[i][k]&dp[k][j]&(maze[i][k] || maze[j][k]);
        }
      }
    for (int i = 0; i < n; ++i)
      cout << dp[i][i] << endl;
    cout << endl;
  }
  return 0;
} 
