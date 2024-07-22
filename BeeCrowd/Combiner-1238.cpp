#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string wa,wb;
    
    cin>>t;
    while(t--){
        cin>>wa>>wb;
        string nw="";
        int tam = wa.size() + wb.size();
        string maxsize = (wa.size() > wb.size()) ? wa : wb;
        string minsize = (wa.size() < wb.size()) ? wa : wb;
        for(int i = 0; i<maxsize.size(); i++){
            if(i < minsize.size()){
                nw+=wa[i];
                nw+=wb[i];
            }
            else{
               nw+=maxsize[i];
            }
        }
        cout<<nw<<"\n";
    }
    return 0;
}
