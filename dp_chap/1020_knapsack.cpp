// 多重背包问题
// dp[i][v] = max{dp[i-1][v-k*c[i]]+k*w[i], 0 <= k <= n[i]}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int kMax = 100005;
const int N = 10000;

P bills[N];
int n, v;
bool dp[kMax];

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> v) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> bills[i].first >> bills[i].second; // size, w
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
      for (int j = v; j >= 0; --j)
        for (int k = 0; k <= bills[i].first; ++k) {
          if (j < k*bills[i].second)
            break;
          dp[j] |= dp[j-k*bills[i].second];
        }
    for (int i = v; i >= 0; --i)
      if (dp[i]) {
        cout << i << endl;
        break;
      }
  }

  return 0;
}
