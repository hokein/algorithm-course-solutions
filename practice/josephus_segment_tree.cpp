// 
// n=7, k=3
// 0 1 2 3 4 5 6
//     |     |
//
// Killed person number | index(cnts)
//   2   3 = 2+1 = (0+k-1)+1
//   5   5 = 4+1 = (2+k-1)+1
//
//   i   (pos[i-1]+k-1)%n+1
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000;

int cnts[N<<2], n, k;

void pushup(int rt) {
  cnts[rt] = cnts[rt<<1] + cnts[(rt<<1)+1];
}

// build [l, r]
void build(int l, int r, int rt) {
  if (l == r) {
    cnts[rt] = 1; // record cnt of number l.
    return;
  }
  int m = (l+r) >> 1;
  build(l, m, rt<<1);
  build(m+1, r, (rt<<1)+1);
  pushup(rt); // sum up subtree cnts.
}

// query the number of cnts No.k.
int query(int k, int l, int r, int rt) {
  if (l == r)
    return l;
  int m = (l+r) >> 1;
  if (cnts[rt<<1] >= k)
    return query(k, l, m, rt<<1);
  return query(k-cnts[rt<<1], m+1, r, (rt<<1)+1) ;
}

// remove the node of cnt No.k.
void update(int k, int l, int r, int rt) {
  if (l == r) {
    cnts[rt] = 0;
    return;
  }
  int m = (l+r) >> 1;
  if (cnts[rt<<1] >= k)
    update(k, l, m, rt<<1);
  else
    update(k-cnts[rt<<1], m+1, r, (rt<<1)+1);
  pushup(rt);
}

void remove(int k) {
  update(k, 0, n-1, 1);
}

int find(int k) {
  return query(k, 0, n-1, 1);
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> k) {
    // [0, ..., n-1]
    build(0, n-1, 1);

    int pos = 0;
    for (int i = 0; i < n; ++i) {
      // cnts[1]: remained number of people
      // pos: the current begin position in cycle of cnts[1] people.
      // (pos+k-1) next killed people position.
      // Since we reduce one person each time, and begin from the killed people.
      // the skip steps is k-1, not k.
      pos = (pos+k-1)%cnts[1];
      cout << find(pos+1)+1 << " ";
      remove(pos+1);
    }
    cout << endl;
  }

  return 0;
} 
