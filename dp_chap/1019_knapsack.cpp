// 分组背包
// dp[k][v] = max(dp[k-1][v], dp[k-1][v-c[i]]+w[i], {i|i belongs to group k})
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int N = 10000;

vector<P> days[N]; // (energy , value)
int dp[N];
int p, n;

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> p >> n;
    for (int i = 0; i < N; ++i)
      days[i].clear();
    int a, b, c;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b >> c;
      ++a;
      days[a].push_back(P(b, c));
    }

    memset(dp, 0, sizeof(dp));
    for (int k = 1; k <= n; ++k)
      for (int v = p; v >= 0; --v) {
        // using tmp here, since c can be 0, 
        // dp[v] = max(dp[v], dp[v-c]+w), then dp[v] will get changed.
        int tmp = dp[v];
        for (int i = 0; i < days[k].size(); ++i) {
          int c = days[k][i].first;
          int w = days[k][i].second;
          if (v >= c) {
            tmp = max(tmp, dp[v-c]+w);
          }
        }
        dp[v] = tmp;
      }

    cout << dp[p] << endl;
  }
  return 0;
} 
