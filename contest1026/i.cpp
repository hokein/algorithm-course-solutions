#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  //freopen("test.txt", "r", stdin);

  ll n, m;
  while (cin >> n >> m) {
    cout << n*(m+1) << endl;
  }
  return 0;
} 
