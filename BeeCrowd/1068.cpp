#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
    string cadena = "";
    stack<char> parentesis;
    
    while(cin>>cadena){
        for(int i = 0; i < cadena.size(); i++) {
            if(cadena[i] == '('){
            	parentesis.push(cadena[i]);
			} 
            if(cadena[i] == ')') {
                if(parentesis.size() > 0){
                	parentesis.pop();
				}else{
					parentesis.push(cadena[i]);
				}
            }
        }
        
        if(parentesis.size() == 0){
        	cout<<"correct"<<endl;
		}else{
			cout<<"incorrect"<<endl;
		}
		
        while(!parentesis.empty()){
        	parentesis.pop();
		}
            
    }
    
    return 0;
}
