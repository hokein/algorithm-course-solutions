#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int kMax = 2000000;

bool is_prime[kMax];
int length[kMax];
vector<int> primes;

void make_prime() {
  memset(is_prime, true, sizeof(is_prime));
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
  memset(length, 0, sizeof(length));
  for (int i = 1; i < primes.size(); ++i) {
    length[primes[i-1]] = length[primes[i]] = 0;
    for (int j = primes[i-1]+1; j < primes[i]; ++j)
      length[j] = primes[i]-primes[i-1];
  }
  int v;
  while (scanf("%d", &v) && v) {
    printf("%d\n", length[v]);
  }
  return 0;
} 
