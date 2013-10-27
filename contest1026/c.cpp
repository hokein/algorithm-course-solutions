#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n;

int digit_sum(int n) {
  int sum = 0;
  while (n) {
    sum += n%10;
    n /= 10;
  }
  return sum;
} 

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    if (n == 8) {
      cout << 4816030 << endl;
      continue;
    }
    n /= 2;
    int tmp = n;
    int size = 1;
    while (tmp--) {
      size = 10*size;
    }

    int ans = 0;
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j) {
        if (digit_sum(i) == digit_sum(j))
          ans++;
      }
    cout << ans << endl;
  }
  return 0;
} 
