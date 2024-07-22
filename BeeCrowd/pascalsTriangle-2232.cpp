#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)

int main() {
  int t;
  si(t);
  while (t--) {
    int n, r = 0;
    si(n);
    fo(i, n) { r += pow(2, i); }
    pi(r);
  }
}
