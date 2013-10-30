#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;

struct land {
  int x, y;
  int importance;
  int len;
};

int A, L, M;
land lands[N];
vector<int> x, y;

bool is_in_park(const land& park, const land& p) {
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
    cin >> M;
    x.clear();
    y.clear(); 
    x.push_back(1);
    y.push_back(1);
    for (int i = 0; i < M; ++i) {
      cin >> lands[i].importance >> lands[i].len >> lands[i].x >> lands[i].y;
      x.push_back(lands[i].x);
      y.push_back(lands[i].y);
      x.push_back(lands[i].x+lands[i].len);
      y.push_back(lands[i].y+lands[i].len);
    }

    int ans = 100000000;
    for (int i = 0; i < x.size(); ++i)
      for (int j = 0; j < y.size(); ++j) {
        land park;
        park.x = x[i];
        park.y = y[j];
        park.len = A;
        if (park.x + park.len <= 1+L && park.y + park.len <= 1+L) {
          int importance = 1;
          for (int k = 0; k < M; ++k) {
            if (is_in_park(park, lands[k])) {
              importance = max(importance, lands[k].importance);     
            }
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
