// Solutions:
// L的值大太，直接按L的值进行动态规划不可行
// 分情况：若S和T相等，则踩到的石子数是固定的
// 若S和T不相等，因为S和T的最大值为10，所以当两个石子相差太远是没有意义的，
// 这里取的值为100，当石子距离相差100以上时，看作100，答案不变。
// 压缩后桥长度不超过10000，直接动态规划即可
//
// dp[i]: At position i, minimum steps
// dp[i] = min(dp[j]+isrock[i]), t <= i-j <= s, position can reach. 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 2000000;
const int M = 1000;
const int INF = 100000000;

int rocks[N], delta[N], dp[N], n;
bool valid[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int l, s, t, m;
  while (cin >> l >> s >> t >> m) {
    rocks[0] = 0;
    for (int i = 1; i <= m; ++i)
      cin >> rocks[i];

    sort(rocks, rocks+1+m); // sort rocks

    // special cases.
    if (s == t) {
      int ans = 0;
      for (int i = 1; i <= m; ++i)
        if (rocks[i]%s == 0)
          ++ans;
      cout << ans << endl;
      continue;
    }

    memset(dp, 0, sizeof(dp));
    memset(valid, 0, sizeof(valid));
    // rebuild graph.
    for (int i = 1; i <= m; ++i) {
      delta[i] = rocks[i] - rocks[i-1];
      if (delta[i] > 100) 
        delta[i] = 100;
    }
    for (int i = 1; i <= m; ++i) {
      rocks[i] = rocks[i-1]+delta[i];
      dp[rocks[i]] = 1;
    }

    int ans = INF;
    valid[0] = 1;
    int L = rocks[m]+100;
    for (int i = 1; i <= L; ++i) { // len
      int mini = INF;
      for (int j = i-t; j <= i-s; ++j) { // previous position.
        if (j >= 0 && valid[j]) {
          valid[i] = 1;
          mini = min(mini, dp[j]+dp[i]);
        }
      }
      dp[i] = mini;
    }
    for (int i = rocks[m]; i <= L; ++i)
      ans = min(dp[i], ans);
    cout << ans << endl;
  }
  return 0;
} 
