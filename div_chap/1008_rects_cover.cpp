#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000;

struct Rect {
  int x1, y1;
  int x2, y2;
};

int calculate_area(const Rect& a) {
  return (a.x2-a.x1)*(a.y2-a.y1);
}

Rect rects[N];
int n, l, r, ans;

void Solve(int x1, int y1, int x2, int y2, int l, int r);

bool cmpx(const Rect& a, const Rect& b) {
  return a.x1 < b.x1;
}

bool cmpy(const Rect& a, const Rect& b) {
  return a.y1 < b.y1;
}

// [l, r], inclusive
bool cutx(int x1, int y1, int x2, int y2, int l, int r) {
  sort(rects+l, rects+r+1, cmpx);
  int mid_x = x1, area = 0;
  for (int i = l; i < r; ++i) {
    area += calculate_area(rects[i]);
    mid_x = max(mid_x, rects[i].x2);
    if (area == (mid_x-x1)*(y2-y1)) {
      Solve(x1, y1, mid_x, y2, l, i);
      Solve(mid_x, y1, x2, y2, i+1, r);
      return true;
    }
  }
  return false;
}

// [l, r], inclusive
bool cuty(int x1, int y1, int x2, int y2, int l, int r) {
  sort(rects+l, rects+r+1, cmpy);
  int mid_y = y1, area = 0;
  for (int i = l; i < r; ++i) {
    area += calculate_area(rects[i]);
    mid_y = max(mid_y, rects[i].y2);
    if (area == (mid_y-y1)*(x2-x1)) {
      Solve(x1, y1, x2, mid_y, l, i);
      Solve(x1, mid_y, x2, y2, i+1, r);
      return true;
    }
  }
  return false;
}

void Solve(int x1, int y1, int x2, int y2, int l, int r) {
  int cur = (x2-x1)*(y2-y1);
  if (cutx(x1, y1, x2, y2, l, r)) return;
  if (cuty(x1, y1, x2, y2, l, r)) return;
  // can not cut, record the maxmium value.
  ans = max(ans, cur);
}

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> l >> r;
    cin >> n;
    for (int i = 0; i < n; ++i) 
      cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
    ans = 0;
    Solve(0, 0, l, r, 0, n-1);
    cout << ans << endl;
  }
  return 0;
} 
