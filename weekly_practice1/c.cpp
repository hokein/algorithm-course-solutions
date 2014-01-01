#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;
int n, k, ans = 0;
int digs[N];

bool isvalid(int size) {
  for (int i = 1; i < size; ++i)
    if ((digs[i]== 0 && digs[i-1] == 0))
      return false;
  return true;
}

void dfs(int pos) {
  if (pos >= n) {
    if (isvalid(pos))
      ans++;
    return;
  }

  if (!isvalid(pos))
    return;
  for (int i = pos==0?1:0; i < k; ++i) {
    digs[pos] = i;
    dfs(pos+1);
  }
}

int main() {
  //freopen("test.txt", "r", stdin);

  for (k = 2; k <= 10; ++k)
    for (n = 2; n+k <= 18; ++n) {
      cout << n << " " << k << ":  ";
      ans = 0;
      dfs(0);
      cout << ans << endl;
    }
  return 0;
} 
