#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;
int q[N], n, k;

int solve() {
  for (int i = 0; i < n; ++i)
    q[i] = i;
  
  int people = n, pos = -1;
  while (people > 1) {
    int cnt = 0;
    // find being killed person.
    while (cnt < k) {
      pos = (pos+1)%n;
      if (q[pos] != -1)
        ++cnt;
    }

    int killed = pos;
    q[killed] = -1;
    cnt = 0;
    // find next person to kill the killed person
    while (cnt < k) {
      pos = (pos+1)%n;
      if (q[pos] != -1)
        ++cnt;
    }
    // return to the place.
    q[killed] = q[pos];
    q[pos] = -1;
    pos = killed;
    --people;
  }
  int ans = 0;
  while (q[ans] == -1) ++ans;
  ++q[ans];
  cout << (n-q[ans]+1)%n+1 << endl;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> k) {
    if (k == 0 && n == 0)
      break;
    solve();
  }

  return 0;
} 
