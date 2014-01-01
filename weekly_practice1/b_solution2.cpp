#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;
const int MAX = 100000*20+5;

int n, w[N];
bool dp[MAX];

int main() {

  while (cin >> n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> w[i];
      sum += w[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = MAX-5; j >= w[i]; --j)
        dp[j] |= dp[j-w[i]];
    for (int j = sum/2; j <= sum; ++j) 
      if (dp[j] && 2*j >= sum) {
        cout << 2*j - sum << endl;
        break;
      }
  }
  return 0;
} 
