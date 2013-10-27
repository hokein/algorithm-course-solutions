#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1005;

int data[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n-1; ++i)
      cout << i << " "; 
    cout << n-1 << endl;
  }
  return 0;
} 
