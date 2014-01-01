#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  while (cin >> n) {
    int sum = 0;
    if (n <= 0) {
      for (int i = n; i <= 1; ++i)
        sum += i;
    } else {
      for (int i = 1; i <= n; ++i)
        sum += i;
    }
    cout << sum << endl; 
  }
  return 0;
} 
