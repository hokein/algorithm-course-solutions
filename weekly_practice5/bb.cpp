#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMaxN = 1000;

int st[kMaxN];
string line;

int main() {
  //freopen("test.txt", "r", stdin);

  while (getline(cin, line)) {
    stringstream scin(line);
    int n = 0;
    while (scin >> st[n])
      ++n;
    
    vector<int> ans;
    for (int end = n-1; end > 0; --end) {
      int maxx = st[end], maxx_index = end;
      for (int i = end; i >= 0; --i) {
        if (st[i] > maxx) {
          maxx = st[maxx_index=i];
        }
      }
      if (maxx_index != end) {
        if (maxx_index != 0) {
          ans.push_back(n-1-maxx_index+1);
          reverse(st, st+maxx_index+1);
        }
        reverse(st, st+end+1);
        ans.push_back(n-1-end+1);
      }
    }
    cout << line << endl;
    for (int i = 0; i < ans.size(); ++i)
      cout << ans[i] << " ";
    cout << 0 << endl;
  }
  return 0;
} 
