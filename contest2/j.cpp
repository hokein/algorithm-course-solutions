#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 50;

bool maze[N][N], vis[N];
int indegree[N], n;
char int2char[N], path[N];
map<char, int> mpchar;

inline bool is_valid(int size, int pos) {
  for (int i = 0; i < size; ++i)
    if (maze[pos][mpchar[path[i]]])
      return false;
  return true;
}

void dfs(int pos)  {
  if (pos >= n) {
    for (int i = 0; i < n; ++i)
      cout << path[i];
    cout << endl;
    return;
  }
  for (int i = 0; i < n; ++i)
    if (!vis[i] && is_valid(pos, i)) {
      vis[i] = 1;
      path[pos] = int2char[i];
      dfs(pos+1);
      vis[i] = 0;
    }
}

int main() {
  //freopen("test.txt", "r", stdin);

  string letters, pairs;
  int is_first = true;
  while (getline(cin, letters)) {
    if (!is_first)
      cout << endl;
    is_first = false;
    getline(cin, pairs);
    n = 0;
    mpchar.clear();
    set<int> se;
    // sort letter.
    for (int i = 0; i < letters.size(); ++i)
      if (letters[i] != ' ')
        se.insert(letters[i]);
    for (set<int>::iterator it = se.begin(); it != se.end(); ++it) {
      mpchar[*it] = n;
      int2char[n++] = *it;
    }
    memset(maze, 0, sizeof(maze));
    for (int i = 0; i < n; ++i)
      maze[i][i] = 1;
    for (int pos = 0; pos < pairs.size(); ) {
      while (pairs[pos] == ' ')
        pos++;
      char a = pairs[pos++];
      while (pairs[pos] == ' ')
        pos++;
      char b = pairs[pos++];
      maze[mpchar[a]][mpchar[b]] = 1;
    }

    dfs(0);
  }
  return 0;
} 
