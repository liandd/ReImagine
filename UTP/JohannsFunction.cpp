#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli johannsFuntion(lli n){
    lli g = 0;
    g = (n * (n + 1) * (n + 2)) / 6;
    return g;
}

int main(){
    lli t = 0, n = 0;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", johannsFuntion(n));
    }
    return 0;
}
