#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli n;
    cin>>n;
    while(n--){
        lli x, tmp = 1;
        cin>>x;
        for(lli i = 2; i <= x >> 1; i++){
            if(x % i == 0)
                tmp += i;
        }
        if(tmp < x){
            cout<<"deficient"<<endl;
        }else if (tmp == x){
            cout<<"perfect"<<endl;
        }else{
            cout<<"abundant"<<endl;
        }
    }
    return 0;
}
