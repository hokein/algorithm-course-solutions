#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100;

int n, pos;
string s;
double p[N];

double parallel_match();

// match A,B
double series_match() {
  double ret = 1;
  while (pos < s.size()) {
    if (s[pos] == ')') break;
    if (s[pos] == ' ' || s[pos] == ',') {
      ++pos;
      continue;
    } else if (s[pos] == '(') {
      ret *= 1-parallel_match(); // meet a parallel circuit
    } else {
      ret *= 1-p[s[pos]-'A'];
      ++pos;
    }
  }
  return 1-ret;
}

// match (A)
double parallel_match() {
  double ret = 1;
  while (pos < s.size()) {
    if (s[pos] == ' ') { ++pos; continue;}
    if (s[pos] == ',') { // meet a series circuit
      ++pos;
      ret = 1-(1-ret)*(1-parallel_match());
    } else if (s[pos] >= 'A' && s[pos] <= 'Z') {
      ret *= series_match();
    } else if (s[pos] == '(') {
      ++pos;
      ret *= parallel_match();
    } else if (s[pos] == ')') {
      ++pos;
      break;
    }
  }
  return ret;
}

int main() {
  freopen("test.txt", "r", stdin);

  while (cin >> n) {
    cin >> s;
    for (int i = 0; i < n; ++i)
      cin >> p[i];
    s = "(" + s + ")";
    pos = 0;
    printf("%.4f\n", parallel_match());
  }

  return 0;
} 
