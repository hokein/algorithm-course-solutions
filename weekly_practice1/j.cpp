#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  //freopen("test.txt", "r", stdin);

  int a, b;
  while (cin >> a >> b) {
    cout << a+b-1-a << " " << a+b-1-b << endl;
  }
  return 0;
} 
