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

const int N = 1000;
int n, m, cnt;
int maze[N][N];

bool fill(int ii, int jj) {
  maze[ii][jj] = cnt++;
  // up line
  for (int j = jj-1; j > n-1-jj; --j)
    maze[ii][j] = cnt++;
  // left
  for (int i = ii; i < jj; ++i)
    maze[i][ii] = cnt++;
  // bottom
  for (int j = ii; j < jj; ++j)
    maze[jj][j] = cnt++;
  // line
  for (int i = jj; i > ii; --i)
    maze[i][jj] = cnt++;
}

int main() {
  freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    //cnt = n*n;
    cnt = 1;
    for (int i = 0, j = n-1; i < n/2+1; ++i, --j) {
      fill(i, j);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        printf("%3d ", maze[i][j]);
      cout << endl;
    }
  }
  return 0;
}                                 
