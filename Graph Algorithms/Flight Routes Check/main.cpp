#include <bits/stdc++.h>
using namespace std;

#define Graph vector<vector<int>>

void dfs(int u, vector<bool> &visited, const Graph &g) {
    visited[u] = true;
    for (auto v : g[u]) if (!visited[v]) dfs(v, visited, g);
}


int main() {
    int n, m; cin >> n >> m;
    Graph g(n+1);
    Graph rg(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    vector<bool> visited(n+1);
    dfs(1, visited, g);
    for (int i = 2; i < n+1; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }

    visited.assign(n+1, false);
    dfs(1, visited, rg);
    for (int i = 2; i < n+1; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}