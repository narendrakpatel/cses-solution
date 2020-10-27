#include <bits/stdc++.h>
using namespace std;

double power(double x, int k) {
    double ret = 1.0;
    while(k) {
        if(k&1) ret *= x;
        x *= x;
        k >>= 1;
    }
    return ret;
}

int main() {
    double n, k; cin >> n >> k;
    double ans = 0.0;
    for (double i = 1.0; i < k; i++) ans += power(i/k, (int)n);
    ans *= 1e8;
    ans = llround(ans);
    ans /= 1e8;
    cout << fixed << setprecision(6) << k-ans << endl;
}