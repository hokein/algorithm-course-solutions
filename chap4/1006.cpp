#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int kMax = 10006;

bool is_prime[kMax];
int cnts[kMax];
int sum[kMax*100];
vector<int> primes;

void make_prime() {
  memset(is_prime, true, sizeof(is_prime));
  primes.push_back(0);
  for (int i = 2; i < kMax; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i+i; j < kMax; j+=i)
        is_prime[j] = false;
    }
  }
}

int main() {
  //freopen("test.txt", "r", stdin);

  make_prime();
  memset(cnts, 0, sizeof(cnts));
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i < primes.size(); ++i) {
    sum[i] = sum[i-1] + primes[i];
  }

  for (int i = 1; i < primes.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (sum[i] - sum[j] < kMax) {
        ++cnts[sum[i]-sum[j]];
      }
    }
  }

  int v;
  while (scanf("%d", &v) && v) {
    printf("%d\n", cnts[v]);
  }
  return 0;
} 
