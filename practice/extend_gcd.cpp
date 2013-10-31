#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

P extend_gcd(int a, int b) {
  if (b == 0)
    return P(1, 0);
  P p = extend_gcd(b, a%b);
  return P(p.second, p.first-a/b*p.second);
}

int main() {
  //freopen("test.txt", "r", stdin);
  int a, b;
  while (cin >> a >> b) {
    P res = extend_gcd(a, b);
    cout << a*res.first+b*res.second << endl;
  }

  return 0;
} 
