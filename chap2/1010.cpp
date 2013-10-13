#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

struct Person {
  int id, salary, height;
};

bool cmp(const Person& a, const Person& b) {
  return a.salary < b.salary;
}

Person p[N];
map<int, int> id2index;
int n, m, q, subordinates[N], boss[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &m, &q);
    for (int i = 0; i < m; ++i)
      scanf("%d%d%d", &p[i].id, &p[i].salary, &p[i].height);
    sort(p, p+m, cmp);
    id2index.clear();
    memset(subordinates, 0, sizeof(subordinates));
    memset(boss, 0, sizeof(boss));
    for (int i = 0; i < m; ++i) {
      id2index[p[i].id] = i;
      for (int j = i+1; j < m; ++j) {
        if (p[i].height <= p[j].height) {
          boss[i] = p[j].id;
          subordinates[j]+=subordinates[i]+1; 
          break;
        }
      }
    }
    int id;
    for (int i = 0; i < q; ++i) {
      scanf("%d", &id);
      printf("%d %d\n", boss[id2index[id]], subordinates[id2index[id]]);
    }
  }
  return 0;
} 
