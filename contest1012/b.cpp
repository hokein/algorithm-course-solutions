#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10;
const ll INF = (1LL<<50);

// 0:B 1:C 2:G
ll bin[N][3], path[N], ans_path[N], ans;
bool vis[N] = {0};
char s[] = {'B', 'C', 'G'};

void dfs(int cnt) {
  if (cnt >= 3) {
    ll sum = 0;
    sum += bin[1][path[0]] + bin[2][path[0]];
    sum += bin[0][path[1]] + bin[2][path[1]];
    sum += bin[0][path[2]] + bin[1][path[2]];
    if (sum < ans) {
      ans = sum;
      for (int i = 0; i < 3; ++i)
        ans_path[i] = path[i];
    }
    return;
  } 
  for (int i = 0; i < 3; ++i)
    if (!vis[i]) {
      vis[i] = 1;
      path[cnt] = i;
      dfs(cnt+1);
      vis[i] = 0;
    }
}

int main() {
  while (cin >> bin[0][0] >> bin[0][2] >> bin[0][1]) {
    for (int i = 0; i < 2; ++i)
      cin >> bin[i+1][0] >> bin[i+1][2] >> bin[i+1][1];
    ans = INF;
    dfs(0); 
    for (int i = 0; i < 3; ++i)
      cout << s[ans_path[i]];
    cout << " " << ans << endl;
  }
  return 0;
} 
