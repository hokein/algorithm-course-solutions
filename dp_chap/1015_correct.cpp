#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100005*10;
const ll INF = 100000000000;

ll num[N], sum[N];
int cnt[N];
int n;

int main() {
  //freopen("test.txt", "r", stdin);
  //freopen("correct.txt", "w", stdout);

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> num[i];
    }
    sum[0] = 0;
    ll maxx = -INF;
    for (int i = 1; i <= n; ++i) {
      sum[i] = max(num[i], sum[i-1]+num[i]);
      maxx = max(sum[i], maxx);
    }

    // Find minimum subsum.
    ll all_sum = 0; 
    bool has_positive = 0;
    for (int i = 1; i <= n; ++i) {
      has_positive |= (num[i] >= 0);
      all_sum += num[i];
      num[i] = -num[i];
    }

    sum[0] = 0;
    ll maxx_neg = -INF;
    for (int i = 1; i <= n; ++i) {
      sum[i] = max(num[i], sum[i-1]+num[i]);
      maxx_neg = max(maxx_neg, sum[i]);
    }

    if (has_positive)
      cout << max(maxx, all_sum+maxx_neg) << endl;
    else
      cout << maxx << endl;

  }
  return 0;
} 
