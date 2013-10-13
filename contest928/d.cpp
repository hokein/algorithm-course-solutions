#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int prime[] = {2, 3, 5, 7 };

vector<int> v[10];
void solve(ll n) {
  if (n < 10) {
    cout << n << endl;
    return;
  } 
  ll tmp = n;
  v[2].clear();
  v[3].clear();
  v[5].clear();
  v[7].clear();
  for (int i = 0; i < 4; ++i) {
    while (tmp%prime[i] == 0) {
     v[prime[i]].push_back(prime[i]);
     tmp /= prime[i];
    }
  }
  if (tmp != 1) {
    cout << "-1" << endl;
    return ;
  }
  vector<int> digs;

  for (int i = 0; i < v[5].size(); ++i)
    digs.push_back(v[5][i]);
  for (int i = 0; i < v[7].size(); ++i)
    digs.push_back(v[7][i]);

  for (int i = 0; i < v[3].size()/2; ++i)
    digs.push_back(9);

  int size2 = v[2].size();
  for (int i = 0; i < v[2].size()/3; ++i)
    digs.push_back(8);
  size2 = size2 - 3*(size2/3);
  int remain_3 = v[3].size() - 2*(v[3].size()/2);
  if (remain_3 > 0 ) {// 1
    if (size2 > 0) {
      digs.push_back(6);
      size2--;
    }
    else {
      digs.push_back(3);
    }
  }
  
  if (size2 > 0) {
    if (size2 == 2)
      digs.push_back(4);
    if (size2 == 1)
      digs.push_back(2);
  }
    
  sort(digs.begin(), digs.end());
  for (int i = 0; i < digs.size(); ++i)
    cout << digs[i];
  cout << endl;
}

int main() {
  //freopen("test.txt", "r", stdin);

  ull n;
  while (cin >> n) {
    if (n == 0) {
      cout << "10" << endl;
      continue;
    }
    solve(n);
  }
  return 0;
} 
