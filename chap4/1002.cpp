#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;


int main() {
  //freopen("test.txt", "r", stdin);

  int y;
  while (cin >> y && y) {
    y = (y-1960)/10;
    double val = 4*pow(2, y)*log(2.0);
    double sum = 0;
    int ans = 0;
    for (int i = 1; ; ++i) {
      sum += log(i*1.0);
      if (sum <= val) {
        ans = i;
      } else {
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
} 
