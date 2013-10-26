#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;
const int INF = 100000000;

int maze[N][N], in_degree[N];
int main() {
  //freopen("test.txt", "r", stdin);

  int cnt = 0;
  string s;
  while (cin >> s) {
    memset(maze, 0, sizeof(maze));
    memset(in_degree, 0, sizeof(in_degree));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j)
        maze[i][j] = INF;
      maze[i][i] = 0;
    }
    int sum = 0;
    while (s != "deadend") {
      int a = s[0]-'a';
      int b = s[s.size()-1]-'a';
      maze[a][b] = maze[b][a] = s.size(); 
      in_degree[a]++;
      in_degree[b]++;
      sum += s.size();
      cin >> s;
    }

    for (int k = 0; k < 30; ++k)
      for (int i = 0; i < 30; ++i)
        for (int j = 0; j < 30; ++j)
          maze[i][j] = min(maze[i][j], maze[i][k]+maze[k][j]);
    int st=-1, ed=-1;
    for (int i = 0; i < 30; ++i)
      if (in_degree[i]%2 == 1) {
        if (st == -1)
          st = i;
        else
          ed = i;
      }
    if (st != -1)    
      sum += maze[st][ed];
    cout << sum << endl;
  }
  return 0;
} 
