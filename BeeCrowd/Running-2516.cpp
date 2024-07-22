#include <bits/stdc++.h>
using namespace std;

int main(){
	int s, a, b;
	while(scanf("%d%d%d", &s,&a,&b)!= EOF){
		if(b>=a){
			cout<<"impossivel\n";
		}else{
			double v = a - b;
			double t = s/v;
			cout<<fixed<<setprecision(2)<<t<<"\n";
		}
	}
	return 0;
}
