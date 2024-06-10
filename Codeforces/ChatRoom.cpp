#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  unordered_set<char> pal = {'h', 'e', 'l', 'o'};
  set<char> encontrado;
  vector<char> objetivo = {'h', 'e', 'l', 'l', 'o'};
  int objetivox = 0;
  for (int i = 0; i < s.size(); i++) {
    char key = s[i];
    if (pal.find(key) != pal.end()) {
      if (key == objetivo[objetivox]) {
        encontrado.insert(key);
        objetivox++;
      }
      if (objetivox == objetivo.size()) {
        break;
      }
    }
  }
  if (encontrado.size() == 4 && encontrado.count('l') == 1) {
    cout << "YES"
         << "\n";
  } else if (encontrado.size() == 5) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
  return 0;
}
