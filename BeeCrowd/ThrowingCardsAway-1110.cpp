#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
	int n=0;
	while(cin>>n && n){
		vi deck(n);
		vi r;
		int cont;
		iota(deck.begin(),deck.end(),1);
		cout<<"Discarded cards: ";
		while(deck.size()!=1){
			int aux;
			for(int i=0;i<deck.size();i++){
				aux=deck[1];
				if(deck.size()!=2)
					cout<<deck[0]<<", ";
				else
					cout<<deck[0];
				deck.erase(deck.begin(), deck.begin()+2);
				deck.push_back(aux);
			}
		}
		cout<<"\nRemaining card: "<<deck[0]<<"\n";
	}
	return 0;
}
