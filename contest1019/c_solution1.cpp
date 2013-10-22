#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 200;

int col_sum[N][N], a[N][N], n, b[N];

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        cin >> a[i][j];
    memset(col_sum, 0, sizeof(col_sum));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        col_sum[j][i] = col_sum[j-1][i]+a[j][i];
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        for (int k = 1; k <= n; ++k)
          b[k] = col_sum[j][k]-col_sum[i-1][k];

        int dp[N] = {0};
        dp[0] = 0;
        for (int k = 1; k <= n; ++k) {
          dp[k] = max(dp[k], dp[k-1]+b[k]);
          ans = ans>dp[k]?ans:dp[k];
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
} 
