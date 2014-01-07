#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <deque>
#include <map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000;
map<string, int> name2ids;
int parents[N];
int cnt;

// check whether q is p ancestors. 
bool is_parent(string p, string q, int* steps) {
  *steps = 0;
  int pos1 = name2ids[p];
  int pos2 = name2ids[q];
  while (parents[pos1]) {
    if (parents[pos1] == pos2)
      return true;
    ++(*steps);
    pos1 = parents[pos1];
  } 
  return false;
}

bool is_cousin(string& p, string& q, int* k, int *j) {
  *k = *j = 0;
  deque<int> path1, path2;
  for (int i = name2ids[p]; i; i = parents[i])
    path1.push_front(i);
  for (int i = name2ids[q]; i; i = parents[i])
    path2.push_front(i);

  int lca_pos = -1;
  for (int i = 0; i < min(path1.size(), path2.size()); ++i)
    if (path1[i] == path2[i]) {
      lca_pos = i;
    } else {
      break;
    }
  if (lca_pos == -1) return false;
  int n = path1.size()-1-(lca_pos+1);
  int m = path2.size()-1-(lca_pos+1);
  *k = min(n, m);
  *j = n>m?n-m:m-n;
  return true;
}

int main() {
  //freopen("test.txt", "r", stdin);

  string p, q;
  cnt = 1;
  memset(parents, 0, sizeof(parents));
  while (cin >> p >> q) {
    if (p == "no.child")
      break;
    if (name2ids.find(p) == name2ids.end())
      name2ids[p] = cnt++;
    if (name2ids.find(q) == name2ids.end())
      name2ids[q] = cnt++;
    parents[name2ids[p]] = name2ids[q]; 
  }
  while (cin >> p >> q) {
    int steps, k, j;
    if (name2ids.find(p) == name2ids.end()
        || name2ids.find(q) == name2ids.end())
      cout << "no relation" << endl;
    else if (is_parent(q, p, &steps)) {
      while (steps--) {
        if (steps == 0)
          cout << "grand ";
        else
          cout << "great ";
      }
      cout << "parent" << endl;
    } else if (is_parent(p, q, &steps)) {
      while (steps--) {
        cout << (steps==0?"grand ":"great ");
      }
      cout << "child" << endl;
    } else if (parents[name2ids[p]] && parents[name2ids[p]] == parents[name2ids[q]]) {
      cout << "sibling" << endl;
    } else if (is_cousin(p, q, &k, &j)) {
      cout << k << " cousin";
      if (j) {
        cout << " removed " << j;
      }
      cout << endl;
    } else {
      cout << "no relation" << endl;
    }
  }
  return 0;
} 
