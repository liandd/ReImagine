#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, result = 0;
  cin >> n;
  while (n--) {
    int donation = 0;
    string operation = "";
    cin >> operation;
    if (operation == "donate") {
      cin >> donation;
      result += donation;
      continue;
    }
    if (operation == "report") {
      cout << result << "\n";
      continue;
    }
  }
  return 0;
}
