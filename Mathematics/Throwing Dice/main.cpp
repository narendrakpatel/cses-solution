#include <bits/stdc++.h>
using namespace std;

#define mat vector<vector<long long int>>
#define mod 1000000007

mat mul(mat a, mat b) {
    mat m(a.size(), vector<long long int>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < a[0].size(); k++) {
                m[i][j] += (a[i][k]*b[k][j])%mod;
                m[i][j] %= mod;
            }
    return m;
}

mat power(mat a, long long int n) {
    mat res(a.size(), vector<long long int>(a.size()));
    for (int i = 0; i < a.size(); i++) res[i][i] = 1;
    while(n) {
        if (n&1) res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

int main() {
    long long int n; cin >> n;
    mat dicemat(6, vector<long long int>(6));
    for (int i = 0; i < 5; i++) dicemat[i][i+1] = 1;
    for (int i = 0; i < 6; i++) dicemat[5][i] = 1;

    mat ans = power(dicemat, n);
    cout << ans[5][5] << endl;
}