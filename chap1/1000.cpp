#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

map<string, string> ip_to_main_id;
map<string, string> main_id_to_mj;

int main() {
  //freopen("test.txt", "r", stdin);

  int n;
  while (cin >> n && n) {
    string ip, name;
    ip_to_main_id.clear(); 
    main_id_to_mj.clear();
    for (int i = 0; i < n; ++i) {
      cin >> name >> ip;
      if (ip_to_main_id.find(ip) == ip_to_main_id.end()) {
        ip_to_main_id[ip] = name;
        main_id_to_mj[name] = "";
      }
      else {
        main_id_to_mj[ip_to_main_id[ip]] = name;
      }
    }

    for (map<string, string>::iterator it = main_id_to_mj.begin();
         it != main_id_to_mj.end(); ++it) {
      cout << it->second << " is the MaJia of " << it->first << endl;
    }
    cout << endl;
  }
  return 0;
} 
