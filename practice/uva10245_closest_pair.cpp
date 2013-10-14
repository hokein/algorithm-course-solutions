// The closest pair problem: Divide and Conquer
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<double, double> P;

const int N = 1000000;
const int INF = 1000000000;

P p[N];
int n;

double dis(int a, int b) {
  double dx = p[a].first - p[b].first;
  double dy = p[a].second - p[b].second;
  return sqrt(dx*dx+dy*dy);
}

double solve(int st, int ed) {
  if (ed-st <= 1)
    return INF;
  int mid = (st+ed)/2;
  double x0 = p[mid].first;
  double d = min(solve(st, mid), solve(mid+1, ed));
  vector<P> v;
  for (int i = st; i < ed; ++i) {
    if (fabs(p[i].first-x0) > d) continue;
    for (int j = 0; j < v.size(); ++j) {
      if (fabs(v[j].second-p[i].second) > d) continue;
      double dx = v[j].first - p[i].first;
      double dy = v[j].second - p[i].second;
      d = min(d, sqrt(dx*dx+dy*dy));
    }
    v.push_back(p[i]);
  }
  return d;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n && n) {
    for (int i = 0; i < n; ++i)
      cin >> p[i].first >> p[i].second;
    sort(p, p+n);
    double ans = solve(0, n);
    if (ans < 10000)
      printf("%.4f\n", ans);
    else
      printf("INFINITY\n");
  }
  return 0;
} 
