#include <bits/stdc++.h>
using namespace std;

#define inf 1000001

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x+1, inf);
    dp[0] = 0;
    for (int i = 1; i < x+1; i++) {
        for (auto c : coins) {
            if (i-c < 0) continue;
            if (dp[i-c] == -1) continue;
            dp[i] = min(dp[i], 1+dp[i-c]);
        }
        if (dp[i] == inf) dp[i] = -1;
    }

    cout << dp[x] << endl;
}