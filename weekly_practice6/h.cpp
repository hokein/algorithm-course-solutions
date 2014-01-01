#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMaxN = 1000;

bool is_prime[kMaxN];
vector<int> primes;
map<int, int> cnts; // primes_index, nums;

void make_prime() {
  memset(is_prime, 1, sizeof(is_prime));
  is_prime[1] = 0;
  for (int i = 2; i < kMaxN; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = 2*i; j < kMaxN; j+=i)
        is_prime[j] = 0;
    }
  }
}

void cal_factors(int n) {
  for (int i = 0; i < primes.size(); ++i) {
    int cnt = 0;
    int prime_num = primes[i];
    while (n%prime_num == 0) {
      ++cnt;
      n/=prime_num;
    }
    if (cnt > 0) {
      if (cnts.find(i) != cnts.end())
        cnts[i]+=cnt;
      else
        cnts[i] = cnt;
    }
  }
}

int main() {
  //freopen("test.txt", "r", stdin);

  make_prime();

  int n;
  while (cin >> n && n) {
    cnts.clear();
    for (int i = 2; i <= n; ++i)
      cal_factors(i);

    printf("%3d! =", n);
    int cnt = 0;
    for (map<int, int>::iterator it = cnts.begin(); it != cnts.end(); ++cnt) {
      if (cnt > 0 && cnt % 15 == 0)
        printf("\n      ");
      if (it->first == cnt) {
        printf("%3d", it->second);  
        ++it;
      } else {
        printf("%3d", 0);
      }
    }
    printf("\n");
  }
  return 0;
} 
