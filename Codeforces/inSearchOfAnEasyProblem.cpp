#include <bits/stdc++.h>
using namespace std;

int binarySearch(int A[], int lf, int ri, int k) {
  int mid, result = -1;
  while (lf <= ri) {
    mid = (lf + ri) >> 1;
    if (A[mid] == k) {
      result = mid;
      break;
    } else {
      if (k > A[mid]) {
        lf = mid + 1;
      } else {
        ri = mid - 1;
      }
    }
  }
  if (result == -1) {
    result = -lf - 1;
  }
  return result;
}
int main() {
  int n, i = 0;
  scanf("%d", &n);
  int A[n + 2];
  bool res = false;
  while (n--) {
    scanf("%d", &A[i]);
    if (A[i] == 1) {
      res = true;
      printf("HARD\n");
      return 0;
    }
    i++;
  }
  printf("EASY\n");

  return 0;
}
