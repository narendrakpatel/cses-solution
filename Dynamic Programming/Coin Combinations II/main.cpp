#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1));
    dp[0][0] = 1;
    for (int i = 1; i < n+1; i++) {
        for (int j = 0; j < x+1; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-coins[i-1] < 0) continue;
            (dp[i][j] += dp[i][j-coins[i-1]]) %= mod;
        }
    }

    cout << dp[n][x] << endl;
}
