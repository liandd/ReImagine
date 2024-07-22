#include<bits/stdc++.h>
using namespace std;
#define INF -1
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vii> ady;
vi dist;
int origen,destino,n,e,cont;
int bfs(){
    cont=0;
    dist[origen]=0;
    queue<int> q;
    q.push(origen);
    while(!q.empty()){
        int a=q.front();
        q.pop();
        cont++;
        for(int i=0; i<(int)ady[a].size();i++){
            if(dist[a]!=INF){
                continue;
            }
            dist[i]=dist[a]+1;
            q.push(i);
        }
    }
return cont;
}
int main(){
    while(cin>>n>>e && n && e){
        ady.assign(n,vii(0,ii{0,0}));
        dist.assign(n+1,INF);
        while(e--){
            int a,b,w;
            cin>>a>>b>>w;
            ady[a].push_back(ii{b,w});
            if(b==2)ady[b].push_back(ii{a,w});
        }
        bool ans = true;
        int ss=0;
        ss = bfs();
        if(ss < n){
            ans = false;
            break;
        }
        cout<<ans<<"\n";
    }
return 0;
}
