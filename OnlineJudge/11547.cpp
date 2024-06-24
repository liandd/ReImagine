#include <bits/stdc++.h>
using namespace std;

int main() {
  int t = 0;
  scanf("%d", &t);
  while (t--) {
    int n = 0, result = 0;
    scanf("%d", &n);
    result = ((n * 567) / 9) + 7492;
    n = (result * 235) / 47;
    result = n - 498;
    string str = "";
    str = to_string(result);
    char r = str[str.size() - 2];
    printf("%c\n", r);
  }
  return 0;
}
