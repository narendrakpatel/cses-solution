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
    int n, m, k; cin >> n >> m >> k;
    mat adj(n+1, vector<long long int>(n+1));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a][b]++;
    }
    mat ans = power(adj, k);
    cout << ans[1][n] << endl;
}