#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
#define myInfinite 2147483647
#define MAXN 1000000
#define MAXK 50

int A[MAXN + 5];

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
	int n, k, S[MAXK + 5], element;
	int idMaximunFrecuency, index, minimunSum;
	int idElement, idQuery, i, j, CopyJ;
	llu F[MAXK + 5], maximunFrecuency;
	
	
	scanf("%d %d", &n, &k);
	
	CopyJ = j = k;
	
	for(idElement = 0; idElement < n; idElement++)
		scanf("%d", &A[idElement]);
	
	MergeSort(A, 0, n - 1);
	
	for(idQuery = 0; idQuery < k; idQuery++)
		scanf("%d", &S[idQuery]);
	
	idQuery = 0;
	while(k--){
		F[idQuery] = 0;
		for(i = 0; i < n - 1 ; i++){
			element = S[idQuery] - A[i];
			if(element > A[i]){
				if(binarySearch(A, i + 1, n - 1, element) >= 0){
					F[idQuery]++;
				}
			}
			else
				break;
		}
		idQuery++;
	}
	vector<pair<int, llu>> results;
    for (i = 0; i < j; i++) {
        results.emplace_back(S[i], F[i]);
    }
	// Combo Ganador, el ordenamiento
    sort(results.begin(), results.end(), [](const pair<int, llu> &a, const pair<int, llu> &b) {
        if (a.second != b.second) return b.second < a.second;
        return a.first < b.first;
    });

    for (const auto &res : results) {
        printf("%d %llu\n", res.first, res.second);
    }
	/*
	while(j--){
		maximunFrecuency = 0;
		for(index = 0; index < CopyJ; index++){
			if(F[index] > maximunFrecuency)
				maximunFrecuency = F[index];
		}
		
		minimunSum = myInfinite;
		idMaximunFrecuency = 0;
		
		for(index = 0; index < CopyJ; index++){
			if(F[index] == maximunFrecuency){
				if(S[index] < minimunSum){
					minimunSum = S[index];
					idMaximunFrecuency = index;
				}	
			}
		}
		printf("%d %llu\n", S[idMaximunFrecuency], F[idMaximunFrecuency]);
		S[idMaximunFrecuency] = 0;
		F[idMaximunFrecuency] = 0;
	}
	*/
	return 0;
}
