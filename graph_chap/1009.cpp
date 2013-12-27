#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100005;

vector<int> maze[N];
int n, m, indegrees[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    memset(indegrees, 0, sizeof(indegrees));
    for (int i = 1; i <= n; ++i) {
      maze[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      maze[a].push_back(b);
      ++indegrees[b];
    }
    priority_queue<int, vector<int>, greater<int> > nodes;
    for (int i = 1; i <= n; ++i)
      if (indegrees[i] == 0) {
        nodes.push(i);
      }

    int base = 100;
    vector<int> ans; 
    while (!nodes.empty()) {
      int u = nodes.top();
      nodes.pop();
      ans.push_back(u);
      for (int j = 0; j < maze[u].size(); ++j) {
        int v = maze[u][j];
        --indegrees[v];
        if (indegrees[v] == 0)
          nodes.push(v);
      } 
    }
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
} 


