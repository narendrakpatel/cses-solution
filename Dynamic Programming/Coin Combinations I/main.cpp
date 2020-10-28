#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<long long int> dp(x+1);
    dp[0] = 1;
    for (int i = 1; i < x+1; i++) {
        for (auto c : coins) {
            if (i-c < 0) continue;
            dp[i] += dp[i-c];
            dp[i] %= mod;
        }
    }

    cout << dp[x] << endl;
}