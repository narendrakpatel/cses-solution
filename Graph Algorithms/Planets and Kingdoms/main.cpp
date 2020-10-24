#include <bits/stdc++.h>
using namespace std;

#define Graph vector<vector<int>>

void dfsutil(int u, vector<bool> &visited, vector<int> &vec, const Graph &g) {
    visited[u] = true;
    for (auto v : g[u]) if (!visited[v]) dfsutil(v, visited, vec, g);
    vec.push_back(u);
}

int main() {
    int n, m; cin >> n >> m;

    Graph g(n+1), rg(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    vector<int> kingdom(n+1);

    vector<bool> visited(n+1);
    vector<int> order;
    for (int i = 1; i < n+1; i++) if (!visited[i]) dfsutil(i, visited, order, g);
    reverse(order.begin(), order.end());

    visited.assign(n+1, false);
    int k = 0; vector<int> component;
    for (auto u : order) {
        if (!visited[u]) {
            k++;
            dfsutil(u, visited, component, rg);
            for (auto v : component) kingdom[v] = k;
            component.clear();
        }
    }

    cout << k << endl;
    for (int i = 1; i < n+1; i++) cout << kingdom[i] << " ";
    cout << endl;
}