#include <bits/stdc++.h>
using namespace std;

int main() {
  string str = "";
  int test = 0;
  while ((cin >> str) && (str != "*")) {
    if (str == "Hajj") {
      cout << "Case " << ++test << ": "
           << "Hajj-e-Akbar"
           << "\n";
    } else
      cout << "Case " << ++test << ": "
           << "Hajj-e-Asghar"
           << "\n";
  }
  return 0;
}
