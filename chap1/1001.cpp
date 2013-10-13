#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;

string num;
int b[N];

int div(string num, int divisor) {
  int dividend = 0;
  for (int i = 0; i < num.size(); ++i) {
    dividend = 10*dividend + num[i]-'0';
    if (dividend >= divisor)
      dividend = dividend%divisor;
  }
  return dividend ;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> b[i];
    cin >> num;
    cout << "(";
    for (int i = 0; i < n; ++i) {
      cout << div(num, b[i]);
      if (i != n-1)
        cout << ",";
    } 
    cout << ")" << endl;
  }
  return 0;
} 
