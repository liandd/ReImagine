#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    while(scanf("%d%d",&a,&b) != EOF){      
        vector<int> v(b);
        for(int i=0;i<b;i++){
            scanf("%d",&v[i]);
        }
        if(a==b){
            cout<<"*\n";
        }else{
            vector<int> n(a); 
            iota(n.begin(),n.end(),1);
            sort(v.begin(),v.end());
            for(int i=0; i<a; i++){
                if(find(v.begin(),v.end(),n[i])==v.end())
                    printf("%d ",n[i]);
            }
            cout<<"\n";
        }

    }
    return 0;
}
