// 完全背包
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;

int dp[N];
int n, sum, coin[N]; 

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> sum >> n) {
    for (int i = 0; i < n; ++i)
      cin >> coin[i];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
      for (int v = coin[i]; v <= sum; ++v)
        dp[v] += dp[v-coin[i]];
    cout << dp[sum] << endl;
  }
  return 0;
} 
