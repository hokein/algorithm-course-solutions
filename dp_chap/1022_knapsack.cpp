#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMax = 10000005;
const int N = 1005;

int dp[kMax], n, m;
int c[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
      for (int v = m; v >= c[i]; --v)
        dp[v] = max(dp[v-c[i]]+c[i], dp[v]);
    cout << dp[m] << endl;
  }
  return 0;
} 
