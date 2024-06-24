#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 0;
  int test = 0;
  while (scanf("%d", &n) && (n > 0)) {
    int i = 0, element = 0, cont = 0, res = 0, A[n + 1];
    while (n--) {
      scanf("%d", &A[i]);
      if (A[i] > 0)
        cont++;
      if (A[i] == 0)
        res++;
      i++;
    }
    printf("Case %d: %d\n", ++test, (cont - res));
  }
  return 0;
}
