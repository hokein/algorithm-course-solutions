// Using STL::complex
// (a, b), a+bi, a*e^(ithera)
// 
// complex<double, double> a, b
// b = a*complex<double>(0, 1), rotate 90, counter-clock.
//
// exp(complex<double>(0, b)), e^(0+bi) = cos(b)+sin(b)*i, b is in radian
// exp(complex<double>(a, b)), e^(a+bi) = e^(a)*(cos(b)+sin(b)*i)
//
// b = a*exp(complex<double>(0, b)), rotate b in radian. counter-clock.
//
// norm(a-b), square of dis(a, b).
// abs(a-b), dis(a, b). 
// a.real(), x
// a.imag(), y 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef complex<double> P; 

const int N = 10000;
int n;
double x[N];
P p[N]; 

P calculate(const P& a, const P& b) {
  P c = (a+b)/P(2, 0); // calculate mid point
  P ca = c-a; 
  P rotate_ca = ca*P(0,1); // rotate 90
  double height = sqrt(4.0-abs(ca)*abs(ca));
  return c+rotate_ca/abs(rotate_ca)*height;
}

int main() {
  //freopen("test.txt", "r", stdin);

  P t(0, 3.1415926/2);
  cout << t.real() << endl;
  cout << exp(t) << endl;
  int cases = 0;
  while (cin >> n && n) {
    for (int i = 0; i < n; ++i)
      cin >> x[i]; 
    sort(x, x+n);
    for (int i = 0; i < n; ++i)
      p[i] = P(x[i], 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n-i-1; ++j)
        p[j] = calculate(p[j], p[j+1]);
    }
    printf("%.4f %.4f\n", p[0].real(), p[0].imag());
  }
  return 0;
} 
