#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int kMaxN = 100000;

int height[kMaxN] = {0};

int main() {
  //freopen("test.txt", "r", stdin);
  int l, r, h;
  int max_r = 0, min_l = kMaxN;
  // inverval dyeing 
  while (cin >> l >> h >> r) {
    max_r = max(max_r, r);
    min_l = min(min_l, l);
    for (int i = l; i < r; ++i)
      height[i] = height[i]>h?height[i]:h;
  }
  for (int i = min_l; i < max_r; ++i)
    if (height[i] != height[i-1])
      cout << i << " " << height[i] << " ";
  cout << max_r << " 0" << endl; 
  return 0;
} 
