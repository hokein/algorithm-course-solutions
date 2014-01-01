#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;
const int INF = 100000000;

struct Land {
  int importance;
  int len;
  int x, y;
};

Land land[N];
int L, A, m, x[N], y[N];
int cntx, cnty;

bool is_in_park(const Land& park, const Land& p) {
  int x1 = park.x, x2 = park.x+park.len;
  int y1 = park.y, y2 = park.y+park.len;

  if (p.x >= x1 && p.x < x2) {
    if (p.y >= y1 && p.y < y2) return true;
    if (p.y < y1 && p.y+p.len > y1) return true;
  }
  if (p.x < x1 && p.x+p.len > x1) {
    if (p.y <= y1 && p.y+p.len > y1) return true;
    if (p.y >= y1 && p.y < y2) return true;
  }
  return false; 
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> L >> A) {
    cntx = cnty = 0;
    x[cntx++] = 1;
    y[cnty++] = 1;
    cin >> m;
    int size = 0;
    for (int i = 0; i < m; ++i) {
      cin >> land[i].importance >> land[i].len >> land[i].x >> land[i].y;
      x[cntx++] = land[i].x;
      x[cntx++] = land[i].x+land[i].len;
      y[cnty++] = land[i].y;
      y[cnty++] = land[i].y+land[i].len;
    }
    
    sort(x, x+cntx);
    sort(y, y+cnty);
    cntx = unique(x, x+cntx)-x;
    cnty = unique(y, y+cnty)-y;

    int ans = INF;
    for (int i = 0; i < cntx; ++i)
      for (int j = 0; j < cnty; ++j) {
        Land park;
        park.x = x[i];
        park.y = y[j];
        park.len = A;
        if (park.x+park.len <= 1+L && park.y+park.len <= 1+L) {
          int importance = 1;
          for (int k = 0; k < m; ++k) {
            if (is_in_park(park, land[k]))
              importance = max(importance, land[k].importance);
          }
          ans = min(ans, importance);
        }
      }

    if (ans <= 100)
      cout << ans << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
