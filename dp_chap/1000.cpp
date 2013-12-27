#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 100000000;
const int N = 100;

int num[N][N];
int n, m;

int cal_one_dig(int digs) {
  int ret = 0;
  while (digs) {
    ret += digs&1;
    digs >>= 1;
  }
  return ret;
}

int sum(int digs) {
  int i = 1, j = 1;
  int ret = num[i][j];
  for (int k = 0; k < n+m-2; ++k) {
    int dig = digs&1;
    if (dig) {
      j += 1;
    } else {
      i += 1;
    }
    ret += num[i][j];
    digs >>= 1;
  }
  return ret;
}

int main() {
  //freopen("test.txt", "r", stdin);
  //
  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        cin >> num[i][j]; 
    int digs = n-1+m-1;
    int ans = INF;
    for (int i = 0; i < (1<<digs); ++i) {
      if (cal_one_dig(i) != m-1) continue;
      int ret = sum(i);
      if (ret > 0)
        ans = min(ans, ret);
    }
    if (ans == INF)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
} 
