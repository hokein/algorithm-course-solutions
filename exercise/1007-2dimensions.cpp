#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 50;

int dp[N][N][N][N];
int sum1[N], sum2[N], val1[N], val2[N];
int n;

int DP(int i, int j, int ii, int jj) {
  if (dp[i][j][ii][jj] != -1)
    return dp[i][j][ii][jj];
  if (j == i && jj == ii)
    return dp[i][j][ii][jj] = 0;

  int result = 0;
  if (j > i) {
    result = max(result, sum1[j]-sum1[i+1]+sum2[jj]-sum2[ii]-DP(i+1, j, ii, jj)+val1[i]);
    result = max(result, sum1[j-1]-sum1[i]+sum2[jj]-sum2[ii]-DP(i, j-1, ii, jj)+val1[j-1]);
  }
  if (jj > ii) {
    result = max(result, sum1[j]-sum1[i]+sum2[jj]-sum2[ii+1]-DP(i, j, ii+1, jj)+val2[ii]);
    result = max(result, sum1[j]-sum1[i]+sum2[jj-1]-sum2[ii]-DP(i, j, ii, jj-1)+val2[jj-1]);
  }

  return dp[i][j][ii][jj] = result;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> val1[i];
    for (int i = 0; i < n; ++i)
      cin >> val2[i];

    sum1[0] = sum2[0] = 0;
    for (int i = 1; i <= n; ++i) {
      sum1[i] = sum1[i-1] + val1[i-1];
      sum2[i] = sum2[i-1] + val2[i-1];
    }
    memset(dp, -1, sizeof(dp));
    cout << DP(0, n, 0, n) << endl;
  }
  return 0;
} 
