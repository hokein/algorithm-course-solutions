#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000;

int num[N], n;
int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> num[i];
    sort(num, num+n);
    int ans = 0;
    for (int i = 0; i < n/2+1; ++i) {
      ans += num[i]/2+1;
    }
    cout << ans << endl;
  }
  return 0;
} 
