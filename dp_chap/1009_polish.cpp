#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int N = 1000;
const ll INF = 100000000000;
P matrix[N];
int weight[N];
ll dp[N][N];
int n;

ll DP(int x, int y) {
  if (dp[x][y] != -1)
    return dp[x][y];
  if (x == y) return dp[x][y] = 0;
  for (int k = x; k < y; ++k)
    dp[x][y] = max(dp[x][y],
                   DP(x, k)+DP(k+1,y)+ 1LL*weight[x-1]*weight[k]*weight[y]);
  return dp[x][y];
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    // weight: 0 1 2 3
    // matrix:   1 2 3 , matrix1 = (weight[0]*weight[1]), matrix2 = (weight[1]*weight[2])
    for (int i = 0; i < n; ++i)
      cin >> weight[i];
    for (int i = 0; i < n; ++i) // concatenate
      weight[n+i] = weight[i];
    weight[2*n] = weight[0];

    memset(dp, -1, sizeof(dp));
    ll maxx = 0;
    for (int i = 1; i <= n; ++i)
      maxx = max(maxx, DP(i,i+n-1));
    cout << maxx << endl;
  }
  return 0;
} 
