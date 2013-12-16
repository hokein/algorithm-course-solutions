#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int kMax = 100;
const int kRow = 8;
const int kCol = 8;
bool vis[kMax][kMax];
int times[kMax][kMax];

P parent[kMax][kMax];
P start_pos;

int dx[] = {-2, -1, 2, 1, 1, 2, -2, -1};
int dy[] = {-1, -2, 1, 2, -2, -1, 1, 2};

void output_path(P p, int steps) {
  if (steps == 0)
    return;
  output_path(parent[p.first][p.second], steps-1);
  if (steps > 1)
    cout << " ";
  cout << p.first*kCol + p.second + 1;
}

inline int calculate(const P& p) {
  int times = 0;
  for (int i = 0; i < 8; ++i) {
    int x = p.first + dx[i];
    int y = p.second + dy[i];
    if (x >= 0 && x < kRow && y >= 0 && y < kCol && !vis[x][y])
      ++times;
  }
  return times;
}

bool cmp(const P& p1, const P& p2) {
  return times[p1.first][p1.second] < times[p2.first][p2.second];
}

bool dfs(P p, int steps) {
  if (steps == kRow*kCol) {
    output_path(p, steps);
    cout << endl;
    return true;
  }
  vector<P> v;
  for (int i = 0; i < 8; ++i) {
    int x = p.first + dx[i];
    int y = p.second + dy[i];
    if (x >= 0 && x < kRow && y >= 0 && y < kCol && !vis[x][y]) {
      v.push_back(P(x, y));
      times[x][y] = calculate(P(x, y));
    }
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); ++i) {
    vis[v[i].first][v[i].second] = 1;
    parent[v[i].first][v[i].second] = p;
    if (dfs(v[i], steps+1))
      return true;
    vis[v[i].first][v[i].second] = 0;
  }
  return false;
}

int main() {
  freopen("test.txt", "r", stdin);
  int n;
  while (cin >> n) {
    if (n == -1)
      break;
    --n;
    start_pos = P(n/kCol, n%kCol);
    memset(vis, 0, sizeof(vis));
    vis[start_pos.first][start_pos.second] = 1;
    dfs(start_pos, 1);
  }
  return 0;
} 
