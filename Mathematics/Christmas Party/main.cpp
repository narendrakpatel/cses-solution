#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long int powermod(long long int a, long long int b, long long modulo) {
    long long int res = 1;
    while(b) {
        if (b&1) res *= a;
        a *= a;
        res %= modulo;
        a %= modulo;
        b >>= 1;
    }
    return res;
}

long long int inv(long long int a, long long modulo) {
    return powermod(a, modulo-2, modulo);
}

int main() {
    vector<long long int> fac(1000001,1);
    vector<long long int> invfac(1000001,1);
    for (int i = 2; i < 1000001; i++) {
        fac[i] = fac[i-1]*i; fac[i] %= mod;
        invfac[i] = invfac[i-1]*inv(i,mod); invfac[i] %= mod;
    }

    int n; cin >> n;
    long long int res = 0;
    for (int k = 0; k < n+1; k++) {
        long long int partial = fac[n];
        partial *= invfac[k]; partial %= mod;
        res += (k%2 == 0) ? partial : -partial;
        res = (res+mod)%mod;
    }
    cout << res << endl;
}