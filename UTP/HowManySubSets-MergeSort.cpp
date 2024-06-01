// Mejora de la solucion Ingenua
// Juan David Garcia Acevedo - UCP
#include<bits/stdc++.h>
using namespace std;
#define myInfinite 2147483647
#define MAXN 500000

void myMerge(int A[], int lf, int mid, int ri){
    int n1 = mid - lf;
    int n2 = ri - mid;
    int i, j, k;
    int L[n1 + 2], R[n2 + 2];
    
    for(i = 0; i < n1; i++)
        L[i] = A[lf + i];
        
    for(j = 0; j < n2; j++)
        R[j] = A[mid + j];
        
    L[n1] = myInfinite;
    R[n2] = myInfinite;
    i = 0;
    j = 0;
    
    for(k = lf; k < ri; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int A[], int lf, int ri){
    int mid;
    if(lf < ri - 1){
        mid = (lf + ri) >> 1;
        MergeSort(A, lf, mid);
        MergeSort(A, mid, ri);
        myMerge(A, lf, mid, ri);
    }
}

int main(){
    int n, query, A[MAXN + 5], result;
    int idElement, i, j, s;
    
    scanf("%d %d", &n, &query);
    
    for(idElement = 0; idElement < n; idElement++)
        scanf("%d", &A[idElement]);
    
    MergeSort(A, 0, n - 1);
        
    while(query--){
        result = 0;
        scanf("%d", &s);
        for(i = 0; i < n - 1; i++){
            for(j = i + 1; j < n; j++){
                if((A[i] + A[j]) <= s){
                    result++;
                }
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
