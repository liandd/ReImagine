#include<bits/stdc++.h>
using namespace std;

int main(){
	string nombre="";
	double a=0,b=0;
	getline(cin,nombre);
	scanf("%lf %lf",&a,&b);
	printf("TOTAL = U$%.2f\n",(b*0.15)+a);

return 0;
}
