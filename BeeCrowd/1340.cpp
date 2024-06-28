#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 0;
    while(cin>>n){
        bool queueF = true, pila = true, pqF = true;
        priority_queue<int> pq;
        queue<int> cola;
        stack<int> pilaa;
        int ans = 0, tmp = 0;
        for(int i = 0; i < n ; i++){
            cin >> ans >> tmp;
            if(ans == 1){
                cola.push(tmp);
                pilaa.push(tmp);
                pq.push(tmp);
            }
            if(ans == 2){
                if(pilaa.top() != tmp){
                    pila = false;
                } else {
                    pilaa.pop();
                }
                if(cola.front() != tmp){
                    queueF = false;
                } else{
                    cola.pop();
                }
                if(pq.top() != tmp){
                    pqF = false;
                } else {
                    pq.pop();
                }
            }
        }
        if (!pila && !queueF && !pqF){
            cout << "impossible\n";
        } else if (pila && pqF){
            cout << "not sure\n";
        } else if (pila && queueF){
            cout << "not sure\n";
        } else if (pqF && queueF){
            cout << "not sure\n";
        } else if (pqF){
            cout << "priority queue\n";
        } else if (queueF){
            cout << "queue\n";
        } else if (pila){
            cout << "stack\n";
        }
    }
    return 0;
}
