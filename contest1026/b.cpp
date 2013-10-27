#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;
int a[N];
int n;
int main() {
  //freopen("test.txt", "r", stdin);

  int k, q;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a, a+n);
    string s;
    cin >> s;
    cin >> k;
    for (int i = 0; i < k; ++i) {
      cin >> q;
      cout << a[q-1] << endl;
    }
  }
  return 0;
} 
