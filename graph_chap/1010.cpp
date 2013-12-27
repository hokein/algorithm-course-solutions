#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 20005;

vector<int> maze[N];
int n, m, indegrees[N], money[N];

int main() {
  //freopen("test.txt", "r", stdin);

  cin >> n >> m;
  {
    memset(indegrees, 0, sizeof(indegrees));
    for (int i = 1; i <= n; ++i) {
      maze[i].clear();
      money[i] = 100;
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      maze[b].push_back(a);
      ++indegrees[a];
    }
    //vector<int> nodes;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
      if (indegrees[i] == 0) {
        q.push(i);
        money[i] = 100;
      }

    int ans = 0, cnt = 0, sum = 0;
    while (!q.empty()) {
      //int u = nodes.back();
      //nodes.pop_back();
      int u = q.front();
      q.pop();
      ++cnt;
      sum += money[u];
      for (int j = 0; j < maze[u].size(); ++j) {
        int v = maze[u][j];
        --indegrees[v];
        if (indegrees[v] == 0) {
          //nodes.push_back(v);
          q.push(v);
          money[v] = money[u] + 1;
        }
      } 
    }
    if (cnt != n) {
      cout << "Poor Xed" << endl;
    } else {
      cout << sum << endl;
    }
  }
  return 0;
} 
