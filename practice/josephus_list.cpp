#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <list>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  freopen("test.txt", "r", stdin);

  int n, k;
  while (cin >> n >> k) {
    list<int> cycle;
    for (int i = 0; i < n; ++i)
      cycle.push_back(i);
    list<int>::iterator it = cycle.begin();
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < k; ++j) {
        ++it;
        if (it == cycle.end())
          it = cycle.begin();
      }
      cout << *it + 1 << " ";
      it = cycle.erase(it);
      if (it == cycle.end()) it = cycle.begin(); // reach end node.
    }
    cout << endl;
  }
  return 0;
} 
