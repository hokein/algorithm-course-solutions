// LCA problem.
// Pure solution, record two paths and find the lastest same node.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10000;

struct Node {
  bool is_worm;
  int st, ed; // 0 pos, 1 pos
  Node() { is_worm = 0; }
  vector<Node*> sons; 
};

int n, a, b;
string s;
int pos, path1_size, path2_size;
Node path1[N], path2[N];

// build tree from dfs sequence.
Node* make_tree() {
  Node* node = new Node();
  node->st = pos; // 0 position
  ++pos;
  while (pos < s.size() && s[pos] == '0') {
    (node->sons).push_back(make_tree());
    ++pos;
  }
  node->ed = pos; // 1 position
  if (pos == a || pos == b)
    node->is_worm = 1;
  return node;
}

// find first wormy node
bool dfs1(Node* node, int level) {
  path1[level] = *node; // record path
  if (node->is_worm) {
    node->is_worm = false; // reset worm for another finding.
    path1_size = level+1;
    return true;
  }
  for (int i = 0; i < (node->sons).size(); ++i) {
    if (dfs1((node->sons)[i], level+1))
      return true;
  }
  return false;
}

// find another worm node
// Maybe not find one, since there is only one node. set path2_size = 0.
bool dfs2(Node* node, int level) {
  path2[level] = *node; // record path
  path2_size = 0;
  if (node->is_worm) {
    path2_size = level+1;
    return true;
  }
  for (int i = 0; i < (node->sons).size(); ++i) {
    if (dfs2((node->sons)[i], level+1))
      return true;
  }
  return false;
}

void dfs_del(Node* node) {
  for (int i = 0; i < (node->sons).size(); ++i)
    dfs_del((node->sons)[i]);
  delete(node);
}

int main() {
  //freopen("test.txt", "r", stdin);

  int n, T;
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> s;
    cin >> a >> b;
    --a; --b;
    pos = 0;
    Node* root = make_tree();
    dfs1(root, 0);
    dfs2(root, 0); 
    int pos1 = 0, pos2 = 0, pos = path1_size-1; // consider the same node.
    while (pos1 < path1_size && pos2 < path2_size) {
      if (path1[pos1].st == path2[pos2].st) {
        pos = pos1;
        ++pos1; ++pos2;
      } else {
        break;
      }
    }
    cout << path1[pos].st+1 << " " << path1[pos].ed+1 << endl; 
    dfs_del(root);
  }
  return 0;
} 
