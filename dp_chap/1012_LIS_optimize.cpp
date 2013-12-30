// LIS optimize
// O(nlogn)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P; // value, pos
const int N = 100000;

int n, dp[N], value[N];
// q[i]: the last number of length n LIS.
int q[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> value[i];
    }
    dp[0] = 0;
    int len = 0;
    for (int i = 1; i <= n; ++i) {
      int pos = lower_bound(q, q+len, value[i])-q;
      q[pos] = value[i];
      if (pos == len) // reach end, new to increase len.
        ++len;
      dp[i] = pos+1;
    }
    cout << len << endl;
  }
  return 0;
} 
