#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ll;

ll factorial(int n, int k) {
  ll ans = 1;
  if (n%k == 0) {
    for (int i = n; i >= k; i-=k)
      ans *= (ll)i;
  }
  else {
    for (int i = n; i >= n%k; i-=k)
      ans *= (ll)i;
  }
  return ans;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  string s;
  while (cin >> n >> s) {
    cout << factorial(n, s.size()) << endl;
  }
  return 0;
} 
