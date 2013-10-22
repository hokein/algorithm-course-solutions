#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> P;
ll a, b;

inline ll pow(ll v, ll n) {
  if (n == 0)
    return 1;
  ll res = pow(v, n/2);
  if (n%2 == 0)
    return res*res;
  return res*res*v;
}

// n^k =b, b != 1, n != 1
inline ll find_k(ll b, ll n) {
  for (int k = 0; ; ++k) {
    ll res = pow(n, k);
    if (res > b)
      return -1;
    if (res == b)
      return k;
  }
  return -1;
}

P find_n(ll a, ll b) {
  for (ll n = 2; ; ++n) {
    ll k = find_k(b, n);
    if (k != -1 && pow(n+1, k) == a) {
      return P(n, k); 
    }
  }
  return P(1,1);
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (scanf("%lld%lld", &a, &b) != EOF) {
    ll n, k;
    if (!a && !b)
      break;
    if (b == 1) { // n = 1, 2^k = a
      n = 1;
      k = find_k(a, 2);   
    }
    else {
      P p = find_n(a, b);
      n = p.first;
      k = p.second;
    }
    ll num_cats = 0, sum_height = 0;
    for (int i = 0; i < k; ++i)
      num_cats += pow(n, i);
    for (int i = 0, h = a; i <= k; ++i) {
      sum_height += h*pow(n, i);
      h /= (n+1);
    }
    printf("%lld %lld\n", num_cats, sum_height);
  }
  return 0;
} 
