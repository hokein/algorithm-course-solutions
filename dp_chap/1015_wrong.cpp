// An wrong solution
// 
// Test Data
// 1
// 7
// 5 4 -4 3 -3 -3 2
// Actual result: 10, expected output: 11
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
  freopen("test.txt", "r", stdin);
  //freopen("wrong.txt", "w", stdout);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> num[i];
      num[n+i] = num[i];
    }
    sum[0] = 0;
    cnt[0] = 0;
    ll maxx = -INF;
    for (int i = 1; i <= n; ++i) {
      if (sum[i-1]+num[i] > num[i]) {
        sum[i] = sum[i-1]+num[i];
        cnt[i] = cnt[i-1]+1;
      } else {
        sum[i] = num[i];
        cnt[i] = 1; 
      }
      maxx = max(maxx, sum[i]);
    }

    for (int i = n+1; i <= 2*n; ++i) {
      if (sum[i-1]+num[i] > num[i]) {
        if (cnt[i-1] == n) {
          cnt[i] = cnt[i-1];
          sum[i] = sum[i-1];
          for (int j = i-cnt[i-1]+1; num[j] <= 0 && j < i; ++j) {
            sum[i] -= num[j];
            --cnt[i];
          }
        } else {
          cnt[i] = cnt[i-1]+1;
          sum[i] = sum[i-1]+num[i];
        }
      } else {
        sum[i] = num[i];
        cnt[i] = 1;
      }
      maxx = max(maxx, sum[i]);
    }
    cout << maxx << endl;
  }

  return 0;
} 
