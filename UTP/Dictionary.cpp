#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n=0, q=0,a=0,b=0;
    cin>>n>>q;
    set<string>dictionary;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        dictionary.insert(str);
    }
    vector<string>s(dictionary.begin(),dictionary.end());
    while(q--){
        string s1="",s2="";
        cin>>s1>>s2;
        a=lower_bound(s.begin(), s.end(), s1)-s.begin();
        b=upper_bound(s.begin(), s.end(), s2)-s.begin();
        cout<<b-a<<"\n";
    }
    return 0;

}
