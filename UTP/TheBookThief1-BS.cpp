#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MT 14142
lli binarySearch(lli a[], lli i, lli j, lli k){
    lli m = 0, result = -1;
    while(i <= j){
        m = (i + j) >> 1;
        if(a[m] == k){
            result = m;
            break;
        }
        else{
            (k > a[m]) ? i = m + 1 : j = m - 1;
        }
    }
    (result == -1) ? result = (-1) * i - 1 : result;
    return result;
}

int main(){
    lli s = 0, paginas = 0, paginaOlvidada = 0, t = 0, indice = 0;
    lli triangularNumbers[MT + 5];
    triangularNumbers[0] = 0;
    for(lli i = 1; i <= MT; i++){
        triangularNumbers[i] = triangularNumbers[i - 1] + i;
    }
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &s);
        if(s > 0){
            indice = binarySearch(triangularNumbers, 1, MT, s);
            (indice > 0) ? paginas = indice + 1 : paginas = -1 * (indice + 1);
            paginaOlvidada = triangularNumbers[paginas] - s;
            printf("%lld %lld\n", paginaOlvidada, paginas);
        }
    }

    return 0;
}
