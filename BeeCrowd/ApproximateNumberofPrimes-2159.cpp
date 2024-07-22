#include <bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d", &x)
#define pf(x,y) printf("%.1f %.1f\n", x, y)

int main() {
  int n;
  double p, m, logn;
  cin >> n;
  logn = log(n);
  p = n / logn;
  m = 1.25506 * (p);
  pf(p, m);
}
