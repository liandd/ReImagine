#include <bits/stdc++.h>
using namespace std;

int main() {
  int cont = 0;
  string str = "";
  while ((cin >> str) && (str[0] != '#')) {
    if (str == "HELLO") {
      cout << "Case " << ++cont << ": ENGLISH\n";
      continue;
    } else if (str == "HOLA") {
      cout << "Case " << ++cont << ": SPANISH\n";
      continue;
    } else if (str == "HALLO") {
      cout << "Case " << ++cont << ": GERMAN\n";
      continue;
    } else if (str == "BONJOUR") {
      cout << "Case " << ++cont << ": FRENCH\n";
      continue;
    } else if (str == "CIAO") {
      cout << "Case " << ++cont << ": ITALIAN\n";
      continue;
    } else if (str == "ZDRAVSTVUJTE") {
      cout << "Case " << ++cont << ": RUSSIAN\n";
      continue;
    } else
      cout << "Case " << ++cont << ": UNKNOWN\n";
    continue;
  }
  return 0;
}
