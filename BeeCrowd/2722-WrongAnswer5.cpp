#include<bits/stdc++.h>
using namespace std;

int main(){

int n=0;
cin>>n;
cin.ignore();
while(n--){
    string str1="",str2="";
    getline(cin,str1);
    getline(cin,str2);
    string nombre="";
    int cont=0,cont2=0;
    while (cont < str1.size() && cont2 < str2.size()) {
        nombre += str1[cont++];
        if (cont % 2 == 0) {
            nombre += str2[cont2++];
            nombre += str2[cont2++];
        }
    }
    cout<<nombre<<"\n";
}
return 0;
}
