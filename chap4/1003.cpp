// Give number a, find x, which x^3 = a(mod 10^n), n = len(a)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;

ll a;

int dig(ll v) {
  int n = 0;
  while (v) {
    ++n;
    v /= 10;
  }
  return n;
}

ll mul(ll a, ll b, ll mod) {
  ll c = 0;
  while (b) {
    c += a*(b%10);
    c %= mod;
    a = (10*a)%mod;
    b /= 10;
  }
  return c;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    cin >> a;
    int digits = dig(a);
    ll mod = 1;
    ll current = 0;
    for (int i = 0; i < digits; ++i) {  // enum each bit, from low to high
       mod *= 10; 
       ll new_value;
       for (int j = 0; j < 10; ++j) {  // 0~9.
         new_value = j*(mod/10) + current;
         if (mul(mul(new_value, new_value, mod), new_value, mod) == a%mod)
           break;
       }
       current = new_value;
    }
    cout << current << endl;
  } 
  return 0;
} 
