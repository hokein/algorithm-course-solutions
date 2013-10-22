#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int pos; // read pointer.
string line; // buffer.

inline bool is_digit(char c) {
  return c >= '0' && c <= '9';
}

bool read_line() {
  pos = 0;
  return getline(cin, line);
}

// get token:
//   * nums
//   * (
//   * )
//   * "": empty, means research EOF
string get_token() {
  char c;
  if (pos >= line.size())
    if (!read_line())
      return "";
  bool is_negative = 0;
  while (1) {
    if (pos == line.size())
      if (!read_line())
        return "";
    c = line[pos++];
    if (c == '(' || c == ')')
      return string(1, c);
    else if (c == '-')
      is_negative = 1;
    else if (is_digit(c))
      break;
  }

  if (is_digit(c)) {
    string s(1, c);
    while (1) {
      if (pos == line.size())
        if (!read_line())
          return "";
      c = line[pos];
      if (!is_digit(c)) {
        if (is_negative)
          s = "-"+s;
        return s;  
      }
      ++pos;
      s += string(1, c);
    }
  }
  return "";
}

int string2int(const string& s) {
  int res = 0;
  for (int i = s[0]=='-'?1:0; i < s.size(); ++i)
    res = 10*res + s[i]-'0';
  return s[0]=='-'?-res:res;
}

struct node {
  int value, left, right;
  node():value(0), left(-1), right(-1) {}
};

const int N = 100000;
node nodes[N];
int cnt;

// build binary search tree.
int match() {
  string s1 = get_token(), s2 = get_token();
  if (s1 == "(" && s2 == ")") {
    return -1;
  } else { // (12
    int num = string2int(s2);
    int pos = cnt;
    nodes[cnt++].value = num;
    nodes[pos].left = match(); // left substree
    nodes[pos].right = match(); // right substree
    get_token();
    return pos;
  }
}

bool dfs(int root, int cur_sum, int sum) {
  if (root == -1) return false;
  cur_sum += nodes[root].value;
  if (nodes[root].left == -1 && nodes[root].right == -1)
    return cur_sum == sum;
  if (nodes[root].left != -1)
    if (dfs(nodes[root].left, cur_sum, sum))
      return true;
  if (nodes[root].right != -1)
    if (dfs(nodes[root].right, cur_sum, sum))
      return true;
  return false;
}

int main() {
  pos = 0;
  while (1) {
    string s = get_token();
    if (s == "") break;
    cnt = 0;
    int sum = string2int(s);
    int root = match();
    if (dfs(root, 0, sum))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
} 
