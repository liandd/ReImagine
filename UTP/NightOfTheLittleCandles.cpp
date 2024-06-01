#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long v, va=0, t=0, lado=2, aux;
    while(cin>>v){
        va=0;
        t=0;
        lado=2;
        aux=(lado*(lado+1))/2;
        while((va+aux)<=v){
            while((va+aux)<=v){
                t++;
                va+=aux;
                lado++;
                aux=(lado*(lado+1))/2;
            }
            lado=2;
            aux=(lado*(lado+1))/2;
        }


        cout<<t<<" "<<v-va<<"\n";
    }
}
