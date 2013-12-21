#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
  //freopen("test.txt", "r", stdin);

  string s;
  while (cin >> s) {
    if (s == "0")
      break;
    int base = 1;
    int ans = 0;
    for (int i = s.size()-1; i >= 0; --i) {
       int c = s[i]-'0';
       if (c >= 5) --c;
       ans += c*base;
       base *= 9; 
    }
    cout << s << ": " << ans << endl;  
  }
  return 0;
} 
