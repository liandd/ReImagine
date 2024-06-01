#include<bits/stdc++.h>
using namespace std;
#define myInfinite 2147483647
#define MAXN 1000000

int binarySearch(int A[], int lf, int ri, int k){
	int mid, result = -1;
	while(lf <= ri){
		mid = (lf + ri) >> 1;
		if(A[mid] == k){
			result = mid;
			break;
		}
		else{
			if(k > A[mid]){
				lf = mid + 1;
			}
			else{
				ri = mid - 1;
			}
		}
	}
	if(result == -1){
		result = -lf - 1;
	}
	return result;
}

void myMerge(int A[], int lf, int mid, int ri){
	int n1 = mid - lf + 1;
	int n2 = ri - mid;
	int L[n1 + 5], R[n2 + 5];
	int i, j, k;
	
	for(i = 0; i < n1; i++)
		L[i] = A[lf + i];
	
	for(j = 0; j < n2; j++)
		R[j] = A[mid + 1 + j];
		
	L[n1] = myInfinite;
	R[n2] = myInfinite;
	i = 0;
	j = 0;
	
	for(k = lf; k <= ri; k++){
		if(L[i] > R[j]){
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
	if(lf < ri){
		mid = (lf + ri) >> 1;
		MergeSort(A, lf, mid);
		MergeSort(A, mid + 1, ri);
		myMerge(A, lf, mid, ri);
	}
}

int main(){
	int m, n, A[MAXN + 5], B[MAXN + 5];
	int idElement, i, j;
	
	while(scanf("%d %d", &m, &n) != EOF){
		for(idElement = 0; idElement < m; idElement)
			scanf("%d", &A[idElement]);
		
		MergeSort(A, 0, m - 1);
		
		for(idElement = 0; idElement < n; idElement)
			scanf("%d", &B[idElement]);
		
		
		
	}	
	return 0;
}
