#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;
const double PI = 3.1415926;

typedef pair<double, double> P;

P p[N];

double dis(const P& p1, const P& p2) {
  double dx = p1.first - p2.first;
  double dy = p1.second - p2.second;
  return sqrt(dx*dx + dy*dy);
}

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  double r;
  while (cin >> n >> r) {
    for (int i = 0; i < n; ++i)
      cin >> p[i].first >> p[i].second;

    double len = 0;
    for (int i = 1; i < n; ++i)
      len += dis(p[i-1], p[i]);
    if (n > 1)
      len += dis(p[n-1], p[0]);
    printf("%.2f\n",  len+2*PI*r); 
  }
  return 0;
} 
