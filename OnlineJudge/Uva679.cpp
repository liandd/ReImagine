#include<bits/stdc++.h>
#define lli long long int
lli binarySearch(lli i, lli j, lli k){
    lli result = 1;
    while(i < j){
        if((k & 1) == 0){
            result = result * 2 + 1;
            k >>= 1;
        }
        else{
            result *= 2;
            k = (k + 1) >> 1;
        }
        i++;
    }
    return result;
}
int main(){
    lli t = 0, d = 0, i = 0, indice = 0;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &d, &i);
        indice = binarySearch(1, d, i);
        printf("%lld\n", indice);
    }
    return 0;
}
