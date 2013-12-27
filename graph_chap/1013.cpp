#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int N = 105;
const int INF = 1000000000;

int n, m, maze[N][N], d[N*N];
bool vis[N*N];

P st, ed;
vector<P> cross[N*N]; // <v, len>

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
      for (int j = 0; j < m; ++j) {
        cin >> maze[i][j];
        cross[i*m+j].clear();
      }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        int v1 = i*m+j;
        if (i > 0) {
          int v = (i-1)*m+j;
          cross[v].push_back(P(v1, maze[i][j]));
          cross[v1].push_back(P(v, maze[i-1][j]));
        }
        if (j > 0) {
          int v = i*m + j-1;
          cross[v].push_back(P(v1, maze[i][j]));
          cross[v1].push_back(P(v, maze[i][j-1]));
        }
      }
    cin >> st.first >> st.second;
    st.first--; st.second--;
    cin >> ed.first >> ed.second;
    ed.first--; ed.second--;

    int starting = st.first*m + st.second;
    int ending = ed.first*m + ed.second;
    for (int i = 0; i < N*N; ++i)
      d[i] = INF;
    memset(vis, 0, sizeof(vis));

    priority_queue<P, vector<P>, greater<P> > q;
    d[starting] = maze[st.first][st.second];
    q.push(P(d[starting], starting)); // <len, v>
    while (!q.empty()) {
      int u = q.top().second;
      q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (int j = 0; j < cross[u].size(); ++j) {
        int v = cross[u][j].first;
        int len = cross[u][j].second;
        if (d[v] > d[u]+len) {
          d[v] = d[u]+len;
          q.push(P(d[v], v));
        }
      }
    }
    
    cout << d[ending] << endl;
  }
  return 0;
} 
