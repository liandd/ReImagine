#include <iostream>

using namespace std;

int n;

int Check() {
    if (n==1) return 0;
    
    int sum, count;
    sum = count = 0;
    
    while (1) {
        sum += sum+1;
        if (sum<n) count++;
        else if (sum>=n) break;
    }
    return count;
}

main() {
    while (cin >> n && n!=0) {
        cout << Check() << endl;
    }
}
