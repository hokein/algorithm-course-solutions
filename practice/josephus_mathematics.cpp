// f(n, k), the person who survives, person number from 0 to n-1.
// f(n, k) = (f(n-1, k)+k)%n
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;
int f[N], n, k;


int cal() {
  f[1] = 0;
  for (int i = 2; i <= n; ++i)
    f[i] = (f[i-1]+k)%i;
  return f[n];
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n >> k) {
    //k = 2;
    cout << cal()+1 << endl;
  }

  return 0;
} 
