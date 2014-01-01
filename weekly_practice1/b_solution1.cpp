#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int w[25], vis[25], sum, ans, n;

void dfs(int cur_pos, int sum1) {
  if (cur_pos >= n) {
    if (sum-sum1 >= sum1)
      ans = min(ans, sum-2*sum1);
    else 
      ans = min(ans, sum1-(sum-sum1));
    return; 
  }

  dfs(cur_pos+1, sum1+w[cur_pos]);
  dfs(cur_pos+1, sum1);
}

int main() {
  while (cin >> n) {
    sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> w[i]; 
      sum += w[i];
    }

    ans = sum;
    memset(vis, 0, sizeof(vis));
    dfs(0, 0);
    cout << ans << endl;
  }
  return 0;
} 
