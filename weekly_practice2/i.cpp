#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int skew(double a, double b) {
  double h = 1;
  int type1_row = 0, type2_row = 0;
  for (int i = 0; h < a;++i) {
    if (i%2 == 0)
      type1_row++; 
    else
      type2_row++;
    h += sqrt(3)/2.0;
  }
  int second_row_num = (int)b - 1; 
  if (b - (int)b >= 0.5)
    second_row_num++;
  return type2_row*second_row_num+type1_row*(int)b;
}

int main() {
  //freopen("test.txt", "r", stdin);

  double a, b;
  while (cin >> a >> b) {
    int grid_sum = (int)a*(int)b;
    int skew_sum = max(skew(a, b), skew(b, a));
    if (grid_sum >= skew_sum)
      cout << grid_sum << " grid" << endl;
    else
      cout << skew_sum << " skew" << endl;
  }
  return 0;
} 
