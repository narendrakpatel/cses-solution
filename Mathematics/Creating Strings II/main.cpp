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
    vector<long long int> fac(1000001, 1);
    vector<long long int> invfac(1000001, 1);
    for (int i = 2; i < 1000001; i++) {
        fac[i] = fac[i-1]*i;
        fac[i] %= mod;
        invfac[i] = invfac[i-1]*powermod(i, mod-2, mod);
        invfac[i] %= mod;
    }

    string s; cin >> s;
    vector<int> letter(26);
    for (auto c : s) letter[(c-'a')]++;
    long long int res = fac[s.size()];
    for (auto count : letter) {
        res *= invfac[count]; res %= mod;
    }

    cout << res << endl;
}