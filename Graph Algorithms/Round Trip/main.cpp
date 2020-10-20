#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<int>>

bool dfs(int u, vector<bool> &visited, vector<int> &parent, int &cycle_start, const graph &g) {
    visited[u] = true;
    for (auto v : g[u]) {
        if (v == parent[u]) continue;
        if (visited[v]) {
            cycle_start = u;
            parent[v] = u;
            return true;
        } else {
            parent[v] = u;
            if (dfs(v, visited, parent, cycle_start, g)) return true;
        }
    }
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    graph g(n+1, vector<int>());

    int _u, _v;
    for (int i = 0; i < m; i++) {
        cin >> _u >> _v;
        g[_u].push_back(_v);
        g[_v].push_back(_u);
    }

    vector<int> parent(n+1,-1);
    vector<bool> visited(n+1);
    int cycle_start = -1;

    for (int i = 1; i < n+1; i++)
        if (!visited[i] && dfs(i, visited, parent, cycle_start, g)) break;

    if (cycle_start == -1) cout << "IMPOSSIBLE" << endl;
    else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int u = parent[cycle_start]; u != cycle_start; u = parent[u]) cycle.push_back(u);
        cycle.push_back(cycle_start);
        cout << cycle.size() << endl;
        for (auto u : cycle) cout << u << " ";
        cout << endl;
    }
}