#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

int a[N];

int main() {
  //freopen("test.txt", "r", stdin);

  int n1, n2, num;
  while (cin >> n1) {
    for (int i = 0; i < n1; ++i)
      cin >> a[i];
    set<int> b;
    cin >> n2;
    for (int j = 0; j < n2; ++j) {
      cin >> num;
      b.insert(num);
    }

    string ans = "NO";
    for (int i = 0; i < n1; ++i)
      if (b.find(10000-a[i]) != b.end()) {
        ans = "YES";
        break;
      }
    cout << ans << endl;
  }
  return 0;
} 
