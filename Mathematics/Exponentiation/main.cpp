#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main() {
    int n; cin >> n;
    while (n--) {
        long long a, b, res = 1; cin >> a >> b;
        while (b) {
            if (b&1) res *= a;
            a *= a;
            res %= mod;
            a %= mod;
            b >>= 1;
        }
        cout << res << endl;
    }
}