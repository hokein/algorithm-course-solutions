// testcases:
// 6 4 5 3 2 4 4  : 2
// 4 6 3 1 5 : 3
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1005;
int num[N], dp[N][N], ans = 0, n;
int player1_select[N][N];

int DP(int i, int j) {
  //cout << i <<  " " << j << endl; 
  if (dp[i][j] != -1)
    return dp[i][j];
  if (i == j)
    return dp[i][j] = num[i];
  if (j-i == 1) {
    if (j-i+1 == n) {
      ans = num[i]-num[j];
      if (ans < 0)
        ans = -ans;
    }
    player1_select[i][j] = num[i] > num[j]? i:j; 
    return dp[i][j] = max(num[i], num[j]);
  }

  // player1
  if ((j-i+1)%2 == 0) {
    int max_diff = -1, tmp = -1;
    // playser1 selects num[i]
    if (num[i+1] >= num[j]) { // player2 selects num[i+1]
      tmp = num[i] + DP(i+2, j) - DP(i+1, j); 
      if (max_diff < tmp) { 
        max_diff = tmp;
        dp[i][j] = num[i] + DP(i+2, j);
        player1_select[i][j] = i;
        //dp[i][j] = max(dp[i][j], num[i] + DP(i-2, j) - DP(i-1, j));
      }
    }
    else { // player2 selects num[j]
      tmp = num[i] + DP(i+1, j-1) - DP(i+1, j);
      if (max_diff < tmp) {
        max_diff = tmp;
        dp[i][j] = num[i] + DP(i+1, j-1);
        player1_select[i][j] = i;
      }
    }

    // player1 select num[j]
    if (num[i] < num[j-1]) { // player2 selects num[j-1]
      tmp = num[j] + DP(i, j-2) - DP(i, j-1);
      if (max_diff < tmp) {
        max_diff = tmp;
        dp[i][j] = num[j] + DP(i, j-2); 
        player1_select[i][j] = j;
      }
    }
    else { // player2 selects num[i]
      tmp = num[j] + DP(i+1, j-1) - DP(i, j-1);
      if (max_diff < tmp) {
        max_diff = tmp;
        dp[i][j] = num[j] + DP(i+1, j-1);
        player1_select[i][j] = j;
      }
    }
    if (j-i+1 == n)
      ans = max_diff;
  }
  else {
    if (num[i] >= num[j]) { // player2 selects i
      DP(i+1, j);
      int op1 = player1_select[i+1][j];
      int st = i+1, ed = j;
      if (op1 == i+1)
        st = i+2; 
      else
        ed = j-1;
      dp[i][j] = max(dp[i][j], num[i] + DP(st, ed));
    }
    else { // player2 selects j.
      DP(i, j-1);
      int op1 = player1_select[i][j-1];
      int st = i, ed = j-1;
      if (op1 == i)
        st = i+1;
      else
        ed = j-2;
      dp[i][j] = max(dp[i][j], num[j] + DP(st, ed));
    }
  }

  return dp[i][j];
}

int main() {
  //freopen("test.txt", "r", stdin);

  int cases = 0;
  while (cin >> n && n) {
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      cin >> num[i];
    }
    DP(1, n);
    printf(
        "In game %d, the greedy strategy might lose by as many as %d points.\n",
        ++cases, ans);
  }
  return 0;
} 
