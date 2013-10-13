#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000;
string s[N];
int dna_match[1000];
bool vis[N];

bool is_complement(string& a, string& b) {
  if (a.size() != b.size())
    return false;
  for (int i = 0; i < a.size(); ++i)
    if (dna_match[a[i]] != b[i])
      return false;
  return true;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int t;
  cin >> t;
  dna_match['A'] = 'T';
  dna_match['T'] = 'A';
  dna_match['C'] = 'G';
  dna_match['G'] = 'C';
  while (t--) {
    int n;
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (!vis[i]) {
        for (int j = i+1; j < n; ++j)
          if (!vis[j]) {
            if (is_complement(s[i], s[j])) {
              ans++;
              vis[i] = vis[j] = 1;
              break;
            }
          }
      }
    cout << ans << endl;
  }
  return 0;
} 
