#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
int n;

inline bool isvalid(ll v) {
  ll tmp = v;
  while (tmp%2 == 0) {
    tmp/=2;
  }
  while (tmp%3 == 0) {
    tmp/=3;
  }
  while (tmp%5 == 0) {
    tmp/=5;
  }
  return tmp == 1;
}

void solve() {
  int cnt = 0;
  for (ll i = 2; ;++i) {
    if (isvalid(i)) {
      cnt++;
      if (cnt == n-1) {
        cout << i << endl;
        return;
      }
    }
  }
}


int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    solve();
  }
  //ll pow2 = 1;
  //ll pow3 = 1;
  //ll pow5 = 1;
  //int n;

  //while (cin >> n) {
    //pow3 = 1;
  //for (int j = 0; j < n; ++j)
    //pow3 *= 5LL;
  //cout << pow3 << endl;
  //}
  //for (int i = 0; i < 60; ++i) {
    //for (int j = 0; j < 39; ++j) {
      //for (int k = 0; k < 26; ++k) {

      //}
    //} 
  //}
  return 0;
} 
