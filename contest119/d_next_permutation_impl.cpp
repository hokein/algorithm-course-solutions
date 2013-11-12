// next_permutation implementation
//
// from last, find i, i+1, a[i] < a[i+1], a[i+1] > a[i+2] > ... > a[n-1]
// from last, find k such a[k] > a[i], swap(a[i], a[k]), and reverse(a[i+1], a[n])
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  //freopen("test.txt", "r", stdin);

  string a;

  while (cin >> a) {
    if (a == "#")
      break;

    bool flag = false;
    for (int k = a.size()-1; k > 0; --k) {
      if (a[k-1] < a[k]) {
        int i = k-1, ii = k;
        for (int j = a.size()-1; ; --j)
          if (a[j] > a[i]) {
            swap(a[i], a[j]);
            reverse(&a[ii], &a[a.size()]);
            break;
          }
        flag = true;
        break;
      }
    }
    if (flag)
      cout << a << endl;
    else
      cout << "No Successor" << endl;
  }
  return 0;
} 
