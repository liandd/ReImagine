#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<string> vs(n);
	for(int i = 0; i<n; i++){
		cin>>vs[i];
	}
	set<string> ss;
	for(int i=0; i<n; i++){
	bool b = 0;
	string aux;
		for(int j=0; j<vs[i].size();j++){
			if(!b){
				if(vs[i][j] == '+'){
					while(vs[i][j]!='@') j++;
				}
				if(vs[i][j] == '@'){
					b = 1;
				}
				if(vs[i][j]!='.'){
					aux+=vs[i][j];
				}
			}else{
				aux+=vs[i][j];
			}

		}
		ss.insert(aux);
	}
	cout<<ss.size()<<"\n";
	return 0;
}
