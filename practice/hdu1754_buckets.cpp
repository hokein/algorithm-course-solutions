#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 400005;
const int B = 500;

vector<int> buckets[N/B];
int a[N], buckets_max[N/B];
int n, m;

int main() {
  //freopen("test.txt", "r", stdin);

  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < N/B; ++i)
      buckets[i].clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      buckets[i/B].push_back(a[i]);
    }

    for (int i = 0; i <= n/B; ++i) {
      buckets_max[i] = 0;
      for (int j = 0; j < buckets[i].size(); ++j)
        buckets_max[i] = max(buckets_max[i], buckets[i][j]);
    }

    char c;
    int l, r;
    for (int i = 0; i < m; ++i) {
      getchar();
      scanf("%c%d%d", &c, &l, &r);
      --l;
      if (c == 'U') {
        a[l] = r;
        buckets[l/B][l%B] = r;
        buckets_max[l/B] = 0;
        for (int i = 0; i < buckets[l/B].size(); ++i)
          buckets_max[l/B] = max(buckets_max[l/B], buckets[l/B][i]);
      } else if (c == 'Q') {
        // query [l, r)
        int tl = l, tr = r;
        int ans = a[l];
        while (tl < tr && tl%B != 0) ans = max(ans, a[tl++]);
        while (tl < tr && tr%B != 0) ans = max(ans, a[--tr]);

        for (int j = tl; j < tr; j+=B)
          ans = max(ans, buckets_max[j/B]);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
} 
