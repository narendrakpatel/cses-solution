#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<int>>

bool dfs(int u, vector<int> &color, vector<int> &order, const graph &g) {
    color[u] = 1;
    for (auto v : g[u]) {
        if (color[v] == 1) return true;
        else if (color[v] == 0 && dfs(v, color, order, g)) return true;
    }
    color[u] = 2;
    order.push_back(u);
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    graph g(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    vector<int> order;
    vector<int> color(n+1);
    for (int i = 1; i < n+1; i++)
        if (!color[i]) dfs(i, color, order, g);

    reverse(order.begin(), order.end());
    vector<int> dist(n+1, 1000000);
    vector<int> parent(n+1);
    dist[1] = 0;
    for (auto u : order) {
        if (dist[u] == 1000000) continue;
        for (auto v : g[u]) {
            if (dist[v] < dist[u]+1 || dist[v] == 1000000) {
                dist[v] = dist[u]+1;
                parent[v] = u;
            }
        }
    }
    if (dist[n] == 1000000) cout << "IMPOSSIBLE" << endl;
    else {
        vector<int> path;
        for (int u = n; u != 0; u = parent[u]) path.push_back(u);
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (auto u : path) cout << u << " ";
        cout << endl;
    }
}