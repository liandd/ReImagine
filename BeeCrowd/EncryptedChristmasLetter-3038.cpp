#include <bits/stdc++.h>
using namespace std;

int main(){
	string w;
	map<char,char> d;
	d['@']='a';
	d['&']='e';
	d['!']='i';
	d['*']='o';
	d['#']='u';
	
	while(getline(cin,w)){
		string r;
		for(int i=0;i<w.size();i++){
			if(w[i]=='@' || w[i]=='&' || w[i]=='!' || w[i]=='*' || w[i]=='#')
				r+=d[w[i]];
			else 
				r+=w[i];
		}
		cout<<r<<"\n";
	}
	return 0;
}
