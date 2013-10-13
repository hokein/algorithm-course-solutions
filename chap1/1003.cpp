#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;
const double epos = 10e-10;
int period[N], sum[N];
pair<int, int> p[N];

bool is_equal(double a, double b) {
  if (a < b) swap(a, b);
  return a-b < epos; 
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  int size1 = a.second - a.first + 1;
  int size2 = b.second - b.first + 1;
  int sum1 = sum[a.second]-sum[a.first-1];
  int sum2 = sum[b.second]-sum[b.first-1];
  if (!is_equal(sum1*1.0/size1, sum2*1.0/size2))
    return (sum1*1.0/size1) > (sum2*1.0/size2); 

  if (size1 != size2)
    return size1 > size2;
  return a.first < b.first;
}

int main() {
  //freopen("test.txt", "r", stdin);
  int t, cases = 0;
  cin >> t;
  while (t--) {
    int n, request_size, mini_num;
    cin >> n >> request_size >> mini_num;
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> period[i];
      sum[i] = sum[i-1] + period[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i+mini_num-1; j <= n; ++j)
        p[cnt++] = make_pair<int, int>(i, j); 
    }
    
    sort(p, p+cnt, cmp);
    cout << "Result for run " << ++cases << ":" << endl;
    for (int i = 0; i < min(request_size, cnt); ++i)
      cout << p[i].first << "-" << p[i].second << endl; 

  }
  return 0;
} 
