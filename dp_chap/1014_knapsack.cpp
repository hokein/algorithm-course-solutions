// 完全背包
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMax = 1000;

int dp[kMax];
int n;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 5; i <= n; ++i)
      for (int v = i; v <= n; ++v)
        dp[v] += dp[v-i];
    cout << dp[n] << endl;
  }
  return 0;
} 
