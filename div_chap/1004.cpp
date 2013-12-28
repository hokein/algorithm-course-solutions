#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;
const double epos = 10e-7;
int month[N];
double money[N];
int n;

double ppow(double p, int times) {
  double ret = 1;
  while (times) {
    ret *= p;
    --times;
  }
  return ret;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int last_month;
  double total;
  int is_first = true;
  int cases = 0;
  while (cin >> n) {
    if (n == -1)
      break;
    for (int i = 0; i < n; ++i)
      cin >> month[i] >> money[i];
    cin >> last_month >> total;

    double l = 0, r = 1;
    while (r-l > epos) {
      double mid = l + (r-l)/2;
      double sum = 0;
      for (int i = 0; i < n; ++i) 
        sum += money[i]*ppow(1+mid, last_month-month[i]+1);
      if (sum < total) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (!is_first)
      printf("\n");
    is_first = false;
    printf("Case %d: %.5f\n", ++cases, l);
  }
  return 0;
} 
