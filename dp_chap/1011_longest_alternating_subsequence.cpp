#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1005;

int dp[N], num[N], n;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n && n) {
    for (int i = 1; i <= n; ++i)
      cin >> num[i];

    dp[1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
      int maxx = 0;
      for (int j = 1; j < i; ++j)
        if (dp[j]%2 == 1 && num[i] < num[j]) {
          if (maxx < dp[j]+1)
            maxx = dp[j]+1;
        } else if (dp[j]%2 == 0 && num[i] > num[j]) {
          if (maxx < dp[j]+1)
            maxx = dp[j]+1;
        }
      dp[i] = max(1, maxx);
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
  }
  return 0;
} 
