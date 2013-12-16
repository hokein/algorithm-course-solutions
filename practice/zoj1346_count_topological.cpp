// Calculate the number of ways of topological sequence.
//
// Solution: dp 
//  dp{S} = sum (dp{S - a[i]}), S = {a[0], a[1], ..., a[n]},
//  there is no element b[i] in {S-a[i]}, which a[i] has dependency on b[i].
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 16;
const int kMax = (1<<16) + 5;

int n, dp[kMax];
bool maze[N][N];
map<string, int> mpname;

int len(int value) {
  int ans = 0;
  while (value) {
    ans += value%2;
    value /= 2;
  }
  return ans;
}

bool isvalid(int pos, int value) {
  for (int i = 0; value >> i; ++i) {
    if (i == pos) continue;
    if ((value>>i)&1) {
      if (maze[i][pos])
        return false;
    }
  }
  return true;
}

int DP(int value) {
  if (len(value) == 1) {
    return dp[value] = 1;
  }

  if (dp[value] != 0) return dp[value];
  for (int i = 0; (value >> i); ++i) {
    if ((value>>i)&1) {
       if (isvalid(i, value))
         dp[value] += DP(value&(~(1<<i)));
    }
  }

  return dp[value];
}

int main() {
  //freopen("test.txt", "r", stdin);

  string a, b;
  while (cin >> n) {
    int cnt = 0;
    mpname.clear();
    memset(dp, 0, sizeof(dp));
    memset(maze, 0, sizeof(maze));
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      if (mpname.find(a) == mpname.end()) {
        mpname[a] = cnt++;
      }
      if (mpname.find(b) == mpname.end()) {
        mpname[b] = cnt++;
      }
      maze[mpname[a]][mpname[b]] = 1;
    }
    int state = 0;
    for (int i = 0; i < cnt; ++i) {
      state = (state<<1)+1;
    }

    cout << DP(state) << endl;
  }
  return 0;
} 
