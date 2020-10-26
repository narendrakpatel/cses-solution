#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long int powermod(long long int a, long long int b, long long int modulo) {
    long long int res = 1;
    while (b) {
        if (b&1) res *= a;
        a *= a;
        a %= modulo;
        res %= modulo;
        b >>= 1;
    }
    return res;
}

int main() {
    vector<long long int> fac(2000001, 1);
    vector<long long int> invfac(2000001, 1);
    for (int i = 2; i < 2000001; i++) {
        fac[i] = fac[i-1]*i;
        fac[i] %= mod;
        invfac[i] = invfac[i-1]*powermod(i, mod-2, mod);
        invfac[i] %= mod;
    }

    int n, m; cin >> n >> m;
    long long int res = fac[n+m-1];
    res *= invfac[m]; res %= mod;
    res *= invfac[n-1]; res %= mod;
    cout << res << endl;
}