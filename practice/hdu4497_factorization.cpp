// given gcd(a, b, c), lcm(a, b, c)
// calculate all different combinations of (a,b,c) tuples.
//
// a = p1^t1*p2^t2*p3^t3*...*pn^tn
// b = p1^u1*p2^u2*p3^u3*...*Pn^un
// c = p1^v1*p2^v2*p3^v3*...*pn^vn
// 
// gcd = p1^min(t1,u1,v1)*p2^min(t2,u2,v2)*...*pn^min(tn,un,vn)
// lcm = p1^max(t1,u1,v1)*p2^max(t2,u2,v2)*...*pn^max(tn,un,vn)
//
//
// a' = a/gcd, b' = b/gcd, c' = c/gcd
// lcm/gcd = p1^w1*p2^w2*...*pn^wn
//
// a' = p1^t1*p2^t2*p3^t3*...*pn^tn
// b' = p1^u1*p2^u2*p3^u3*...*Pn^un
// c' = p1^v1*p2^v2*p3^v3*...*pn^vn
// 
// To p1: min(t1, u1, v1) = 0, max(t1, u1, v1) = w1
// (0, [0,w1], w1):
//    two special cases: (0, 0, w1), (0, w1, w1), 3*2 times.
//    other case: (0, (0, w1), w1): A(3,3)*(w1-1) = 6*(w1-1)
//    total: 6*(w1-1)+3*2 = 6w1.
// gcd(a', b', c') = 1
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ull, ull> P; // factor, cnt. 

vector<P> factors;

void factorization(ull k) {
  ull tmp = k;
  ull size = sqrt(tmp*1.0)+1;
  factors.clear();
  for (ull i = 2; i <= size && tmp > 1; ++i) {
    if (tmp%i == 0) {
      ull cnt = 0;
      while (tmp%i == 0) {
        cnt++;
        tmp/=i;
      } 
      factors.push_back(P(i, cnt));
    }
  }
  if (tmp > 1)
    factors.push_back(P(tmp, 1));
}

int main() {
  //freopen("test.txt", "r", stdin);

  ull gcd, lcm;
  int n;
  cin >> n;
  while (n--) {
    cin >> gcd >> lcm;
    if (lcm%gcd != 0) {
      cout << "0" << endl;
      continue;
    }
    factorization(lcm/gcd);
    ull ans = 1;
    for (int i = 0; i < factors.size(); ++i)
      ans *= 6*factors[i].second;
    cout << ans << endl;
  }
  return 0;
} 
