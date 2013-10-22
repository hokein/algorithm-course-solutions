#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000005;

bool vis[N];

int gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

int main() {
  //freopen("test.txt", "r", stdin);

  ll n;
  while (cin >> n) {
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (ll s = 1; s*s <= n; s+=1) {
      for (int t = 1; t < s && s*s + t*t <= n; t+=1) {
        ll x = s*s - t*t; 
        ll y = 2*s*t;
        ll z = (s*s+t*t); // z*z = x*x + y*y.
        if (gcd(gcd(x, y), z) == 1) // check gcd(a, b, c) == 1
          ans++;
        for (int i = 1; z*i <= n; ++i)
          vis[i*x] = vis[i*y] = vis[i*z] = 1;
      }
    }
    int ans2 = 0;
    for (int i = 1; i <= n; ++i)
      if (!vis[i])
        ans2++;
    cout << ans << " " << ans2 << endl;
  }
  return 0;
} 
