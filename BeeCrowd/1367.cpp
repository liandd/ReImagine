#include <bits/stdc++.h>
using namespace std;

struct submission{
	char a;
	int time;
	pair<string,bool> prstate;
};

int main(){
	int t;
	while(cin>>t && t){
		vector<submission> submissions(t);
		int s=0,p=0;
		for(int i = 0; i<t; i++){
			cin>> submissions[i].a >> submissions[i].time >> submissions[i].prstate.first;
			if(submissions[i].prstate.first == "correct"){
				s++;
				submissions[i].prstate.second = 0;
			}else submissions[i].prstate.second = 1;
		}

		for(int i = 0; i < t; i++){
			if(submissions[i].prstate.first == "correct") p+=submissions[i].time;
			for(int j = i+1; j < t; j++){
				if(submissions[j].a == submissions[i].a && 
						(submissions[i].prstate.second == 1 && submissions[j].prstate.first == "correct")){
					p+=20;
				}
			}
		}
		cout<<s<<" "<<p<<"\n";
	}
	return 0;
}
