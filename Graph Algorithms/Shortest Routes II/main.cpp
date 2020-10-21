#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<long long int>>

int main() {
    int n, m, q; cin >> n >> m >> q;
    graph g(n+1, vector<long long int>(n+1,LONG_LONG_MAX));

    long long int _a, _b, _c;
    for (int i = 0; i < m; i++) {
        cin >> _a >> _b >> _c;
        g[_a][_b] = g[_b][_a] = min(g[_a][_b], _c);
    }

    vector<vector<long long int>> dist(g);
    for (int i = 1; i < n+1; i++) dist[i][i] = 0;

    for (int i = 1; i < n+1; i++)
        for (int j = 1; j < n+1; j++)
            for (int k = 1; k < n+1; k++) {
                if (dist[j][i] == LONG_LONG_MAX || dist[i][k] == LONG_LONG_MAX) continue;
                dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
                dist[k][j] = dist[j][k];
            }

    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        cout << (dist[u][v] == LONG_LONG_MAX ? -1 : dist[u][v]) << endl;
    }
}