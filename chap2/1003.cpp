#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 205;

char matrix[N][N], s[N];
int col;

int main() {
  //freopen("test.txt", "r", stdin);

  while (scanf("%d", &col) != EOF && col) {
    scanf("%s", s);
    int len = strlen(s);
    int row = len/col; 
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j) {
        if (i%2 == 0) {
          matrix[i][j] = s[i*col+j];
        }
        else {
          matrix[i][col-j-1] = s[i*col+j];
        }
      }
    for (int j = 0; j < col; ++j)
      for (int i = 0; i < row; ++i)
        printf("%c", matrix[i][j]);
    printf("\n");

  }
  return 0;
} 
