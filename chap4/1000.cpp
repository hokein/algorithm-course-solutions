#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int sum_of_base(int n, int base) {
  int sum = 0;
  while (n) {
    sum += n%base;
    n /= base;
  }
  return sum;
}

int main() {
  //freopen("test.txt", "r", stdin);

  for (int i = 2992; i < 10000; ++i) {
    if (sum_of_base(i, 10) == sum_of_base(i, 12)
        && sum_of_base(i, 10) == sum_of_base(i, 16))
      cout << i << endl;
  }
  return 0;
} 
