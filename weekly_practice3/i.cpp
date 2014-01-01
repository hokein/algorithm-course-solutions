#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;

int c[N], n, b[N], p_select[N], ans, rank[N], year[N];
bool bigger[N][N];

bool isvalid(int n) {
  for (int i = 1; i < n; ++i)
    if (!(b[p_select[i]] < b[p_select[i-1]]
          && c[p_select[i]] < c[p_select[i-1]]))
      return false;
  return true;
}
void dfs(int pos, int cnt) {
  if (!isvalid(cnt))
    return;
  ans = ans>cnt?ans:cnt;
  if (pos >= n) {
    //ans = ans>cnt?ans:cnt;
    return;
  }
  p_select[cnt] = pos;
  dfs(pos+1, cnt+1);
  dfs(pos+1, cnt);
}
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 1; i <= n; ++i) {
      cin >> c[i]; // event i happen in c[i] year
      rank[c[i]] = i;
    }
    
    while (cin >> b[1]) {
      ans = 0;
      year[b[1]] = 1;
      for (int i = 2; i <= n; ++i) {
        cin >> b[i]; // event i happen in b[i] year
        year[b[i]] = i;
      }

      int dp[N] = {0};
      for (int i = 0; i <= n; ++i)
        dp[i] = 1;
      int ans = 1;
      // enum years
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
          if (c[year[j]] < c[year[i]]) {
            dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);
          }
        }
      }
      cout << ans << endl;
      //dfs(0, 0);
      //cout << ans << endl;
    }
    //memset(bigger, 0, sizeof(bigger));
    //for (int i = 1; i <= n; ++i)
      //for (int j = i+1; j <= n; ++j) {
        //if (c[i] > c[j])
          //bigger[c[i]][c[j]] = 1; 
        //else
          //bigger[c[j]][c[i]] = 1;
      //}

    //while (cin >> b[1]) {
      //for (int i = 2; i <= n; ++i)
        //cin >> b[i];
      //int ans = 0;
      //int dp[N][N] = {0};
      //for (int i = 1; i <= n; ++i)
        //for (int j = 1; j <= n; ++j) {
          //dp[i][j] = max(dp[i-1][j-1]+bigger[c[i]][b[j]], max(dp[i][j-1], dp[i-1][j]));
          //ans = max(dp[i][j], ans);
        //}
      //cout << ans << endl;

    //}
  }
  return 0;
} 
