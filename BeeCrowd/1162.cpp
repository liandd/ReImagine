#include<bits/stdc++.h>
using namespace std;
#define myInfinite 2147483647
#define llu unsigned long long int
llu inv;
int A[10000005];
void myMerge(int A[], int lf, int mid, int ri){
    int n1 = mid - lf + 1;
	int n2 = ri - mid;
    int i, j, k;
	int L[n1 + 2], R[n2 + 2];
    
    for(i = 1; i <= n1; i++)
        L[i] = A[lf + i - 1];
        
    for(j = 1; j <= n2; j++)
        R[j] = A[mid + j];
        
    L[n1 + 1] = myInfinite;
    R[n2 + 1] = myInfinite;
    i = 1;
    j = 1;
    
    for(k = lf; k <= ri; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
            inv = inv + n1 - i + 1;
        }
    }
}

void MergeSort(int A[], int lf, int ri){
    int mid = 0;
    if(lf < ri){
        mid = (lf + ri) >> 1;
        MergeSort(A, lf, mid);
        MergeSort(A, mid + 1, ri);
        myMerge(A, lf, mid, ri);
    } 
}

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[j]);
        }
        inv = 0;
        MergeSort(A, 0, m - 1);
        printf("Optimal train swapping takes %llu swaps.\n", inv);
    }

    return 0;
}
