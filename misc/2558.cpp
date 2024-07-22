#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<char, int> > c(200);
    int ans;
    string str;

    while (cin >> str){ 
        for (int i = 0; i < 200; ++i){
            c[i].first = i;
            c[i].second = 0;
        }
        for (char ch : str)
            c[ch].second++;

        ans = 0;
        for (const auto& p : c)
            if (p.second & 1)
                ++ans;
        cout << (ans <= 1 ? 0 : ans - 1) << "\n";
    }
    return 0;
}
