#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main() {
    int n; cin >> n;
    vector<long long int> dp(n+1);
    dp[0] = 1;
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < 7; j++) {
            if (i-j >= 0) dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }

    cout << dp[n] << endl;
}