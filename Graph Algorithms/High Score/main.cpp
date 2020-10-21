#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<bool> &visited, const vector<bool> &flag, vector<vector<int>> g) {
    if (flag[u]) return true;
    visited[u] = true;
    for (int v : g[u]) {
        if (visited[v]) continue;
        if (dfs(v, visited, flag, g)) return true;
    }
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    vector<vector<int>> rg(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges[i] = {a, b, -w};
        rg[b].push_back(a);
    }

    vector<bool> flag(n+1);
    vector<long long int> dist(n+1, LONG_LONG_MAX);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            if (dist[a] == LONG_LONG_MAX) continue;
            long long int tmp = dist[b];
            dist[b] = min(dist[b], dist[a] + w);
            flag[b] = flag[b] || ((i == n-1) && (tmp != dist[b]));
        }
    }

    vector<bool> visited(n+1);
    if (dfs(n, visited, flag, rg)) cout << -1 << endl;
    else cout << -dist[n] << endl;
}