#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
  freopen("test.txt", "r", stdin);

  vector<int> v;
  int n, k;
  while (cin >> n >> k) {
    for (int i = 0; i < n; ++i)
      v.push_back(i);
    int pos = 0;
    for (int i = 0; i < n; ++i) {
      pos = (pos+k-1)%v.size();
      cout << v[pos]+1 << " ";
      v.erase(v.begin()+pos);
    }
    cout << endl;
  }
  return 0;
} 
