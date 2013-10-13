#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000000;

int couple_match_id[N];

int main() {
  //freopen("test.txt", "r", stdin);
  int n;
  while (cin >> n && n) {
    int a, b;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      couple_match_id[a] = b;
      couple_match_id[b] = a;
    }

    stack<int> s;
    n *= 2;
    for (int i = 1; i <= n; ++i) {
      if (s.empty()) 
        s.push(i);
      else {
        if (couple_match_id[s.top()] == i)
          s.pop();
        else
          s.push(i);
      }
    }
    cout << (s.empty()? "Yes": "No") << endl;
  }
  return 0;
} 
