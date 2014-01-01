#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;

int sum[N];
int n;
int val[N], dp[N][N];

int DP(int x, int y) {
  if (dp[x][y] != -1)
    return dp[x][y];
  if (x == y)
    return dp[x][y] = 0;
  dp[x][y] = max(sum[y]-sum[x+1]-DP(x+1, y)+val[x],
                 sum[y-1]-sum[x]-DP(x, y-1)+val[y-1]);
  return dp[x][y];
}
int main() {
  freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> val[i];
    sum[0] = 0;
    for (int i = 1; i <= n; ++i)
      sum[i] = sum[i-1]+val[i-1];

    memset(dp, -1, sizeof(dp));
    cout << DP(0, n) << endl;
  }
  return 0;
} 
