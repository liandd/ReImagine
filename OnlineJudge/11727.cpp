#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cont = 0;
  scanf("%d", &n);
  while (n--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int A[3];
    A[0] = a, A[1] = b, A[2] = c;
    sort(A, A + 3);
    printf("Case %d: %d\n", ++cont, A[1]);
  }
  return 0;
}
