#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 200;

int a[N][N], n;

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        cin >> a[i][j];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        int sum[N][N] = {0};
        for (int x = i; x <= n; ++x) {
          int col_sum[N] = {0};
          for (int y = j; y <= n; ++y)
            col_sum[y] = col_sum[y-1] + a[x][y];

          for (int y = j; y <= n; ++y) {
             sum[x][y] = sum[x-1][y]+col_sum[y]-col_sum[j-1]; 
             ans = max(ans, sum[x][y]);
          }
        }
      }

    cout << ans << endl;
  }
  return 0;
} 
