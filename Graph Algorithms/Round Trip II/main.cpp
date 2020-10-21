#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<int>>

bool dfs(int u, vector<int> &color, vector<int> &parent, int &cycle_start, const graph &g) {
    color[u] = 1;
    for (auto v : g[u]) {
        if (color[v] == 1) {
            cycle_start = u;
            parent[v] = u;
            return true;
        } else if (color[v] == 0) {
            parent[v] = u;
            if (dfs(v, color, parent, cycle_start, g)) return true;
        }
    }
    color[u] = 2;
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    graph g(n+1, vector<int>());

    int _u, _v;
    for (int i = 0; i < m; i++) {
        cin >> _u >> _v;
        g[_u].push_back(_v);
    }

    vector<int> parent(n+1,-1);
    vector<int> color(n+1);
    int cycle_start = -1;

    for (int i = 1; i < n+1; i++)
        if (!color[i] && dfs(i, color, parent, cycle_start, g)) break;

    if (cycle_start == -1) cout << "IMPOSSIBLE" << endl;
    else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int u = parent[cycle_start]; u != cycle_start; u = parent[u]) cycle.push_back(u);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (auto u : cycle) cout << u << " ";
        cout << endl;
    }
}