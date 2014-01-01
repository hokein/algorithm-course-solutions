#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMax = 50000;
const int N = 12;
const double epos = 1e-7;

ll value[N] = {
  0, 5, 10, 20, 50, 100,
  200, 500, 1000, 2000, 5000, 10000
};

bool is_equal(double a, double b) {
  return fabs(a-b) < epos;
}

int dp[kMax];
int main() {
  //freopen("test.txt", "r", stdin);

  double dv;

  dp[0] = 1;
  for (int i = 1; i < N; ++i)
    for (int v = value[i]; v < kMax; ++v)
       dp[v] += dp[v-value[i]];

  while (cin >> dv) {
    if (is_equal(dv, 0.0))
      break;
    int v = dv*100+0.5;
    printf("%6.2f%17ld\n", dv, dp[v]);
  }
  return 0;
} 
