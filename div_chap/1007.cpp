#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10005;
const double epos = 10e-5;
const double pi = 3.14159265358979323846;
int radii[N];
int n, f;

bool is_valid(double v) {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int s = radii[i]*radii[i]*pi/v;
    cnt += s;
    if (cnt >= f)
      return true;
  }
  return false;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n >> f;
    for (int i = 0; i < n; ++i)
      cin >> radii[i];
    ++f; 
    sort(radii, radii+n, greater<int>());
    double l = 0, r = radii[0]*radii[0]*pi;
    while (r-l > epos) {
      double mid = l + (r-l)/2;
      if (is_valid(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    printf("%.4f\n", l);
  }
  return 0;
} 
