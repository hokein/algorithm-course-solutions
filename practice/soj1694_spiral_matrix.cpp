//  (ii,ii) ... (ii, jj)
//     .           .
//     .           .
//     .           .
//  (jj,ii) ... (jj, jj)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n, m, cnt, ans_x, ans_y;

bool fill(int m, int ii, int jj) {
  // In case center
  if (cnt == m) {
    ans_x = ii;
    ans_y = jj;
  }

  // up
  for (int j = jj-1; j > n-1-jj; --j) {
    cnt--;
    if (cnt == m) {
      ans_x = ii;
      ans_y = j;
    }
  }
  // left
  for (int i = ii; i < jj; ++i) {
    cnt--;
    if (cnt == m) {
      ans_x = i;
      ans_y = ii;
    }
  }
  // bottom
  for (int j = ii; j < jj; ++j) {
    cnt--;
    if (cnt == m) {
      ans_x = jj;
      ans_y = j;
    }
  }
  // right
  for (int i = jj; i > ii; --i) {
    cnt--;
    if (cnt == m) {
      ans_x = i;
      ans_y = jj;
    }
  }
}

int find_sqare(int m) {
  if (m == 1)
    return 1;
  for (int i = 3; ; i+=2)
    if (i*i >= m && (i-2)*(i-2) < m)
      return i*i;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    cnt = n*n;
    ans_x = -1;
    int min_square = find_sqare(m);
    int len = n;
    // fill from upper_right corner.
    for (int i = 0, j = n-1; i < n/2+1 && ans_x == -1; ++i, --j) {
      if (cnt == min_square)
        fill(m, i, j);
      else {
        cnt -= len*4-4;
        len -= 2;
      }
    }
    cout << ans_x+1 << " " << ans_y+1 << endl;
  }
  return 0;
} 
