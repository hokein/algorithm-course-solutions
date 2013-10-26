#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;
const double epos = 10e-8;
double dp[N][N][N];
int parent[N][N][N];
int n;

double my_abs(double a) {
  return a>0?a:-a;
}
void output_path(int x, int y, int len) {
  if (len < 1) {
    //cout << x << " "; 
    return;
  }
  //output_path(parent[node][node][len], len-1);
  //int next_v;
  //for (int k = 1; k <= n; ++k)
    //if (my_abs(dp[x][k][len-1]*dp[k][y][1]-dp[x][y][len]) < epos) {
      //next_v = k;
      //break;
    //}
  output_path(x, parent[x][y][len], len-1);
  cout << parent[x][y][len] << " ";
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> n) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == j)
          dp[i][j][1] = 1;
        else
          cin >> dp[i][j][1];
        parent[i][j][1] = i;
      }
    }
    
    bool is_find = false;
    for (int p = 2; p <= n && !is_find; ++p) {
      for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= n; ++j) {
            double new_value = dp[i][k][p-1]*dp[k][j][1];
            if (dp[i][j][p] < new_value) {
              dp[i][j][p] = new_value;
              parent[i][j][p] = k;
            }

            //dp[i][j][p] = max(dp[i][j][p], dp[i][k][p-1]*dp[k][j][1]);
          }

      for (int i = 1; i <= n; ++i) {
        if (dp[i][i][p] > 1.01) {
          is_find = true;
          //cout << p;
          output_path(i, i, p);
          cout <<  i << endl; 
          break;
        } 
      } 
    }
    if (!is_find)
      cout << "no arbitrage sequence exists" << endl;
    
  }
  return 0;
} 
