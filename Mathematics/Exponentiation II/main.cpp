#include <bits/stdc++.h>
using namespace std;

#define mod1 1000000007
#define mod2 1000000006

long long int powermod(long long int a, long long int b, long long int mod) {
    long long int res = 1;
    while (b) {
        if (b&1) res *= a;
        a *= a;
        a %= mod;
        res %= mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int n; cin >> n;

    while(n--) {
        long long int a, b, c; cin >> a >> b >> c;
        long long int power = powermod(b, c, mod2);
        cout << powermod(a, power, mod1) << endl;
    }
}