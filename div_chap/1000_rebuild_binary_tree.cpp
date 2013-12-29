// Give a pre-order and in-order sequence of binary tree.
// Rebuild the tree and output the bfs sequence.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct Node {
  char c;
  Node* left, *right;
  Node() {}
  Node(char c) {
    this->c = c;
    left = right = NULL;
  }
};

string pre_order, in_order;
int pos; // pre_order position

// [l, r) 
Node* make_tree(int l, int r) {
  if (l >= r)
    return NULL;
  Node* node = new Node(pre_order[pos]); // root node
  int mid;
  for (int i = l; i < r; ++i) // find left subtree
    if (pre_order[pos] == in_order[i]) {
      mid = i;
      break;
    }
  ++pos;
  node->left = make_tree(l, mid); // build left subtree
  node->right = make_tree(mid+1, r); // build right subtree.
  return node;
}

void bfs(const Node* root) {
  queue<const Node*>  q;
  q.push(root);
  while (!q.empty()) {
    const Node* fp = q.front();
    q.pop();
    cout << fp->c;
    if (fp->left)
      q.push(fp->left);
    if (fp->right)
      q.push(fp->right);
    delete(fp);
  }
  cout << endl;
}

int main() {
  //freopen("test.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    pos = 0;
    cin >> pre_order >> in_order;
    Node* root = make_tree(0, in_order.size());
    bfs(root);
  }
  return 0;
} 
