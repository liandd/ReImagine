#include<bits/stdc++.h>
using namespace std;

int main(){

	ios::sync_with_stdio(0);cin.tie(0);
	int m1,h1,m2,h2;
	while(cin>>h1>>m1>>h2>>m2){
		if(h1==0&&h2==0&&m1==0&&m2==0) break;
		int r;
		if(h2<h1||(h2==h1&&m2<m1)) r=(24+h2-h1)*60+(m2-m1);
		else r = (h2-h1)*60+(m2-m1);
		cout<<r<<"\n";
	}
	return 0;
}
