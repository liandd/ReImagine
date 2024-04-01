#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long int n = 0, g = 0, res = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n && n!=0){
        g = (-1 + sqrt(1 + 8 * static_cast<double>(n))) / 2;
        res = g + 1;
        ((g & 1)==0) ? g >>= 1 : g;
        ((res & 1)==0) ? res >>= 1 : res;
        ((g * res == n)) ? cout << "YES\n" : cout << "NO\n";
    }

return 0;
}
