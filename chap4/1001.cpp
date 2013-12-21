#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll v;
ll a1, b1, a2, b2, c, g;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

P extend_gcd(ll a, ll b) {
  if (b == 0)
    return P(1, 0);
  P p = extend_gcd(b, a%b);
  return P(p.second, p.first-a/b*p.second);
}

ll cal_cost(const P& p) {
  return a1*p.first + b1*p.second;
}

P make_positive(const P& p) {
  if (p.second >= 0) {
    ll t = p.second/(a2/g);
    return P(p.first+t*(b2/g), p.second-(a2/g)*t);
  }
  if (p.first >= 0) {
    ll t = p.first/(b2/g);
    return P(p.first-(b2/g)*t, p.second+(a2/g)*t);
  }
}
int main() {
  //freopen("test.txt", "r", stdin);

  int cases = 1;
  while (cin >> c && c) {
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    g = gcd(a2, b2);
    if (c%g != 0) {
      printf("Data set %d: cannot be flown\n", cases++);
      continue;
    }

    P p = extend_gcd(a2, b2);
    p.first = c/g*p.first;
    p.second = c/g*p.second;

    p = make_positive(p);

    ll cost = cal_cost(p);
    P ans = p;
    if (p.second >= 0) {
      ll t = p.second/(a2/g);
      P min_p_y(p.first+t*(b2/g), p.second-(a2/g)*t);
      if (cost > cal_cost(min_p_y)) {
        ans = min_p_y;
        cost = cal_cost(min_p_y);
      }
    }
    if (p.first >= 0) {
      ll t = p.first/(b2/g);
      P min_p_x(p.first-(b2/g)*t, p.second+(a2/g)*t);
      if (cost > cal_cost(min_p_x)) {
        ans = min_p_x;
        cost = cal_cost(min_p_x);
      }
    }

    printf("Data set %d: %lld aircraft A, %lld aircraft B\n",
            cases++, ans.first, ans.second);
  }
  return 0;
} 
