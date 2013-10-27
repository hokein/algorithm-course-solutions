#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

int a[N];

int main() {
  //freopen("test.txt", "r", stdin);

  a[0] = 0;
  a[1] = 1;
  for (int i = 1; 2*i+1 < N; ++i) {
    a[2*i] = a[i];
    a[2*i+1] = a[i]+a[i+1];
  }
  
  int q;
  while (cin >> q && q) {
    int maxx = a[0];
    for (int i = 0; i <= q; ++i)
      maxx = maxx>a[i]?maxx:a[i];
    cout << maxx << endl;
  }
  return 0;
} 
