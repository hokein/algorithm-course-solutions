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
int num[N];
ll dp[N][N];
int n;

ll DP(int x, int y) {
  if (dp[x][y] != -1)
    return dp[x][y];
  if (x == y) return dp[x][y] = 0;
  for (int k = x; k < y; ++k)
    dp[x][y] = max(dp[x][y],
                   DP(x, k)+DP(k+1,y)
                   +1LL*matrix[x].first*matrix[k].second*matrix[y].second);
  return dp[x][y];
}

int main() {
  freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 1; i <= n; ++i)
      cin >> num[i];
    for (int i = 1; i < n; ++i)
      matrix[i] = P(num[i],num[i+1]);
    matrix[n] = P(num[n], num[1]);

    for (int i = 1; i <= n; ++i)
      matrix[n+i] = matrix[i];
    memset(dp, -1, sizeof(dp));
    ll maxx = 0;
    for (int i = 1; i <= n; ++i)
      maxx = max(maxx, DP(i,i+n-1));
    cout << maxx << endl;
  }
  return 0;
} 
