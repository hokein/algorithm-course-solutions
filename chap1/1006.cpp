#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000;

string s[N];

bool cmp(const string& a, const string& b) {
  return a+b < b+a;
}
int main() {
  //freopen("test.txt", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> s[i];
    sort(s, s+n, cmp);
    for (int i = 0; i < n; ++i)
      cout << s[i];
    cout << endl;
  }
  return 0;
} 
