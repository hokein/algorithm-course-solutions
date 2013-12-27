#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 102;

bool maze[N][N];
int dp[N][N][N];
int n, m, l;

int main() {
  //freopen("test.txt", "r", stdin);

  //cin >> n >> m >> l;
  scanf("%d%d%d", &n, &m, &l);
  {
    int a, b;
    //memset(dp, 0, sizeof(dp));
    //memset(maze, 0, sizeof(maze));
    for (int i = 0; i < m; ++i) {
      //cin >> a >> b;
      scanf("%d%d", &a, &b);
      maze[a][b] = 1; 
      ++dp[a][b][1];
    }
    
    for (int z = 2; z <= l; ++z)
      for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
          if (dp[i][k][z-1] != 0)
            for (int j = 1; j <= n; ++j)
              dp[i][j][z] += dp[i][k][z-1]*dp[k][j][1];
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      scanf("%d%d", &a, &b);
      printf("%ld\n", dp[a][b][l]);
    }
  }
  return 0;
} 
