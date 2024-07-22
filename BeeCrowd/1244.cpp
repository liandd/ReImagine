#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
	return a.size()>b.size();
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
    	string s;
    	vector<string> vs;
    	getline(cin,s);
    	s+=" ";
    	int cont=0;
    	for(int i=0;i<s.size();++i){
    		string aux="";
    		if(s[i]==32){
    			aux=s.substr(cont,i-cont);
    			vs.push_back(aux);
    			cont=i+1;
			}
    		
		}
		stable_sort(vs.begin(),vs.end(),cmp);
		for (int i = 0; i < vs.size(); i++) {
		    cout << vs[i];
		    if (i != vs.size() - 1) {
		        cout << " ";
		    }
		}

		cout<<"\n";
	}
    return 0;
}
