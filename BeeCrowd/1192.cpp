#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		char c[4];
		int a,b;
		cin>>c;
		a=c[0]-'0';
		b=c[2]-'0';
		if(a==b) cout<<a*b<<"\n";
		else if(c[1]>='A'&&c[1]<='Z') cout<<b-a<<"\n";
		else if(c[1]>='a'&&c[1]<='z') cout<<a+b<<"\n";
	}
	return 0;
}
