#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 505;

ll num[N][N];
ll dp[N][N];
int n, m;

ll DP(int i, int j) {
  if (i == 0)
    return dp[i][j] = 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  dp[i][j] = DP(i-1, j)+num[i][j];
  if (j > 1) 
    dp[i][j] = max(dp[i][j], DP(i-1, j-1)+num[i][j]);
  if (j < m)
    dp[i][j] = max(dp[i][j], DP(i-1, j+1)+num[i][j]);
  return dp[i][j];
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = -1;
        cin >> num[i][j];
      }

    ll ans = 0;
    for (int i = 1; i <= m; ++i)
      ans = max(ans, DP(n, i));
    cout << ans << endl;
  }
  return 0;
} 
