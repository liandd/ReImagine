// Implementacion de Busqueda Binaria con Ordenamiento por Mezclas
// Juan David Garcia Acevedo - UCP
#include<bits/stdc++.h>
#define llu unsigned long long int
#define myInfinite 2147483647
#define MAXN 500000

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
	int i, j, k;
	int L[n1 + 2], R[n2 + 2];
	
	for(i = 0; i < n1; i++)
		L[i] = A[lf + i];
		
	for(j = 0; j < n2; j++)
		R[j] = A[mid + 1 + j];
		
	L[n1] = myInfinite;
	R[n2] = myInfinite;
	i = 0;
	j = 0;
	
	for(k = lf; k <= ri; k++){
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
	if(lf < ri){
		mid = (lf + ri) >> 1;
		MergeSort(A, lf, mid);
		MergeSort(A, mid + 1, ri);
		myMerge(A, lf, mid, ri);
	}
}

int main(){
	int n, query, A[MAXN + 5], index, element;
    int idElement, i, s;
	llu result;
	
	scanf("%d %d", &n, &query);
	
	for(idElement = 0; idElement < n; idElement++)
		scanf("%d", &A[idElement]);
	
	MergeSort(A, 0, n - 1);
	
	while(query--){
		result = 0;
		scanf("%d", &s);
		for(i = 0; i < n - 1 ; i++){
			element = s - A[i];
			if(element > A[i]){
				index = binarySearch(A, i + 1, n - 1, element);
				if(index < 0)
					index = (-1 * index) - 2;
				result += (index - i);
			}
			else
				break;
		}
		printf("%llu\n", result);
	}
	return 0;
}
