// testcases:
// 6 4 5 3 2 4 4  : 2
// 4 6 3 1 5 : 3
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1005;
int num[N], dp[N][N], ans = 0, n;
int player1_select[N][N];

int DP2(int, int);

// player1 turns
int DP1(int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  int v1 = num[i] + DP2(i+1, j);
  int v2 = num[j] + DP2(i, j-1);
  return dp[i][j] = max(v1, v2);
}

// player2 turns
int DP2(int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  if (i == j)
    return dp[i][j] = 0;
  if (num[i] >= num[j])
    return dp[i][j] = DP1(i+1, j);
  else
    return dp[i][j] = DP1(i, j-1); 
}

int main() {
  //freopen("test.txt", "r", stdin);

  int cases = 0;
  while (cin >> n && n) {
    memset(dp, -1, sizeof(dp));
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> num[i];
      sum += num[i];
    }
    DP1(1, n);

    printf(
        "In game %d, the greedy strategy might lose by as many as %d points.\n",
        ++cases, 2*dp[1][n]-sum);
  }
  return 0;
} 
