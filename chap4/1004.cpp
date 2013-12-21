#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
ll n;

int digs(ll num) {
  int ret = 0;
  while (num) {
    ++ret;
    num /= 2;
  }
  return ret;
}

// v(reverse(v))
ll combine_even(int v) {
  int tmp = v;
  ll ret = v;
  while (tmp) {
    ret = 2*ret + tmp%2;
    tmp /= 2;
  }
  return ret;
}

// v0reverse(v)
// v1reverse(v)
ll combine_odd(int v, int base) {
  int tmp = v;
  ll ret = 0;
  ll pow2 = 1;
  while (tmp) {
    pow2 *= 2;
    ret = 2*ret + tmp%2;
    tmp /= 2;
  }
  return v*(pow2*2) + base*pow2 + ret;
}

int main() {
  //freopen("test.txt", "r", stdin);
  while (cin >> n) {
    int digits = digs(n);
    int ans = 1;
    for (int i = 1; i < (1<<((digits+1)/2)); ++i) {
      if (combine_even(i) <= n)
        ++ans;
      if (combine_odd(i, 0) <= n)
        ++ans;
      if (combine_odd(i, 1) <= n)
        ++ans;
    }
    cout << ans << endl;
  }

  return 0;
}                                 
