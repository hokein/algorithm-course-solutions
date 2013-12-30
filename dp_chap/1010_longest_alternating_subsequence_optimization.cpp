// Longest Alternating Subsequence
// Variation of LIS.
//
// There is an O(n) solution here.
//
// find a longest subsequence {1, 2, 1, 3, 2, 4}
// x1 < x2 > x3 < x4
// dp[i]: the longest LAS subsequence of sequence [1...n].
//
// dp[i] = 
//  1) dp[i-1] is odd
//       dp[i-1]+1, num[i]>num[i-1]
//       dp[i-1], otherwise.
//  2) dp[i-1] is even
//       dp[i-1]+1, num[i]<num[i-1]
//       dp[i-1], otherwise.
//
// Prove:
//  Suppose dp[i-1] is even.
//  let LAS(a[1..i]) = the LAS of sequence a[1...i].
//  If len(LAS) is even, the next element of LAS is larger than the last one 
//
//  Now need to determine element a[i], there two situations, see below:
//
//  1) if a[i-1] is the last element of LAS(a[1...(i-1)]),
//     only to determine a[i] > a[i-1],
//       if so, dp[i] = dp[i-1]+1,
//       otherwise, dp[i] = dp[i-1], not select a[i].
//
//  2) if a[i-1] is not the last element of LAS(a[1...(i-1)]),
//     there exists j, j < i-1, which a[j] is the last element of LAS(a[1...(i-1)])
//     and a[j] > a[i-1](because len(LAS) is even).
//     We can remove a[j], and replace a[j] with a[i-1], then len(LAS) is unchanged.
//     Than change to situation 1).
//
//  The same as len(LAS) is odd.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;
int num[N], dp[N];
int n;

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      cin >> num[i];
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i-1];
      if (dp[i-1]%2 == 1 && num[i] < num[i-1])
        ++dp[i];
      if (dp[i-1]%2 == 0 && num[i] > num[i-1])
        ++dp[i];
    }

    int maxx = 0;
    for (int i = 1; i <= n; ++i)
      maxx = max(dp[i], maxx);
    cout << maxx << endl;
  }
  return 0;
} 
