#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

bool isPrime[N];
int prime_nums[N], size;

void make_prime() {
  memset(isPrime, 1, sizeof(isPrime));
  isPrime[1] = 0;
  isPrime[2] = 1;
  size = 0;
  for (int i = 2; i < N; ++i)  {
    if (isPrime[i]) {
      prime_nums[size++] = i;
      for (int j = i+i; j < N; j+=i)
        isPrime[j] = 0;
    }
  }
  //cout << size << endl;
}

int main() {
  //freopen("test.txt", "r", stdin);

  make_prime();
  int n;
  while (cin >> n) {
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      cout << prime_nums[t-1] << endl;
    }
  }
  return 0;
} 
