// Regular problem
// binary
// 1 => (01) : 1
// 2 => (10) : 2
// 3 => (11) : 1
// 4 => (100) : 2
// 5 => (101) : 1
//
// Ans is the position of last 1 in binary.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

string s;

string mod(string s, int base, int* reminder) {
  *reminder = 0;
  string ret = "";
  for (int i = 0; i < s.size(); ++i) {
    int new_num = (*reminder)*10+s[i]-'0';
    ret = ret + (char)('0'+new_num/base);
    *reminder = new_num%base;
  }
  return ret; 
}

int main() {
  //freopen("test.txt", "r", stdin);

  int T, cases = 0;
  cin >> T;
  while (T--) {
    cin >> s;
    int reminder, cnt = 0;
    while (1) {
      ++cnt;
      s = mod(s, 2, &reminder);
      if (reminder == 1)
        break;
    } 
    if (cases > 0)
      cout << endl;
    cout << "Case " << ++cases << ": " << cnt << endl;
  }

  return 0;
} 
