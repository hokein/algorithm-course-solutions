#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
using namespace std;

typedef pair<int, int> state;

const int N = 500000;

int n, parent[N], steps[N], max_steps;
char record_operations[N];
state q[N], st(1234, 8765);
set<state> vis;

void print_path(int pos) {
  if (pos == 0)
    return;
  print_path(parent[pos]);
  cout << record_operations[pos];
}

state do_operation(const state& s, int mode) {
  int x = s.first, y = s.second;
  switch (mode) {
    case 0: // operation A.
      return state(y, x);
    case 1: // operation B.
      return state((x%10)*1000+x/10, (y%10)*1000+y/10);
    case 2: // operation C.
      return state(x/1000*1000 + (y/100)%10*100 + (x/100)%10*10 + x%10,
                   y/1000*1000 + (y/10)%10*100 + (x/10)%10*10 + y%10); 
  }
  return s;
}

bool bfs(const state& target) {
  // fp: queue head pointer.
  // rp: queue rear pontier.
  int fp = 0, rp = 0;
  steps[rp] = 0;
  q[rp++] = st; 
  vis.clear();
  while (fp != rp) {
    state s = q[fp];
    if (s == target) {
      if (steps[fp] > max_steps)
        return false;
      cout << steps[fp] << " ";
      print_path(fp);
      cout << endl;
      return true;
    }    
    for (int i = 0; i < 3; ++i) {
      state new_state = do_operation(s, i);
      if (vis.find(new_state) == vis.end()) {
        vis.insert(new_state);
        q[rp] = new_state; // push the new state into the queue.
        // record the state infos, include steps, parent node, and the type operations.
        steps[rp] = steps[fp]+1;
        record_operations[rp] = 'A'+i;
        parent[rp++] = fp; // move rear pointer.
      }
    }
    fp++; // move head pointer, means pop head element.
  }
  return false;
}

int main() {
  //freopen("test.txt", "r", stdin);

  while (cin >> max_steps && max_steps != -1) {
    state target(0, 0);
    int num;
    for (int i = 0; i < 4; ++i) {
      cin >> num;
      target.first = 10*target.first + num;
    }
    for (int i = 0; i < 4; ++i) {
      cin >> num;
      target.second = 10*target.second + num;
    }
    if (!bfs(target))
      cout << -1 << endl; 
  }
  return 0;
} 
