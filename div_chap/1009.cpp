#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename Comparable>
int binarySearch(const vector<Comparable> table, int bot, int top, const Comparable &x)
{
  int l = bot, r = top;
  int pos = -1;
  while (l <= r) {
    int mid = (l+r)/2;
    if (table[mid] == x) {
      pos = mid;
      l = mid+1;
    } else if (table[mid] < x) {
      l = mid+1;
    } else {
      r = mid-1;
    }
  }

  return pos;
}

int main() {
  //freopen("test.txt", "r", stdin);
  int a[ ] = {0,1, 1,3,3,3,6};
  vector<int> v(a,a+7);
  cout << binarySearch(v, 0, v.size()-1, 0) << endl;  // 输出5
  cout << binarySearch(v, 0, v.size()-1, 7) << endl;  //输出-1
  
  return 0;
} 
