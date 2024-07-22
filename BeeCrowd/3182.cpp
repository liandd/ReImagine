#include<bits/stdc++.h>
using namespace std;

struct hotel{
    int pr;
    vector<int> disp;
};

bool cmp(hotel a, hotel b){
    return a.pr < b.pr;
}

int main() {
    int n,b,h,w;
    cin>>n>>b>>h>>w; 
    vector<hotel> a(h);
    for(int i=0;i<h;i++){
        cin>>a[i].pr;
        a[i].disp.resize(w);
        for(int j=0;j<w;j++){
            cin>>a[i].disp[j];
        }
    }
    sort(a.begin(), a.end(), cmp);
    for(int i=0;i<h;i++){
        if(a[i].pr*n > b) break;
        for(int j=0;j<w;j++){
            if(a[i].disp[j] >= n){
                cout<<a[i].pr*n<<"\n";
                return 0;
            }
        }
    }
    cout<<"stay home\n";
    return 0;
}
