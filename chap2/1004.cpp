#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<char, int> P; // (value, index)

const int N = 205;
char matrix[N][N], keyword[N], s[N];

bool cmp(const P& a, const P& b) {
  return a.first < b.first;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (scanf("%s", keyword)) {
    if (strcmp(keyword, "THEEND") == 0)
      break;
    scanf("%s", s);
    int total_col = strlen(keyword);
    int total_row = strlen(s)/total_col;
    vector<P> p;
    for (int i = 0; i < total_col; ++i)
      p.push_back(P(keyword[i], i));
    sort(p.begin(), p.end(), cmp);

    int st_pos = 0;
    for (int i = 0; i < p.size(); ++i) {
      for (int j = 0; j < total_row; ++j)
        matrix[j][p[i].second] = s[st_pos++];
    }
    for (int i = 0; i < total_row; ++i)
      for (int j = 0; j < total_col; ++j)
        printf("%c", matrix[i][j]);
    printf("\n");
  }
  return 0;
} 
