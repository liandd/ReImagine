#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vi vector<int>
lli _sieve_size;
vi primos;
bitset<10000010> bs;

void sieve(lli upperbound){
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(lli i = 2; i <= _sieve_size; i++){
        if(bs[i]){
            for(lli j = i * i; j <= _sieve_size; j += i){
                bs[j] = 0;
            }
            primos.push_back((int)i);
        }
    }
}

lli sumDiv(lli N){
    lli PF_idx = 0, PF = primos[PF_idx], ans = 1, CopyN = N;
    while(PF * PF <= N){
        lli potencia = 0;
        while(N % PF == 0){
            N /= PF;
            potencia++;
        }
        ans *= ((lli)pow((double)PF, potencia + 1.0) - 1) / (PF - 1);
        PF = primos[++PF_idx];
    }
    
    if(N != 1) ans *= ((lli)pow((double)N, 2.0) - 1) / (N - 1);
    
    return ans - CopyN;
}

int main() {
    int t = 0;
    scanf("%d", &t);
    sieve(10000000);
    while(t--){
        lli n = 0, res = 0;
        scanf("%lld", &n);
        res = sumDiv(n);
        if(res < n) printf("deficient\n");
        if(res == n) printf("perfect\n");
        if(res > n) printf("abundant\n");
    }
    return 0;
}
