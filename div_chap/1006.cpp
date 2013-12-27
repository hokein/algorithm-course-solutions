#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100005;

int n, m;
ll num[N];

bool is_valid(ll maxx) {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    ll sum = 0;
    ++cnt;
    for (int j = i; j < n; ++j) {
      if (sum+num[j] > maxx) {
        if (i == j)
          return false;
        break;
      }
      sum += num[j];
      i = j;
    }
  }
  return cnt <= m;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> m) {
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> num[i];
      sum += num[i];
    }
    ll l= 0, r = sum, ans;
    while (l <= r) {
      ll mid = l + (r-l)/2;
      if (is_valid(mid)) {
        ans = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    cout << ans << endl;
  }
  return 0;
} 
