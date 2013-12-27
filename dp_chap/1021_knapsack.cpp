#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMax = 30005;
const int N = 1000;

int dp[kMax];
int n, m, c[N], w[N];

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    for (int i = 0; i < m; ++i)
      cin >> c[i] >> w[i];

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i)
      for (int v = n; v >= c[i]; --v)
        dp[v] = max(dp[v], dp[v-c[i]]+w[i]*c[i]);
    cout << dp[n] << endl;
  }

  return 0;
} 
