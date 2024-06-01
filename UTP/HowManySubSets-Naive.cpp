// Solucion Ingenua para probar el Time Limit en el Juez Hacker Rank
// Juan David Garcia Acevedo
#include<bits/stdc++.h>
using namespace std;
#define MAXN 500000

int main(){
	int n, q, A[MAXN + 5], result;
	int idElement, idQuery, i, j, s;
	
	scanf("%d %d", &n, &q);
	
	for(idElement = 1; idElement <= n; idElement++)
		scanf("%d", &A[idElement]);
		
	for(idQuery = 1; idQuery <= q; idQuery++){
		result = 0;
		scanf("%d", &s);
		for(i = 1; i < n; i++){
			for(j = i + 1; j <= n; j++){
				if((A[i] + A[j]) <= s){
					result++;
				}
			}
		}
		printf("%d\n", result);
	}
	
	return 0;
}
