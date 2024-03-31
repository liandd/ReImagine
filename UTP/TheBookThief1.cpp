#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main(){
    lli s = 0, paginas = 0, gauss = 0, t = 0;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&s);
        if(s > 0){
            paginas = (- 1 + (long long int) sqrt (1 + 8 * s) ) / 2;
            paginas++;
            gauss = (paginas * (paginas + 1)) / 2;
            printf("%lld %lld\n",gauss - s, paginas);
        }
    }
    return 0;
}