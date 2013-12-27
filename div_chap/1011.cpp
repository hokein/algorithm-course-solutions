#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 250005;
const int kBufferMax = 60000;

//const int N = 4;
//const int kBufferMax = 5;

int num[N+5], n;
int input_buffer[kBufferMax+5];

int main() {
  //freopen("test.txt", "r", stdin);

  while (scanf("%d", &n) != EOF) {
    if (n >= N) {
      for (int i = 0; i < N; ++i)
        scanf("%d", &num[i]);
      sort(num, num+N);
      int pos = 0;
      for (int i = N; i <= n; ++i) {
        if (i < n)
          scanf("%d", &input_buffer[pos++]);
        if (pos >= kBufferMax || (pos > 0 && i == n)) {
          sort(input_buffer, input_buffer+pos);
          deque<int> buffer2;
          int p1 = 0, p2 = 0;
          int pp1 = 0;
          while (p1 < N || p2 < pos) {
            if (p1 >= N || (p2 < pos && input_buffer[p2] < num[p1]))
              buffer2.push_back(input_buffer[p2++]);
            else
              buffer2.push_back(num[p1++]);
            if (buffer2.size() > pos*2) {
              for (int j = 0; j < pos; ++j) {
                if (pp1 < N)
                  num[pp1++] = buffer2.front();
                buffer2.pop_front();
              }
            }
          }
          while (pp1 < N) {
            num[pp1++] = buffer2.front();
            buffer2.pop_front();
          }
          pos = 0;
        }
      }
    } else {
      for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
      sort(num, num+n);
    }
    if (n%2 == 0)
      printf("%.1f\n", ((long long)num[n/2-1]+(long long)num[n/2])/2.0);
    else
      printf("%.1f\n", (num[n/2])*1.0);
  }
  return 0;
} 
