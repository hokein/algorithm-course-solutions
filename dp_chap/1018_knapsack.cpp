// 有依赖背包
// First: using 01 knapsack to create groups, each group contains[0, V-c[i]] elements,
//        i is the main products.
// Second: using group knapsacks to find the solution.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int kMax = 200005;
const int N = 1000;

int v[N], p[N], q[N], n, m;
vector<int> belongs[N];
vector<P> groups[N];
int dp[kMax];

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    n /= 10;
    for (int i = 0; i < N; ++i) {
      belongs[i].clear();
      groups[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      cin >> v[i] >> p[i] >> q[i];
      v[i] /= 10; // optimize
      if (q[i] != 0) { // accessory 
        belongs[q[i]].push_back(i);
      } else {  // one groups, main 
        groups[i].push_back(P(v[i], v[i]*p[i]));
      }
    }

    // 0-1 knapsack, change to group knapsack.
    for (int i = 1; i <= m; ++i) {
      if (!belongs[i].empty()) {
        int v_max = n-v[i];
        memset(dp, 0, sizeof(dp));
        for (int k = 0; k < belongs[i].size(); ++k) {
          int pos = belongs[i][k];
          for (int j = v_max; j >= v[pos]; --j)
            dp[j] = max(dp[j-v[pos]]+p[pos]*v[pos], dp[j]);
        }
        for (int j = 0; j <= v_max; ++j)
          groups[i].push_back(P(j+v[i], dp[j]+p[i]*v[i])); // (capacity, weight);
      }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; ++i) {
      if (groups[i].empty()) continue;
      for (int j = n; j >= 0; --j)
        for (int k = 0; k < groups[i].size(); ++k) {
          int cc = groups[i][k].first;
          int ww = groups[i][k].second;
          if (j >= cc)
            dp[j] = max(dp[j-cc]+ww, dp[j]); 
        }
    }
    cout << dp[n]*10 << endl;
  }
  return 0;
} 

