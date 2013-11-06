// 1
// 1 2 1
// 1 2 1 3 1 2 1
// 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1
//
// 0001  => 0 
// 0010  => 1
// 0011  => 0
// 0100  => 2
// 0101  => 0
// 0110  => 1
// 0111  => 0
// 1000  => 3
// how many zeros after the last 1 number?
//
// k steps, calcuale the number of zeros after last 1 number in k binary format.
// then plus 1.
//
//
// Hanoi Tower
// let f(k) is the total steps of moving k disks.
// f(k) = f(k-1) + 1 + f(k-1)
//      = 2*f(k-1)+ 1.
// f(k) = 2^k -1.
// No.k disk move in No.2^(k-1) steps.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n;
string s;

string divide(string s) {
  int remain = 0;
  string res = "";
  for (int i = 0; i < s.size(); ++i) {
    remain = 10*remain+s[i]-'0';
    res += string(1, (remain/2+'0'));
    remain %= 2;
  }
  return res;
}
int main() {
  //freopen("test.txt", "r", stdin);

  int cases = 0;
  cin >> n;
  while (n--) {
    cin >> s;
    int cnt = 0;
    // calculate how many 2 we can divide.
    while ((s[s.size()-1]-'0')%2 == 0) {
      ++cnt;
      s = divide(s);
    }
    cout << "Case " << ++cases << ": " << ++cnt << endl;
    if (n != 0)
      cout << endl;
  }
  return 0;
} 
