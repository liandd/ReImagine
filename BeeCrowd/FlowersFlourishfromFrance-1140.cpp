#include <bits/stdc++.h>
using namespace std;

int main(){
	string w;
	while(getline(cin,w) && w != "*"){
		bool v = 1;
		//cout<<w<<"\n";
		for(int i = 0; i < w.size(); i++){
			char r = tolower(w[0]);
			//cout<<w[i]<<" ";
			if(tolower(w[i]) == ' '){
				//cout<<"\n"<<w[i]<<"\n";
				if(tolower(w[(i+1)%w.size()])!=r){
					v = 0;
				}
			}
		}
		if(v) cout<<"Y\n";
		else cout<<"N\n";
	}
	return 0;
}
