#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

const int N = 10000000;
ull num[N];

void solve() {
  ull n;
  if (scanf("%I64u", &n) == EOF) {
    return;
  }

  solve();
  printf("%.4f\n", sqrt(n));
}
int main() {
  //freopen("test.txt", "r", stdin);

  solve();
  return 0;
} 
