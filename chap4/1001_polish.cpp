// given a1, b1, a2, b2, c
// find x,y which satisfied 
//    a2*x + b2*y = c
//    minimum (a1*x + b1*y) value, x, y >= 0
//
// first find a solution (x, y) of a2*x + b2*y = c
// using extend gcd algorithm
//  a2*x + b2*y = gcd(a2, b2)
//  (x', y')
//
//  (x0, y0) = (c/g*x', c/g*y')
//
//  all solutions of a2*x + b2*y = c is like
//  (x, y) = (x0+b2/g*t, y0-a2/g*t), t is Z
//
//  x0+b2/g*t >= 0 and y0-a2/g*t >= 0
//  => -x0/(b2/g) <= t <= y0/(a2/g)
//  Be careful t is integer.
//
//  The ans is t_min or t_max 
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

int main() {
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
    // a2x+b2y=c solution
    p.first = c/g*p.first;
    p.second = c/g*p.second;

    // calculate min(a1x+b2y), x,y >= 0
    ll x = p.first, y = p.second;
    ll min_t = -(x/(b2/g)), max_t = y/(a2/g);
    if (x+b2/g*min_t < 0)
      ++min_t;
    if (y-a2/g*max_t < 0)
      --max_t;

    P p2(x+b2/g*min_t,y-a2/g*min_t), p1(x+b2/g*max_t, y-a2/g*max_t);
    P ans;
    if (cal_cost(p1) <= cal_cost(p2))
      ans = p1;
    else
      ans = p2;
    printf("Data set %d: %lld aircraft A, %lld aircraft B\n",
           cases++, ans.first, ans.second);
  }
  return 0;
} 
