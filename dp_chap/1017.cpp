#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100000;
const ll INF = 10000000000;
ll sum[N], num[N], cnt[N];
int n;

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      cin >> num[i];
    sum[0] = 0; cnt[0] = 0;
    for (int i = 1; i <= n; ++i)
      if (sum[i-1] > 0) {
        sum[i] = sum[i-1]+num[i];
        cnt[i] = cnt[i-1]+1;
      } else {
        sum[i] = num[i];
        cnt[i] = 1;
      }

    // =====^======
    //      |
    //    max_pos
    ll maxx = -INF;
    int max_pos = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
      if (maxx < sum[i])
        maxx = sum[max_pos=i];
    ans += maxx;

    // start part
    maxx = -INF;
    for (int i = 1; i <= max_pos-cnt[max_pos]; ++i)
      maxx = max(maxx, sum[i]);

    // end part
    sum[max_pos] = 0;
    for (int i = max_pos+1; i <= n; ++i) {
      sum[i] = max(sum[i-1]+num[i], num[i]);
      maxx = max(maxx, sum[i]);
    }

    if (cnt[max_pos] == 1 || maxx > 0)
      cout << ans + maxx << endl;
    else
      cout << ans << endl;
  }
  return 0;
} 
