#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool isvalid(int num, ll n) {
  ll ans = 1;
  while (num) {
    ans *= num%10;
    num/=10;
  }
  return ans == n;
}

int main() {
  //freopen("test.txt", "r", stdin);

  ll n;
  while (cin >> n) {
    int v = 0;
    for (int i = 1; i < 100000000; ++i) {
      if (isvalid(i, n)) {
        cout << i << endl;
        v = 1;
        break;
      }
    }
    if (!v)
      cout << -1 << endl;
  }
  return 0;
} 
