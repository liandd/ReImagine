#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        double c;
        cin>>c;
        vector<double> vc(c);
        int suma=0;
        for(int i=0; i<c; i++){
            cin>>vc[i];
            suma+=vc[i];
        }
        double prom= suma/c;
        int cont = 0;
        for(int i=0; i<c; i++){
            if(vc[i]>prom)cont++;
        }
        double res = (cont * 100)/c;
        cout<<fixed;
        cout<<setprecision(3)<<res<<"%\n";
    }
	return 0;
}
