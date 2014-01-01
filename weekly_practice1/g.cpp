#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <queue>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 2000;

int main() {
  //freopen("test.txt", "r", stdin);

  int n, v;
  while (cin >> n) {
    set<int> sons[N];
    for (int i = 1; i <= n; ++i) {
      while (cin >> v && v) {
        sons[i].insert(v);
      }
    }

    bool in_queue[N] = {0};
    queue<int> no_son;
    for (int i = 1; i <= n; ++i)
      if (sons[i].size() == 0) {
        no_son.push(i);
        in_queue[i] = 1;
      }
    vector<int> path;
    while (!no_son.empty()) {
      int cur = no_son.front();
      path.push_back(cur);
      no_son.pop();
      for (int i = 1; i <= n; ++i) {
        sons[i].erase(cur);
        if (!in_queue[i] && sons[i].empty()) {
          no_son.push(i);
          in_queue[i] = 1;
        }
      }
    }
    for (int i = path.size()-1; i > 0; --i)
      cout << path[i] << " ";
    cout << path[0] << endl;
  }
  return 0;
} 
