#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)

int main() {
  int t;
  si(t);
  while (t--) {
    set<int> sheeps;
    int n;
    si(n);
    fo(i, n) {
      int aux;
      si(aux);
      sheeps.insert(aux);
    }
    pi(sheeps.size());
  }
  return 0;
}
