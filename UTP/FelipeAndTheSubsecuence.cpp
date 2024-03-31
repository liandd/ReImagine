#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n=0,s=0,res=0;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&s);
        res=(s+1)*(s+1)-1;
        printf("%lld\n",res);
    }
return 0;
}
