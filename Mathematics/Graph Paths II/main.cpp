#include <bits/stdc++.h>
using namespace std;

#define mat vector<vector<long long int>>
#define inf (long long int) 1e18+1

mat op(const mat &a, const mat &b) {
    mat m(a.size(), vector<long long int>(b[0].size(),inf));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < a[0].size(); k++) {
                m[i][j] = min(m[i][j], a[i][k]+b[k][j]);
            }
    return m;
}

mat power(mat a, long long int n) {
    mat res(a);
    for (auto row : res) for (auto u : row) if (u != inf) u = 0;
    while(n) {
        if (n&1) res = op(res, a);
        a = op(a, a);
        n >>= 1;
    }
    return res;
}

int main() {
    int n, m, k; cin >> n >> m >> k;
    mat adj(n+1, vector<long long int>(n+1,inf));
    for (int i = 0; i < m; i++) {
        int a, b; long long int c; cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }
    auto ans = power(adj, k-1)[1][n];
    cout << (ans == inf ? -1 : ans) << endl;
}
