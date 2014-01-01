#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

inline ll pow(ll v, int n) {
  int res = 1;
  for (int i = 0; i < n; ++i)
    res *= v;
  return res;
}

inline ll C(int n, int i) {
  ll result = 1;
  for (int j = 0; j < i; ++j)
    result *= (n-j);

  for (int j = 1; j <= i; ++j)
    result /= j;
  return result;
}

int main() {
  int n, k;
  while (cin >> n >> k) {
    int sum = 0;
    for (int i = 0; i <= n/2; ++i) {
      int tmp = pow(k-1, n-i)*C(n-i, i);
      sum += tmp;
    }
    cout << sum << endl;
  }
  return 0;
} 
