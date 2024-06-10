#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)

int main() {
  /*
   Sample Input
  3
  2 1
  10 10
  -10 1
  0 33
  4
  -1000 -1000
  -1000 -1000
  0 0
  -2000 -10000
  -999 -1001
  0
  Sample Output
  NE
  divisa
  NO
  divisa
  NE
  SO
  SE
   */
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  while (cin >> k && k) {
    int n, m;
    cin >> n >> m;
    fo(i, k) {
      int x, y;
      cin >> x >> y;
      if (x == n || y == m)
        cout << "divisa\n";
      else if (x > n && y > m)
        cout << "NE\n";
      else if (x > n && y < m)
        cout << "SE\n";
      else if (x < n && y > m)
        cout << "NO\n";
      else if (x < n && y < m)
        cout << "SO\n";
    }
  }
  return 0;
}
