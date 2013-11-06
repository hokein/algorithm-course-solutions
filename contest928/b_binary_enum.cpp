// divide the pile into two parts(n/2).
// Enum the divided part, O(2^(n/2)), then combine the two parts. 
// find the minimal value.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 2048;
const int INF = 1000000000;

int n, w[N];
vector<int> subsum1, subsum2;

void calculat_subsum(int len, int pos, vector<int>* subsum) {
  subsum->clear();
  for (int i = 0; i < (1<<len); ++i) {
    int tmp = i;
    int sum1 = 0, sum2 = 0;
    for (int j = 0; j < len; ++j)
      if (tmp & (1<<j)) {
        sum1 += w[pos+j];
      } else {
        sum2 += w[pos+j];
      }
    subsum->push_back(sum1-sum2);
  }
}

int solve() {
  int len = n/2;
  calculat_subsum(len, 0, &subsum1);
  calculat_subsum(n-len, len, &subsum2);
  // combine
  sort(subsum1.begin(), subsum1.end());
  sort(subsum2.begin(), subsum2.end());
  int ans = INF;
  int pos1 = 0, pos2 = subsum2.size()-1;
  while (pos1 < subsum1.size() && pos2 >= 0) {
    int value = subsum1[pos1]+subsum2[pos2];
    ans = min(ans, value>0?value:-value);
    if (value >= 0) {
      --pos2;
    } else {
      ++pos1;
    } 
  }
  return ans;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> w[i];
      sum += w[i];
    }
    cout << solve() << endl;
  }
  return 0;
} 
