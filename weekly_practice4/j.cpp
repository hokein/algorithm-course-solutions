#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  //freopen("test.txt", "r", stdin);

  int n, a, b;
  while (cin >> n >> a >> b) {
    cout << n*2*a*b << endl;
  }
  return 0;
} 
