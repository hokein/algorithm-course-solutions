#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;

int n, w[N];

int main() {
  freopen("test.txt", "r", stdin);

  while (cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> w[i];
      sum += w[i];
    }
    int ans = sum;
    for (int j = 0; j < (1<<n); ++j) {
      int sum1 = 0;
      for (int i = 0; j >> i; ++i)
        if (1&(j>>i)) 
          sum1 += w[i]; 
      ans = min(ans, abs(2*sum1-sum));
    }
    cout << ans << endl;
  }
  return 0;
} 
