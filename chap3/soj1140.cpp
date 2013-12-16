#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMax = 100000;

struct Node {
  int nums;
  int inside, outside;
  int min_id;
};

bool operator<(const Node& a, const Node& b) {
  if (a.nums != b.nums)
    return a.nums > b.nums;
  return a.min_id < b.min_id;
}

vector<int> maze[kMax];
Node subtree[kMax], best;
int remain_total, pivot;

int find_min_id(int x, int parent) {
  int min_id = x;
  for (int i = 0; i < maze[x].size(); ++i) {
    int v = maze[x][i];
    if (v != parent)
       min_id = min(min_id, find_min_id(v, x)); 
  }
  return min_id;
}

void dfs(int x, int parent) {
  subtree[x].nums = 1;
  subtree[x].min_id = x;
  for (int i = 0; i < maze[x].size(); ++i) {
    int v = maze[x][i];
    if (v != parent) {
      dfs(v, x);
      subtree[x].nums += subtree[v].nums;
      subtree[x].min_id = min(subtree[x].min_id, subtree[v].min_id);
    }
  }
  if (x != pivot) {
    subtree[x].inside = x;
    subtree[x].outside = parent;
    if (subtree[x].nums <= remain_total/2)
      best = min(best, subtree[x]);
    Node subtree2;
    subtree2.nums = remain_total-subtree[x].nums;
    subtree2.inside = parent;
    subtree2.outside = x;
    subtree2.min_id = pivot; 
    if (subtree2.nums <= remain_total/2)
      best = min(best, subtree2);
  }
}

int main() {
  //freopen("test.txt", "r", stdin);

  int n, k, a, b;
  while (cin >> n >> k) {
    for (int i = 0; i < kMax; ++i)
      maze[i].clear();
    for (int i = 0; i < n-1; ++i) {
      cin >> a >> b;
      maze[a].push_back(b);
      maze[b].push_back(a);
    }

    remain_total = n;
    vector<int> ans;
    pivot = 1;
    for (int i = 0; i < k-1; ++i) {
      pivot = find_min_id(pivot, -1);
      best.nums = -1;
      dfs(next_id, -1);

      //remove(maze[best.inside].begin(), maze[best.inside].end(), best.outside);
      //maze[best.inside].pop_back();
      //remove(maze[best.outside].begin(), maze[best.outside].end(), best.inside);
      //maze[best.outside].pop_back();
      // remove (best.inside, best.outside), (best.outside, best.inside)
      for (int i = 0; i < maze[best.inside].size(); ++i) {
        if (maze[best.inside][i] == best.outside) {
          maze[best.inside].erase(maze[best.inside].begin()+i);
          break;
        }
      }
      for (int i = 0; i < maze[best.outside].size(); ++i) {
        if (maze[best.outside][i] == best.inside) {
          maze[best.outside].erase(maze[best.outside].begin()+i);
          break;
        }
      }

      ans.push_back(best.nums);
      remain_total -= best.nums;
      pivot = best.outside;
    }
    for (int i = 0; i < ans.size(); ++i)
      cout << ans[i] << " ";
    cout << remain_total << endl;
  }
  return 0;
} 
