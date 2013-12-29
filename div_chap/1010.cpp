#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int K = 101;
const int N = 1000002;
const int INF = 1000000000;

short num[K][N], cnt[K];
int n, k;

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &k, &n);
    int v;
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < n; ++j)
        scanf("%hd", &num[i][j]);
      cnt[i] = 0;
    }

    for (int i = 0; i < k*n; ++i) {
      int mini = INF, pos = -1;
      for (int j = 0; j < k; ++j)
        if (cnt[j] < n) {
          if (num[j][cnt[j]] < mini) {
            mini = num[j][cnt[j]];
            pos = j;
          }
        }
      ++cnt[pos];
      printf("%d ", mini);
    }
    printf("\n");
  }
  return 0;
} 
